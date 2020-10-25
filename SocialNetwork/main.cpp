// include
#include "social_network.hpp"
#include "user.hpp"

///STD include
#include <iostream>

using namespace SocialNetworkNS;

int main()
{
   SocialNetwork social_network = SocialNetwork();
   social_network.AddUser("Giulia", "Mescolini");
   social_network.AddUser("Filippo", "Tombari");
   social_network.AddUser("Michele", "Barucca");
   social_network.AddUser("Elisabetta", "Garbin");
   social_network.AddUser("Maurizio", "Vianello");
   social_network.AddUser("Anna Maria", "Paganoni");
   social_network.AddUser("Alfio", "Quarteroni");
   social_network.AddUser("Paolo", "Zunino");
   social_network.AddUser("Elena", "Ricci Armani");
   social_network.AddUser("Emilio", "Barucci");
   social_network.AddUser("Irene", "Sabadini");
   social_network.AddUser("Irene", "Sabadini");

   social_network.AddFriendship("Anna Maria", "Paganoni", "Anna Maria", "Paganoni");
   social_network.AddFriendship("Giulia","Mescolini","Giulia","Mescolini");
   social_network.AddFriendship("Paolo", "Zunino", "Giulio", "Orso");
   social_network.AddFriendship("Anna Maria", "Paganoni", "Giulia", "Mescolini");
   social_network.AddFriendship("Giulia", "Mescolini","Filippo", "Tombari");
   social_network.AddFriendship("Giulia", "Mescolini", "Michele", "Barucca");
   social_network.AddFriendship("Elena", "Ricci Armani", "Emilio", "Barucci");
   social_network.AddFriendship("Maurizio", "Vianello","Alfio", "Quarteroni");
   social_network.AddFriendship("Anna Maria", "Paganoni", "Alfio", "Quarteroni");
   social_network.AddFriendship("Irene", "Sabadini", "Giulia", "Mescolini");
   social_network.AddFriendship("Elisabetta", "Garbin", "Filippo", "Tombari");
   social_network.AddFriendship("Elena", "Ricci Armani", "Filippo", "Tombari");
   social_network.AddFriendship("Filippo", "Tombari", "Maurizio", "Vianello");
   social_network.AddFriendship("Alfio", "Quarteroni", "Irene", "Sabadini");
   social_network.AddFriendship("Michele", "Barucca", "Emilio", "Barucci");
   social_network.AddFriendship("Giulia", "Mescolini", "Elisabetta", "Garbin");
   social_network.AddFriendship("Anna Maria", "Paganoni","Maurizio", "Vianello");
   social_network.AddFriendship("Emilio", "Barucci", "Alfio", "Quarteroni");
   social_network.AddFriendship("Paolo", "Zunino", "Paolo", "Zunino");


    for(const auto & user : social_network.CGetUsers())
   {
      std::cout << "List of friends of " << user.ToString() << std::endl;

      for(const auto & user_friend : social_network.CGetFriends(user))
      {
         std::cout << "   " << user_friend.ToString() << std::endl;
      }
   }


   return 0;
}
