#include "coefficients.hpp"
#include "matlab_utilities.hpp"
#include "pde.hpp"
#include "tensors.hpp"
#include "tests_general.hpp"

TEMPLATE_TEST_CASE("continuity 1 (single term)", "[coefficients]", double,
                   float)
{
  auto continuity1 = make_PDE<TestType>(PDE_opts::continuity_1);
  std::string const filename =
      "../testing/generated-inputs/coefficients/continuity1_coefficients.dat";
  fk::matrix<TestType> const gold =
      fk::matrix<TestType>(read_matrix_from_txt_file(filename));

  generate_all_coefficients(*continuity1);

  fk::matrix<TestType> const test =
      continuity1->get_coefficients(0, 0).clone_onto_host();

  // determined empirically 11/19
  auto const tol_scale = 1e2;
  relaxed_comparison(gold, test, tol_scale);
}

TEMPLATE_TEST_CASE("continuity 2 terms", "[coefficients]", double, float)
{
  int const level     = 4;
  int const degree    = 3;
  TestType const time = 1.0;

  auto pde = make_PDE<TestType>(PDE_opts::continuity_2, level, degree);
  std::string const filename_base =
      "../testing/generated-inputs/coefficients/continuity2_coefficients_l" +
      std::to_string(level) + "_d" + std::to_string(degree) + "_";

  generate_all_coefficients(*pde, time);

  for (int t = 0; t < pde->num_terms; ++t)
  {
    for (int d = 0; d < pde->num_dims; ++d)
    {
      std::string const filename = filename_base + std::to_string(t + 1) + "_" +
                                   std::to_string(d + 1) + ".dat";

      fk::matrix<TestType> const gold =
          fk::matrix<TestType>(read_matrix_from_txt_file(filename));
      fk::matrix<TestType> const &test =
          pde->get_coefficients(t, d).clone_onto_host();

      // determined empirically 11/19
      auto const tol_scale = 1e2;
      relaxed_comparison(gold, test, tol_scale);
    }
  }
}

TEMPLATE_TEST_CASE("continuity 3 terms - norotate", "[coefficients]", double,
                   float)
{
  int const level     = 4;
  int const degree    = 4;
  TestType const time = 1.0;
  auto pde = make_PDE<TestType>(PDE_opts::continuity_3, level, degree);
  std::string const filename_base = "../testing/generated-inputs/coefficients/"
                                    "continuity3_coefficients_norotate_l" +
                                    std::to_string(level) + "_d" +
                                    std::to_string(degree) + "_";

  generate_all_coefficients(*pde, time, false);

  for (int t = 0; t < pde->num_terms; ++t)
  {
    for (int d = 0; d < pde->num_dims; ++d)
    {
      std::string const filename = filename_base + std::to_string(t + 1) + "_" +
                                   std::to_string(d + 1) + ".dat";

      fk::matrix<TestType> const gold =
          fk::matrix<TestType>(read_matrix_from_txt_file(filename));
      fk::matrix<TestType> const &test =
          pde->get_coefficients(t, d).clone_onto_host();

      // determined empirically 11/19
      auto const tol_scale = 1e2;
      relaxed_comparison(gold, test, tol_scale);
    }
  }
}

TEMPLATE_TEST_CASE("continuity 3 terms", "[coefficients]", double, float)
{
  int const level     = 4;
  int const degree    = 4;
  TestType const time = 1.0;
  auto pde = make_PDE<TestType>(PDE_opts::continuity_3, level, degree);
  std::string const filename_base =
      "../testing/generated-inputs/coefficients/continuity3_coefficients_l" +
      std::to_string(level) + "_d" + std::to_string(degree) + "_";

  generate_all_coefficients(*pde, time);

  for (int t = 0; t < pde->num_terms; ++t)
  {
    for (int d = 0; d < pde->num_dims; ++d)
    {
      std::string const filename = filename_base + std::to_string(t + 1) + "_" +
                                   std::to_string(d + 1) + ".dat";

      fk::matrix<TestType> const gold =
          fk::matrix<TestType>(read_matrix_from_txt_file(filename));
      fk::matrix<TestType> const &test =
          pde->get_coefficients(t, d).clone_onto_host();

      // determined empirically 11/19
      auto const tol_scale = 1e3;
      relaxed_comparison(gold, test, tol_scale);
    }
  }
}

