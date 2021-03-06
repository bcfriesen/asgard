cmake_minimum_required (VERSION 3.13)
project (asgard
  VERSION 0.1.0
  LANGUAGES CXX
)

###############################################################################
## Set up the compiler and general global build options
###############################################################################
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options ("-g" "-Wall" "-Wextra" "-Wpedantic")
message (STATUS "CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")

# set up possible commandline input variable defaults (override with -D)
option (ASGARD_BUILD_TESTS "Build tests for asgard" ON)
option (ASGARD_BUILD_OPENBLAS "Download and build our own OpenBLAS" OFF)
option (ASGARD_BUILD_HDF5 "Download and build our own HDF5/HighFive" OFF)
option (ASGARD_HDF5_PATH "optional location of lib/ containing HDF5" "")
option (ASGARD_BUILD_PROFILE_DEPS "Download and build our own tools (e.g.  graphviz)" OFF)
option (ASGARD_LAPACK_PATH "optional location of include/ and lib/ containing LAPACK" "")
option (ASGARD_BLAS_PATH "optional location of include/ and lib/ containing BLAS" "")
option (ASGARD_PROFILE_GPROF "enable profiling support for using gprof" "")
option (ASGARD_PROFILE_XRAY "enable profiling support for using LLVM XRAY" "")
option (ASGARD_PROFILE_GPERF_CPU "enable cpu profiling support using gperftools" "")
option (ASGARD_PROFILE_GPERF_MEM "enable memory profiling support using gperftools" "")
option (ASGARD_PROFILE_PERF "enable profiling support for using linux perf" "")
option (ASGARD_PROFILE_VALGRIND "enable profiling support for using valgrind" "")
option (ASGARD_GRAPHVIZ_PATH "optional location of bin/ containing dot executable" "")
option (ASGARD_IO_HIGHFIVE "Use the HighFive HDF5 header library for I/O" OFF)
option (ASGARD_USE_CUDA "Optional CUDA support for asgard" OFF)
option (ASGARD_USE_OPENMP "Optional openMP support for asgard" ON)
option (ASGARD_USE_MPI "Optional distributed computing support for asgard" OFF)
set (ASGARD_TESTING_RANKS "0" CACHE STRING "Override default number of ranks to use for testing")

if (NOT ASGARD_BLAS_PATH AND ASGARD_LAPACK_PATH)
  set (ASGARD_BLAS_PATH ${ASGARD_LAPACK_PATH})
endif()
if (NOT ASGARD_LAPACK_PATH AND ASGARD_BLAS_PATH)
  set (ASGARD_LAPACK_PATH ${ASGARD_BLAS_PATH})
endif()

###############################################################################
## Pull in external support as needed
###############################################################################
# sets OpenBLAS_PATH and LINALG_LIBS
include (${CMAKE_SOURCE_DIR}/contrib/contrib.cmake)
# sets PROFILE_DEPS and PROFILE_LIBS
include (${CMAKE_SOURCE_DIR}/profiling/profiling.cmake)
# sets HighFive_FOUND
include (${CMAKE_SOURCE_DIR}/contrib/io.cmake)

string(FIND "${BLAS_LIBRARIES}" "mkl" FOUND_MKL)
set(ASGARD_USE_MKL FALSE)
if(FOUND_MKL GREATER_EQUAL 0)
  set(ASGARD_USE_MKL TRUE)
endif()

if(ASGARD_USE_OPENMP)
  find_package(OpenMP REQUIRED)
  add_compile_options ("-fopenmp")
endif()

if(ASGARD_USE_CUDA)
  find_package(CUDA 9.0 REQUIRED)
  include_directories(${CUDA_INCLUDE_DIRS})
endif()

if(ASGARD_USE_MPI)
  find_package(MPI REQUIRED)
  include_directories(${MPI_CXX_INCLUDE_DIRS})
endif()

###############################################################################
## Building asgard
#
# KEEP EVERYTHING LISTED IN ALPHABETICAL ORDER
#
# to add a component:
# 1) define the component in the components list
# 2) define any link dependencies if needed
###############################################################################

# define the components and how to build and link the components together
set (components
  basis
  batch
  coefficients
  connectivity
  distribution
  element_table
  fast_math
  chunk
  lib_dispatch
  matlab_utilities
  pde
  permutations
  program_options
  quadrature
  tensors
  time_advance
  transformations
)
if (ASGARD_IO_HIGHFIVE)
  list (APPEND components io)
endif ()

foreach (component IN LISTS components)
  add_library (${component} src/${component}.cpp)
  target_include_directories (${component} PRIVATE ${CMAKE_BINARY_DIR})
endforeach ()

if (build_hdf5)
  add_dependencies (io hdf5-ext)
endif ()

if (build_OpenBLAS)
  add_dependencies (tensors openblas-ext)
endif ()

target_link_libraries (basis PRIVATE matlab_utilities quadrature tensors)

target_link_libraries (batch PRIVATE lib_dispatch coefficients connectivity chunk element_table pde tensors)

