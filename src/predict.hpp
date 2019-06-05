// Automatically generated by perf_predict
#pragma once
#include "pde.hpp"
#include <algorithm>
#include <iostream>
#include <utility>

std::pair<std::string, double> continuity_3_MB(int level, int degree)
{
  level -= 1;
  degree -= 2;

  double a =
      0.019688000000079125 * pow(level, 0) +
      -6.714436380952768 * pow(level, 1) + 12.834880095238516 * pow(level, 2) +
      -7.373541904762054 * pow(level, 3) + 1.3975347619047795 * pow(level, 4);
  double b =
      0.008724800000019716 * pow(level, 0) +
      -3.603043276190669 * pow(level, 1) + 6.894563885714479 * pow(level, 2) +
      -3.9607251809524473 * pow(level, 3) + 0.7510742857142927 * pow(level, 4);
  double c =
      0.29121600000006415 * pow(level, 0) + -9.645553961905268 * pow(level, 1) +
      18.43217399047674 * pow(level, 2) + -10.588897009523999 * pow(level, 3) +
      2.007082923809546 * pow(level, 4);

  // return a * pow(degree, 2) + b * degree + c;

  return std::make_pair(
      "(Predicted for 9bac2a8487482223d33f8606df17dc83ef6e79f1 on Tuesday, "
      "June 04 2019 at  1:01 pm)",
      a * pow(degree, 2) + b * degree + c);
}

std::pair<std::string, double> continuity_2_MB(int level, int degree)
{
  level -= 1;
  degree -= 2;

  double a = 0.0018040000000002338 * pow(level, 0) +
             -0.040294047619050054 * pow(level, 1) +
             0.07590307142857423 * pow(level, 2) +
             -0.04248966666666777 * pow(level, 3) +
             0.008369214285714426 * pow(level, 4);
  double b = -0.003178400000000116 * pow(level, 0) +
             -0.12443880952381585 * pow(level, 1) +
             0.2719346142857203 * pow(level, 2) +
             -0.15975953333333504 * pow(level, 3) +
             0.03236944285714301 * pow(level, 4);
  double c = 0.27665440000000424 * pow(level, 0) +
             -0.3649787619047832 * pow(level, 1) +
             0.6924633428571662 * pow(level, 2) +
             -0.39200306666667484 * pow(level, 3) +
             0.07736442857142951 * pow(level, 4);

  // return a * pow(degree, 2) + b * degree + c;

  return std::make_pair(
      "(Predicted for 8e150698e3c34ad032fe97a5a0475d276b726c18 on Tuesday, "
      "June 04 2019 at  2:39 pm)",
      a * pow(degree, 2) + b * degree + c);
}

std::pair<std::string, double> continuity_1_MB(int level, int degree)
{
  level -= 1;
  degree -= 2;

  double a = 0.0006674285714285984 * pow(level, 0) +
             0.000281142857142858 * pow(level, 1) +
             0.000281142857142858 * pow(level, 2) +
             0.000281142857142858 * pow(level, 3) +
             0.000281142857142858 * pow(level, 4) +
             0.000281142857142858 * pow(level, 5) +
             0.00028114285714285806 * pow(level, 6) +
             0.00028114285714285795 * pow(level, 7);
  double b = -0.0017353142857143749 * pow(level, 0) +
             0.0002505142857142802 * pow(level, 1) +
             0.0002505142857142802 * pow(level, 2) +
             0.0002505142857142802 * pow(level, 3) +
             0.0002505142857142802 * pow(level, 4) +
             0.0002505142857142802 * pow(level, 5) +
             0.0002505142857142803 * pow(level, 6) +
             0.0002505142857142802 * pow(level, 7);
  double c = 0.276728457142857 * pow(level, 0) +
             -0.00017599999999999417 * pow(level, 1) +
             -0.00017599999999999417 * pow(level, 2) +
             -0.00017599999999999417 * pow(level, 3) +
             -0.00017599999999999417 * pow(level, 4) +
             -0.00017599999999999417 * pow(level, 5) +
             -0.0001759999999999942 * pow(level, 6) +
             -0.00017600000000000948 * pow(level, 7);

  // return a * pow(degree, 2) + b * degree + c;

  return std::make_pair(
      "(Predicted for 49a92e82aa34222ad869edbac2093797868bc63d on Tue Jun 4 "
      "15:11:39 2019 -0400s)",
      a * pow(degree, 2) + b * degree + c);
}

std::pair<std::string, double>
total_mem_usage(PDE_opts pde, int level, int degree)
{
  switch (pde)
  {
  case PDE_opts::continuity_3:
    return continuity_3_MB(level, degree);
    break;
  case PDE_opts::continuity_2:
    return continuity_2_MB(level, degree);
    break;
  case PDE_opts::continuity_1:
    return continuity_1_MB(level, degree);
    break;
  default:
    return std::make_pair("", 0);
  }
}