TEMPLATE_TEST_CASE("continuity 6 terms", "[coefficients]", double, float)
{
  int const level     = 2;
  int const degree    = 4;
  TestType const time = 1.0;
  auto pde = make_PDE<TestType>(PDE_opts::continuity_6, level, degree);
  std::string const filename_base =
      "../testing/generated-inputs/coefficients/continuity6_coefficients_l" +
      std::to_string(level) + "_d" + std::to_string(degree) + "_";

  generate_all_coefficients(*pde, time);

  for (int t = 0; t < pde->num_terms; ++t)
  {
    for (int d = 0; d < pde->num_dims; ++d)
    {
      std::string const filename = filename_base + std::to_string(t + 1) + "_" +
                                   std::to_string(d + 1) + ".dat";

      fk::matrix<TestType> const gold =
          fk::matrix<TestType>(read_matrix_from_txt_file(filename));
      fk::matrix<TestType> const &test =
          pde->get_coefficients(t, d).clone_onto_host();

      // determined empirically 11/19
      auto const tol_scale = 1e3;
      relaxed_comparison(gold, test, tol_scale);
    }
  }
}

TEMPLATE_TEST_CASE("fokkerplanck1_4p2 terms", "[coefficients]", double, float)
{
  int const level     = 3;
  int const degree    = 4;
  TestType const time = 1.0;
  auto pde = make_PDE<TestType>(PDE_opts::fokkerplanck_1d_4p2, level, degree);
  std::string const filename_base = "../testing/generated-inputs/coefficients/"
                                    "fokkerplanck1_4p2_coefficients_l" +
                                    std::to_string(level) + "_d" +
                                    std::to_string(degree) + "_";
  generate_all_coefficients(*pde, time);

  for (int t = 0; t < pde->num_terms; ++t)
  {
    for (int d = 0; d < pde->num_dims; ++d)
    {
      std::string const filename = filename_base + std::to_string(t + 1) + "_" +
                                   std::to_string(d + 1) + ".dat";
      fk::matrix<TestType> const gold =
          fk::matrix<TestType>(read_matrix_from_txt_file(filename));
      fk::matrix<TestType> const &test =
          pde->get_coefficients(t, d).clone_onto_host();

      // determined empirically 11/19
      // FIXME seems loose
      auto const tol_scale = 1e5;
      relaxed_comparison(gold, test, tol_scale);
    }
  }
}

TEMPLATE_TEST_CASE("fokkerplanck1_4p2 terms - norotate", "[coefficients]",
                   double, float)
{
  int const level     = 3;
  int const degree    = 4;
  TestType const time = 1.0;
  auto pde = make_PDE<TestType>(PDE_opts::fokkerplanck_1d_4p2, level, degree);
  std::string const filename_base =
      "../testing/generated-inputs/coefficients/"
      "fokkerplanck1_4p2_coefficients_norotate_l" +
      std::to_string(level) + "_d" + std::to_string(degree) + "_";

  generate_all_coefficients(*pde, time, false);

  for (int t = 0; t < pde->num_terms; ++t)
  {
    for (int d = 0; d < pde->num_dims; ++d)
    {
      std::string const filename = filename_base + std::to_string(t + 1) + "_" +
                                   std::to_string(d + 1) + ".dat";

      fk::matrix<TestType> const gold =
          fk::matrix<TestType>(read_matrix_from_txt_file(filename));
      fk::matrix<TestType> const &test =
          pde->get_coefficients(t, d).clone_onto_host();

      // determined empirically 11/19
      auto const tol_scale = 1e2;
      relaxed_comparison(gold, test, tol_scale);
    }
  }
}

TEMPLATE_TEST_CASE("fokkerplanck1_4p3 terms", "[coefficients]", double, float)
{
  int const level     = 4;
  int const degree    = 3;
  TestType const time = 1.0;
  auto pde = make_PDE<TestType>(PDE_opts::fokkerplanck_1d_4p3, level, degree);
  std::string const filename_base = "../testing/generated-inputs/coefficients/"
                                    "fokkerplanck1_4p3_coefficients_l" +
                                    std::to_string(level) + "_d" +
                                    std::to_string(degree) + "_";

  generate_all_coefficients(*pde, time, false);

  for (int t = 0; t < pde->num_terms; ++t)
  {
    for (int d = 0; d < pde->num_dims; ++d)
    {
      std::string const filename = filename_base + std::to_string(t + 1) + "_" +
                                   std::to_string(d + 1) + ".dat";

      fk::matrix<TestType> const gold =
          fk::matrix<TestType>(read_matrix_from_txt_file(filename));
      fk::matrix<TestType> const &test =
          pde->get_coefficients(t, d).clone_onto_host();
      // determined empirically 11/19
      auto const tol_scale = 1e2;
      relaxed_comparison(gold, test, tol_scale);
    }
  }
}

