//
// Created by Federica Filippini on 23/11/2020.
//

#include "instant_messenger.h"

namespace im
{
    void Messenger::send(key_type time, const mapped_type& msg){
        m_data[time]=msg;
    }

    std::list<Messenger::mapped_type> Messenger::receive (key_type timestamp) const{
        std::list<mapped_type> result;

        for(container_type::const_iterator it=m_data.lower_bound(timestamp); it!=m_data.cend(); ++it)
            result.push_back(it->second);

        return result;
    }
    std::list<Messenger::mapped_type> Messenger::search (const std::string& word) const{
        std::list<mapped_type> result;

        for(const container_type::value_type& pair : m_data){
            const mapped_type& msg=pair.second;
            if(msg.find(word) != mapped_type::npos) result.push_back(msg);
        }

        return result;
    }

    }

