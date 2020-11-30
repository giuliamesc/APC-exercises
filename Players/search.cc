#include <iostream>

#include "search.hh"
#include "timing.hh"

namespace Arcade
{
   bool binary_search (const std::vector<Arcade::Player> & player_vec, unsigned player_username)
   {
      timing::time_point start = std::chrono::system_clock::now();

      std::vector<Arcade::Player>::const_iterator begin = player_vec.begin(), end = player_vec.end(),
         // original musernamepoint
         musername = begin + (end - begin) / 2;
      unsigned n_iter = 1;

      while (begin != end and musername->getUsername() != player_username)
      {
         /* end is meant to be invalusername, so in both cases
          * we are ignoring musername at the following iteration
          */
         if (player_username < musername->getUsername())
            end = musername;
         else
            begin = musername + 1;

         musername = begin + (end - begin) / 2;
         ++n_iter;
      }

      std::cout << "Number of Iterations " << n_iter << "\n";

      timing::time_point finish = std::chrono::system_clock::now();
      timing::elapsed_between (start, finish);

      if (musername != player_vec.end() and player_username == musername->getUsername())
      {
         return true;
      }
      else
      {
         return false;
      }
   }

    bool set_search(const player_set_type & stud_set, unsigned username){
        timing::time_point start = std::chrono::system_clock::now();

        bool find = false;

        Player A(username);
        
        if (stud_set.find(A) != stud_set.end())
                find = true;
         
        

        timing::time_point finish = std::chrono::system_clock::now();
        timing::elapsed_between (start, finish);
        return find;

   }
    bool map_search(const player_map_type & player_map, unsigned username){
        timing::time_point start = std::chrono::system_clock::now();
        for(player_map_type::const_iterator it=player_map.cbegin(); it!=player_map.cend(); it++){
            if(it->first==username) {
                timing::time_point finish = std::chrono::system_clock::now();
                timing::elapsed_between (start, finish);
                return true;
            }
        }
        timing::time_point finish = std::chrono::system_clock::now();
        timing::elapsed_between (start, finish);
        return false;
   }
}
