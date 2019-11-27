#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

namespace utilities
{
  std::string calc_ol_result(std::string result)
  {
    // split string
    // calculate points
    std::fstream lfs;
    std::string chunk;
    int i;

    for (chunk, i = 0; getline(lfs, chunk, ';'); i++)
    {
      std::stringstream sss(chunk);
      
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
      std::cout << "Max no of sitting is 2, you have not qualified for admission!" << std::endl;

      return;
    }

    return (0.0625 * utme) + (0.50 * ol_score) + (0.50 * post_utme);
  }
}
