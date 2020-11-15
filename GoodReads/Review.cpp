//
// Created by giuli on 15/11/2020.
//

#include "Review.h"

const std::string &Review::getText() const {
    return text;
}

const std::vector<std::string> &Review::getWords() const {
    return words;
}

void Review::to_string() const{
    std::cout << "Book title: " << book_title << std::endl;
    std::cout << "Text: " << text <<std::endl;
}

bool Review::find_in_words(const std::string & w){

    bool found = false;

    for(unsigned i=0; i<words.size() && !found; i++){
        if(words[i]==w) found = true;
    }

    return found;

    /*for(unsigned i=0; i<getText().length() && !found; i++){
        if(text[i]==w[0]){
            bool stop=false;
            for(unsigned j=1; j<w.length() &&!stop; j++){
                if(text[i+j]!=w[j]) stop=true;
            }
            if(!stop) found=true;
        }
    }*/
}