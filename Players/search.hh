#ifndef SEARCH_HH
#define SEARCH_HH

#include <vector>
#include <string>
#include <utility>
#include <set>
#include <unordered_map>

#include "Player.hh"

typedef std::set<Arcade::Player> player_set_type;
typedef std::unordered_map<unsigned, Arcade::Player> player_map_type;

namespace Arcade
{
   bool binary_search (const std::vector<Arcade::Player> & player_vec,  unsigned player_username);
   bool set_search(const player_set_type & stud_set, unsigned username);
   bool map_search(const player_map_type & player_map, unsigned username);
}

#endif // SEARCH_HH
