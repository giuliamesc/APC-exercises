//
// Created by giuli on 15/11/2020.
//

#ifndef GOODREADS_REVIEW_H
#define GOODREADS_REVIEW_H

#include <string>
#include <vector>
#include <iostream>

class Review {
private:
    std::string book_title;
    std::string text;
    unsigned int rating;
    std::vector<std::string> words;

    bool find_in_words(const std::string & w);

public:
    Review(const std::string &title, const std::string &t, unsigned int rat) : book_title(title), text(t), rating(rat) {}
    const std::string &getText() const;
    const std::vector<std::string> &getWords() const;
    void to_string() const;
};


#endif //GOODREADS_REVIEW_H
