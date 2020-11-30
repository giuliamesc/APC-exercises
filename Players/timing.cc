#include <ctime>
#include <iostream>

#include "timing.hh"

namespace timing
{
  void elapsed_between (const time_point & start, const time_point & finish)
  {
    std::chrono::duration<double> elapsed_seconds = finish - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t (finish);
    std::cout << "finished computation at " << std::ctime (&end_time)
              << "elapsed time: " << elapsed_seconds.count() << " s"
              << std::endl;
  }
}
