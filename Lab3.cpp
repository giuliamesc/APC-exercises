#include <iostream>
#include <string>
#include <vector>

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
  //player_set_type player_set;
  player_map_type player_map;
  Arcade::RandomPlayerGenerator rs;

  // create the vector with players sorted by username
  for (unsigned i = 0; i < n_player; ++i)
    {
      Arcade::Player random_player = rs.nextPlayer();
      player_vec.push_back (random_player);
      //player_set.insert(random_player);
      player_map.insert(std::make_pair(random_player.getUsername(),random_player));
    }

  const unsigned player_ok_username = player_vec[player_vec.size() / 2].getUsername();
  const unsigned player_ko_username = player_vec.back().getUsername() + 1;

  std::cout << "*********initial binary search on vector*********\n";
  std::cout << (Arcade::binary_search (player_vec, player_ok_username) ? "Found!\n" : "Not found\n");
  std::cout << (Arcade::binary_search (player_vec, player_ko_username) ? "Found!\n" : "Not found\n");

  return 0;
}

bool operator<(const Arcade::Player &lhs, const Arcade::Player &rhs){
    return (lhs.getUsername()<rhs.getUsername());
}

bool set_search(const player_set_type & stud_set, unsigned username){
    bool found=false;
    for(auto it=stud_set.cbegin(); !found && it!=stud_set.cend(); ++it){
        if(it->getUsername()==username) found=true;
    }
    return found;
}

bool map_search(const player_map_type & player_map, unsigned username){
    auto iter=player_map.find(username);
    return iter!=player_map.cend();
}
