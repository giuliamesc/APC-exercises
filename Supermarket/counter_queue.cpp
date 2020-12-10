//
// Created by Federica Filippini on 23/11/2020.
//

#include "counter_queue.h"

namespace Supermarket
{
    bool Counter_queue::pick_number (const std::string & customer_id){
        typedef std::pair<std::unordered_set<std::string>::iterator, bool> ret_type;
        ret_type outcome=m_in_line.insert(customer_id);

        bool inserted=outcome.second;

        if(inserted)
            m_order.push(customer_id);

        return inserted;
    }

    std::string Counter_queue::next_customer (){
        std::string next =m_order.front();
        m_order.pop();
        m_in_line.erase(next);
        return next;
    }

    bool Counter_queue::empty () const{
        return m_order.empty();
    }

}