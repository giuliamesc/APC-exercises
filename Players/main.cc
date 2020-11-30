#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "RandomPlayerGenerator.hh"
#include "search.hh"
#include "Player.hh"
#include "timing.hh"

typedef std::vector<Arcade::Player> player_vec_type;
typedef std::set<Arcade::Player> player_set_type;
typedef std::unordered_map<unsigned, Arcade::Player> player_map_type;

int main()
{
  constexpr unsigned n_player = 1000;
  player_vec_type player_vec;
  player_set_type player_set;
  player_map_type player_map;

  Arcade::RandomPlayerGenerator rs;

  // create the vector with players sorted by username
  for (unsigned i = 0; i < n_player; ++i)
    {
      Arcade::Player random_player = rs.nextPlayer();
      player_vec.push_back (random_player);
      player_set.insert(random_player);
      player_map.insert(std::make_pair(random_player.getUsername(),random_player));
    }

  const unsigned player_ok_username = player_vec[player_vec.size() / 2].getUsername();
  const unsigned player_ko_username = player_vec.back().getUsername() + 1;

  std::cout << "*********initial binary search on vector*********\n";

  std::cout << (Arcade::binary_search (player_vec, player_ok_username) ? "Found!\n" : "Not found\n");
  std::cout << (Arcade::binary_search (player_vec, player_ko_username) ? "Found!\n" : "Not found\n");

  std::cout << (std::binary_search (player_vec.cbegin(), player_vec.cend(),player_vec[player_vec.size() / 2]) ? "Found!\n" : "Not found\n");
  std::cout << (std::binary_search (player_vec.cbegin(), player_vec.cend(),player_vec.back()) ? "Found!\n" : "Not found\n");

  std::cout << (Arcade::set_search(player_set, player_ko_username) ? "Found!\n" : "Not found\n");
  std::cout << (Arcade::set_search(player_set, player_ok_username) ? "Found!\n" : "Not found\n");

  std::cout << (Arcade::map_search(player_map, player_ko_username) ? "Found!\n" : "Not found\n");
  std::cout << (Arcade::map_search(player_map, player_ok_username) ? "Found!\n" : "Not found\n");

  return 0;
}
