#include <iostream>

#include "counter_queue.h"

int main (void)
{
    Supermarket::Counter_queue queue1;

    bool b0 = queue1.pick_number("AAA0");
    if (! b0)
        std::cout << "client was already in the queue" << std::endl;
    else
        std::cout << "client inserted in the queue!" << std::endl;

    bool b1 = queue1.pick_number("BBB1");
    if (! b1)
        std::cout << "client was already in the queue" << std::endl;
    else
        std::cout << "client inserted in the queue!" << std::endl;

    bool b2 = queue1.pick_number("CCC2");
    if (! b2)
        std::cout << "client was already in the queue" << std::endl;
    else
        std::cout << "client inserted in the queue!" << std::endl;

    bool b1_2 = queue1.pick_number("BBB1");
    if (! b1_2)
        std::cout << "client was already in the queue" << std::endl;
    else
        std::cout << "client inserted in the queue!" << std::endl;

    std::cout << "\nnext customer to serve: " << queue1.next_customer() << std::endl;
    std::cout << "next customer to serve: " << queue1.next_customer() << std::endl;

    return 0;
}
