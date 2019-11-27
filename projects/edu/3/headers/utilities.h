/*
  O/L score = Total O/L point + Sitting point
  C6 = 3, C5 = 4, C4 = 5, B3 (A3) = 6, B2 (A2) = 7, A1 = 8
  max sitting = 2
  1 sitting = 10 points 
  2 sittings = 5 points
*/

#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

// #include "utilities.h"

namespace utilities
{
  int calc_ol_result(std::string result)
  {
    // split string
    // calculate points
    std::stringstream rss(result); // whole result column steam
    std::string chunk;
    int i, total_ol_score = 0, score = 0;

    for (chunk, i = 0; getline(rss, chunk, ';'); i++)
    {
      std::stringstream irs(chunk); // individual result stream
      int _i;
      std::string subject, grade;

      std::cout << "calculating O'Level results..." << std::endl;

      for (chunk, _i = 0; getline(irs, chunk, '-'); i++)
      {
        // std::stringstream _bits(chunk); // individual result stream
        if (_i == 0)
          subject = chunk; // subject

        if (_i == 1)
        {
          grade = chunk; // grade
          // get grade equivalent
          score = grade_equivalent(grade); // call method thats calculates grade equivalent
          total_ol_score += score; // add to score
        }

        std::cout << "subject: " << subject << " score: " << score << std::endl;        
      }
    }
  }

  double calc_aggregate(int utme, int post_utme, int ol_score, int sitting_no)
  {
    // calculate aggregate
    // normalize score
    if (utme > 400)
    {
      utme = 400;
    }

    if (post_utme > 50)
    {
      post_utme = 50;
    }
    
    if (sitting_no > 2)
    {
      std::cout << "Max no of sitting is 2, you are not qualified for admission!" << std::endl;

      return;
    }

    return (0.0625 * utme) + (0.50 * ol_score) + (0.50 * post_utme);
  }

  int grade_equivalent(std::string grade)
  {
    // ...
    // method here
    if (
      grade == "a1" ||
      grade == "A1"
      ) return 8;

    if (
      grade == "a2" ||
      grade == "b2" ||
      grade == "A2" ||
      grade == "B2"
      ) return 7;

    if (
      grade == "a3" ||
      grade == "A3" ||
      grade == "b3" ||
      grade == "B3"

      ) return 6;

    if (
    grade == "c4" ||
    grade == "C4"
    ) return 5;

    if (
    grade == "c5" ||
    grade == "C5"
    ) return 4;

    if (
    grade == "c6" ||
    grade == "C6"
    ) return 5;

    return 0;
  }
}