if (ASGARD_USE_OPENMP AND NOT ASGARD_USE_MKL)
   target_link_libraries(batch PRIVATE OpenMP::OpenMP_CXX)
endif ()

target_link_libraries (coefficients
  PRIVATE pde matlab_utilities quadrature tensors transformations)

target_link_libraries (connectivity
  PRIVATE element_table matlab_utilities permutations tensors)

target_link_libraries(chunk PRIVATE distribution element_table fast_math pde)

target_link_libraries(distribution PRIVATE element_table lib_dispatch)
if (ASGARD_USE_MPI)
  target_link_libraries(distribution PRIVATE MPI::MPI_CXX)
endif ()

target_link_libraries (element_table
  PRIVATE permutations program_options tensors)

target_link_libraries (fast_math
  PRIVATE lib_dispatch tensors)

if (ASGARD_IO_HIGHFIVE)
  target_link_libraries (io PUBLIC highfive tensors PRIVATE hdf5)
endif ()

target_link_libraries (lib_dispatch PRIVATE ${LINALG_LIBS})
if (ASGARD_USE_CUDA)
  target_link_libraries(lib_dispatch PRIVATE ${CUDA_LIBRARIES}
					     ${CUDA_CUBLAS_LIBRARIES})
endif()

target_link_libraries (matlab_utilities PUBLIC tensors)

target_link_libraries (pde PRIVATE basis matlab_utilities tensors)

target_link_libraries (permutations PRIVATE matlab_utilities tensors)

target_link_libraries (program_options PRIVATE clara distribution)

target_link_libraries (quadrature PRIVATE matlab_utilities tensors)

target_link_libraries (tensors PRIVATE lib_dispatch)
if (ASGARD_USE_CUDA)
  target_link_libraries (tensors PRIVATE ${CUDA_LIBRARIES})
endif ()

target_link_libraries (time_advance PRIVATE batch fast_math pde tensors INTERFACE element_table)

target_link_libraries (transformations
  PRIVATE connectivity distribution matlab_utilities pde program_options
  quadrature tensors)

# define the main application and its linking
add_executable (asgard src/main.cpp)

# link in components needed directly by main
set (main_app_link_deps
  batch
  coefficients
  connectivity
  distribution
  element_table
  matlab_utilities
  pde
  program_options
  quadrature
  tensors
  time_advance
  transformations
)
if (ASGARD_IO_HIGHFIVE)
  list (APPEND main_app_link_deps io)
endif()

if (ASGARD_USE_MPI)
  list (APPEND main_app_link_deps PRIVATE MPI::MPI_CXX)
endif()

foreach (link_dep IN LISTS main_app_link_deps)
  target_link_libraries (asgard PRIVATE ${link_dep})
endforeach ()

# build/link anything needed for profiling if requested
if (PROFILE_DEPS)
  add_dependencies (asgard ${PROFILE_DEPS})
endif ()
target_link_libraries (asgard PRIVATE ${PROFILE_LIBS})

# Generate header file from src/build_info.hpp.in
configure_file(
  src/build_info.hpp.in
  ${CMAKE_BINARY_DIR}/build_info.hpp
)
# Include the generated build_info.hpp
target_include_directories (asgard PRIVATE ${CMAKE_BINARY_DIR})


###############################################################################
## Testing asgard
#
###############################################################################
if (ASGARD_BUILD_TESTS)
  enable_testing ()

  # Define ctest tests and their executables
  add_library (tests_general testing/tests_general.cpp)
  target_link_libraries (tests_general PUBLIC Catch PRIVATE pde program_options)
  target_include_directories(tests_general PRIVATE ${CMAKE_BINARY_DIR})
  foreach (component IN LISTS components)
    add_executable (${component}-tests src/${component}_tests.cpp)
    target_include_directories (${component}-tests PRIVATE ${CMAKE_SOURCE_DIR}/testing)
    target_include_directories (${component}-tests PRIVATE ${CMAKE_BINARY_DIR})
    target_link_libraries (${component}-tests PRIVATE ${component} tests_general)
    # FIXME
    if (ASGARD_IO_HIGHFIVE AND "${component}" STREQUAL "io")
      target_link_libraries (io-tests PRIVATE highfive hdf5 tensors)
    endif ()

    if (ASGARD_USE_MPI)
      target_link_libraries (${component}-tests PRIVATE ${component} MPI::MPI_CXX)
      if ("${component}" STREQUAL "distribution" OR
          "${component}" STREQUAL "time_advance")

      set(test_ranks "4")
      if (ASGARD_USE_CUDA)
         set(test_ranks "1")
      endif ()
      if (${ASGARD_TESTING_RANKS})
         set(test_ranks ${ASGARD_TESTING_RANKS})
      endif ()
      add_test (NAME ${component}-test-mpi
                COMMAND mpirun -n ${test_ranks} ${component}-tests
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} )
      endif()
    endif ()







    add_test (NAME ${component}-test
              COMMAND ${component}-tests
              WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} )
  endforeach ()




else ()
  message (WARNING "warning: tests will not be built.")
endif ()
