#include <iostream>

#include "Player.hh"

namespace Arcade
{
  Player::Player (unsigned _username, const std::vector<unsigned> & _scores) :
     username (_username),
     scores (_scores)
   {}

  Player::Player (unsigned _username) :
     username (_username),
     scores ()
   {}

  const std::vector<unsigned> & Player::getScores() const
  {
    return scores;
  }

  unsigned Player::getUsername() const
  {
    return username;
  }

  void Player::setScores (const std::vector<unsigned> & new_scores)
  {
    scores = new_scores;
  }

  void Player::setUsername (unsigned new_username)
  {
    username = new_username;
  }

  void Player::print() const
  {
    std::cout << username << ":\n";

    for (unsigned score : scores)
      std::cout << score << " ";

    std::cout << std::endl;
  }

  bool Player::operator< (const Player & rhs) const{
     if (username < rhs.username)
         return true;
     else
         return false;
  }
}
