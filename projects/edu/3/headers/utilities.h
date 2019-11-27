#include <string>

namespace utilities
{
  std::string calc_ol_result(std::string result)
  {
    // split string
    // calculate points
  }

  double calc_aggregate(int utme, int post_utme, int ol_score)
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

    return (0.0625 * utme) + (0.50 * ol_score) + (0.50 * post_utme);
  }
}
