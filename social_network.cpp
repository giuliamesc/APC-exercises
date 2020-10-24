///Header include
#include "social_network.hpp"
#include "user.hpp"

///STD include
#include <iostream>

namespace SocialNetworkNS {
    size_t SocialNetwork::CUserIndex(const std::string &name,
                                     const std::string &surname) const {
        size_t i;

        User u(name, surname);

        bool found = false;

        for (i = 0; i < users.size() && !found; ++i)
            if (users[i] == u)
                found = true;

        if (found)
            return --i;
        else
            return users.size();
    }

    void SocialNetwork::AddUser(const std::string &name,
                                const std::string &surname) {
        //checking whether the user is already in the social network
        if(users.size() == CUserIndex(name, surname)) {
            users.push_back(User(name, surname));
            std::cout << "The user has been added to the Social Network" << std::endl;
            std::vector<size_t> place;
            friends.push_back(place);
        }
        //else we send an error message
        else{
            std::cout << "The user is already in the Social Network" << std::endl;
        }
    }

    const std::vector<User> SocialNetwork::CGetUsers() const {
        return users;
    }


    const std::vector<User> SocialNetwork::CGetFriends(const User &user) const {
        return SocialNetwork::CGetFriends(user.CGetName(),user.CGetSurname());
    }


    const std::vector<User> SocialNetwork::CGetFriends(const std::string &name,
                                                       const std::string &surname) const {
        std::vector<User> ret{};
        size_t index = CUserIndex(name, surname);

        for (size_t i = 0; i < friends[index].size(); i++) {
            size_t j = friends[index][i];
            ret.push_back(users[j]);
        }

        return ret;
    }

    void SocialNetwork::AddFriendship(const std::string &first_name,
                                      const std::string &first_surname,
                                      const std::string &second_name,
                                      const std::string &second_surname) {

        size_t x = CUserIndex(first_name, first_surname);
        size_t y = CUserIndex(second_name, second_surname);
        //std::cout << x << y << std::endl;

        bool control = true;

        for(size_t i=0; i<friends[x].size(); i++){
            if(friends[x][i] == y) control = false;
        }
        if(!control) std::cout << "Friendship already added to the Social Network" << std::endl;

        //friend of yourself
        if (x == y) {
            control = false;
            std::cout << "You can't be friend of yourself :P" << std::endl;
        }

        //friend of an unexisting user
        if (x == users.size() || y == users.size()) {
            control = false;
            std::cout << "You can't be friend of someone who is not in the Social Network" << std::endl;
        }

        if(control) {
            friends[x].push_back(y);
            friends[y].push_back(x);
            std::cout << "Friendship added to the Social Network" << std::endl;
        }

    }
}