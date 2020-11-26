//
// Created by Federica Filippini on 23/11/2020.
//

#ifndef INSTANT_MESSENGER_H
#define INSTANT_MESSENGER_H

#include <string>
#include <map>
#include <list>

namespace im {

    class Messenger {

    private:
        typedef std::map<unsigned long, std::string> container_type;
        container_type m_data;

    public:
        typedef container_type::key_type key_type; //unsigned long
        typedef container_type::mapped_type mapped_type; //string
        typedef container_type::value_type value_type; //pair

        void send (key_type, const mapped_type&);

        std::list<mapped_type> receive (key_type) const;
        std::list<mapped_type> search (const std::string&) const;

    };

}


#endif //INSTANT_MESSENGER_H
