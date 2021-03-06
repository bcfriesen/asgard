# builder

builder is a minimal tool used by [perf_predict](../README.md) to manage the file and string manipulation of building the output header file from the individual functions generated by [the profiler](../profiler/README.md)

## Usage

builder takes three required arguments, the path to the directory containing the functions for memory predictions, the path to the directory containing the functions for compute time predictions, and the output directory for the output `predict.hpp` header.

Here are the flags used to pass these arguments to builder.

| Flag | Meaning |
|--------------------|------------------------------------------------------------------------|
| `-m`, `--mem-dir` | The path to the folder holding memory usage prediction functions. |
| `-t`, `--time-dir` | The path to the folder holding compute time prediction functions. |
| `-o`, `--out-dir` | The path to the output directory where `predict.hpp` could be written. |