std::pair<std::string, double> continuity_3_seconds(int level, int degree)
{
  level -= 1;
  degree -= 2;

  double a = 0.002857142857144573 * pow(level, 0) +
             -0.38630952380954076 * pow(level, 1) +
             0.6724404761904947 * pow(level, 2) +
             -0.33583333333333976 * pow(level, 3) +
             0.05184523809523887 * pow(level, 4);
  double b =
      -0.0014285714285782445 * pow(level, 0) +
      1.0062380952381387 * pow(level, 1) + -1.7052619047619495 * pow(level, 2) +
      0.7983333333333495 * pow(level, 3) + -0.09888095238095432 * pow(level, 4);
  double c =
      0.10971428571429791 * pow(level, 0) +
      -1.2576190476191125 * pow(level, 1) + 2.3733809523810225 * pow(level, 2) +
      -1.3166666666666913 * pow(level, 3) + 0.23319047619047908 * pow(level, 4);

  // return a * pow(degree, 2) + b * degree + c;

  return std::make_pair(
      "(Predicted for 9bac2a8487482223d33f8606df17dc83ef6e79f1 on Tuesday, "
      "June 04 2019 at  1:01 pm)",
      a * pow(degree, 2) + b * degree + c);
}

std::pair<std::string, double> continuity_2_seconds(int level, int degree)
{
  level -= 1;
  degree -= 2;

  double a = 0.0009523809523809575 * pow(level, 0) +
             0.002718253968254221 * pow(level, 1) +
             -0.00752976190476221 * pow(level, 2) +
             0.004305555555555671 * pow(level, 3) +
             -0.0006845238095238234 * pow(level, 4);
  double b = 0.0035238095238095167 * pow(level, 0) +
             -0.009567460317461193 * pow(level, 1) +
             0.026216269841270887 * pow(level, 2) +
             -0.015027777777778169 * pow(level, 3) +
             0.0028075396825397317 * pow(level, 4);
  double c = 0.10323809523809548 * pow(level, 0) +
             -0.028007936507937935 * pow(level, 1) +
             0.05005158730158866 * pow(level, 2) +
             -0.028944444444444856 * pow(level, 3) +
             0.006519841269841311 * pow(level, 4);

  // return a * pow(degree, 2) + b * degree + c;

  return std::make_pair(
      "(Predicted for 8e150698e3c34ad032fe97a5a0475d276b726c18 on Tuesday, "
      "June 04 2019 at  2:41 pm)",
      a * pow(degree, 2) + b * degree + c);
}

std::pair<std::string, double> continuity_1_seconds(int level, int degree)
{
  level -= 1;
  degree -= 2;

  double a = 0.0007142857142857152 * pow(level, 0) +
             -0.00020408163265306142 * pow(level, 1) +
             -0.00020408163265306142 * pow(level, 2) +
             -0.00020408163265306142 * pow(level, 3) +
             -0.00020408163265306142 * pow(level, 4) +
             -0.00020408163265306142 * pow(level, 5) +
             -0.0002040816326530615 * pow(level, 6) +
             -0.0002040816326530614 * pow(level, 7);
  double b = 0.002142857142857143 * pow(level, 0) +
             0.0008163265306122471 * pow(level, 1) +
             0.0008163265306122471 * pow(level, 2) +
             0.0008163265306122471 * pow(level, 3) +
             0.0008163265306122471 * pow(level, 4) +
             0.0008163265306122471 * pow(level, 5) +
             0.0008163265306122473 * pow(level, 6) +
             0.0008163265306122473 * pow(level, 7);
  double c = 0.08942857142857134 * pow(level, 0) +
             0.00016326530612245112 * pow(level, 1) +
             0.00016326530612245112 * pow(level, 2) +
             0.00016326530612245112 * pow(level, 3) +
             0.00016326530612245112 * pow(level, 4) +
             0.00016326530612245112 * pow(level, 5) +
             0.00016326530612245118 * pow(level, 6) +
             0.0001632653061224565 * pow(level, 7);

  // return a * pow(degree, 2) + b * degree + c;

  return std::make_pair(
      "(Predicted for 49a92e82aa34222ad869edbac2093797868bc63d on Tue Jun 4 "
      "15:11:39 2019 -0400s)",
      a * pow(degree, 2) + b * degree + c);
}

std::pair<std::string, double>
expected_time(PDE_opts pde, int level, int degree)
{
  switch (pde)
  {
  case PDE_opts::continuity_3:
    return continuity_3_seconds(level, degree);
    break;
  case PDE_opts::continuity_2:
    return continuity_2_seconds(level, degree);
    break;
  case PDE_opts::continuity_1:
    return continuity_1_seconds(level, degree);
    break;
  default:
    return std::make_pair("", 0);
  }
}
