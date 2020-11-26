#include <iostream>

#include "instant_messenger.h"

int main ()
{
    im::Messenger msg;
    msg.send(0, "I'm coming home");
    msg.send(1, "What's for dinner?");
    msg.send(3, "Sorry, I'm late");

    std::list<im::Messenger::mapped_type> r_msg = msg.receive(1);
    std::cout << "-------------------- receive --------------------" << std::endl;
    for (const im::Messenger::mapped_type& m : r_msg)
        std::cout << m << std::endl;

    std::cout << std::endl;

    std::list<im::Messenger::mapped_type> s_msg = msg.search("home");
    std::cout << "-------------------- search --------------------" << std::endl;
    for (const im::Messenger::mapped_type& m : s_msg)
        std::cout << m << std::endl;

    return 0;
}