TEMPLATE_TEST_CASE("fokkerplanck1_4p4 terms", "[coefficients]", double, float)
{
  int const level     = 3;
  int const degree    = 4;
  TestType const time = 1.0;
  auto pde = make_PDE<TestType>(PDE_opts::fokkerplanck_1d_4p4, level, degree);
  std::string const filename_base = "../testing/generated-inputs/coefficients/"
                                    "fokkerplanck1_4p4_coefficients_l" +
                                    std::to_string(level) + "_d" +
                                    std::to_string(degree) + "_";

  generate_all_coefficients(*pde, time, false);

  for (int t = 0; t < pde->num_terms; ++t)
  {
    for (int d = 0; d < pde->num_dims; ++d)
    {
      std::string const filename = filename_base + std::to_string(t + 1) + "_" +
                                   std::to_string(d + 1) + ".dat";
      fk::matrix<TestType> const gold =
          fk::matrix<TestType>(read_matrix_from_txt_file(filename));
      fk::matrix<TestType> const &test =
          pde->get_coefficients(t, d).clone_onto_host();

      // determined empirically 11/19
      auto const tol_scale = 1e2;
      relaxed_comparison(gold, test, tol_scale);
    }
  }
}

TEMPLATE_TEST_CASE("fokkerplanck1_4p5 terms", "[coefficients]", double, float)
{
  int const level     = 5;
  int const degree    = 2;
  TestType const time = 1.0;
  auto pde = make_PDE<TestType>(PDE_opts::fokkerplanck_1d_4p5, level, degree);
  std::string const filename_base = "../testing/generated-inputs/coefficients/"
                                    "fokkerplanck1_4p5_coefficients_l" +
                                    std::to_string(level) + "_d" +
                                    std::to_string(degree) + "_";

  generate_all_coefficients(*pde, time, false);

  for (int t = 0; t < pde->num_terms; ++t)
  {
    for (int d = 0; d < pde->num_dims; ++d)
    {
      std::string const filename = filename_base + std::to_string(t + 1) + "_" +
                                   std::to_string(d + 1) + ".dat";

      fk::matrix<TestType> const gold =
          fk::matrix<TestType>(read_matrix_from_txt_file(filename));
      fk::matrix<TestType> const &test =
          pde->get_coefficients(t, d).clone_onto_host();

      // determined empirically 11/19
      auto const tol_scale = 1e2;
      relaxed_comparison(gold, test, tol_scale);
    }
  }
}

TEMPLATE_TEST_CASE("fokkerplanck2_complete terms", "[coefficients]", double,
                   float)
{
  int const level     = 3;
  int const degree    = 4;
  TestType const time = 1.0;
  auto pde =
      make_PDE<TestType>(PDE_opts::fokkerplanck_2d_complete, level, degree);
  std::string const filename_base = "../testing/generated-inputs/coefficients/"
                                    "fokkerplanck2_complete_coefficients_l" +
                                    std::to_string(level) + "_d" +
                                    std::to_string(degree) + "_";

  generate_all_coefficients(*pde, time);

  for (int t = 0; t < pde->num_terms; ++t)
  {
    for (int d = 0; d < pde->num_dims; ++d)
    {
      std::string const filename = filename_base + std::to_string(t + 1) + "_" +
                                   std::to_string(d + 1) + ".dat";
      fk::matrix<TestType> const gold =
          fk::matrix<TestType>(read_matrix_from_txt_file(filename));
      fk::matrix<TestType> const &test =
          pde->get_coefficients(t, d).clone_onto_host();

      // determined empirically 11/19
      // FIXME what's with this large tolerance?
      auto const tol_scale = 5e6;
      relaxed_comparison(gold, test, tol_scale);
    }
  }
}

TEMPLATE_TEST_CASE("fokkerplanck2_complete terms - norotate", "[coefficients]",
                   double, float)
{
  int const level     = 3;
  int const degree    = 4;
  TestType const time = 1.0;
  auto pde =
      make_PDE<TestType>(PDE_opts::fokkerplanck_2d_complete, level, degree);
  std::string const filename_base =
      "../testing/generated-inputs/coefficients/"
      "fokkerplanck2_complete_coefficients_norotate_l" +
      std::to_string(level) + "_d" + std::to_string(degree) + "_";

  generate_all_coefficients(*pde, time, false);

  for (int t = 0; t < pde->num_terms; ++t)
  {
    for (int d = 0; d < pde->num_dims; ++d)
    {
      std::string const filename = filename_base + std::to_string(t + 1) + "_" +
                                   std::to_string(d + 1) + ".dat";

      fk::matrix<TestType> const gold =
          fk::matrix<TestType>(read_matrix_from_txt_file(filename));
      fk::matrix<TestType> const &test =
          pde->get_coefficients(t, d).clone_onto_host();

      // determined empirically 11/19
      auto const tol_scale = 1e3;
      relaxed_comparison(gold, test, tol_scale);
    }
  }
}
