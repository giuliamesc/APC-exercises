//
// Created by Federica Filippini on 23/11/2020.
//

#ifndef COUNTERQUEUE_INITIAL_COUNTER_QUEUE_H
#define COUNTERQUEUE_INITIAL_COUNTER_QUEUE_H

#include <string>
#include <queue>
#include <unordered_set>

namespace Supermarket {

    class Counter_queue {

    private:
        std::queue<std::string> m_order;
        std::unordered_set<std::string> m_in_line;

    public:
        bool pick_number (const std::string & customer_id);

        std::string next_customer ();

        bool empty () const;
    };
}

#endif //COUNTERQUEUE_INITIAL_COUNTER_QUEUE_H
