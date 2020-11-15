//
// Created by giuli on 15/11/2020.
//

#ifndef GOODREADS_GOODREADS_H
#define GOODREADS_GOODREADS_H

#include "Book.h"
#include "Review.h"

class GoodReads {

private:
    std::vector<Book> books;
    std::vector<Review> reviews;

    unsigned find_book(const std::string& title) const;

    bool includes_all(const std::vector<std::string> &words, const std::vector<std::string> &keywords) const;
    bool includes_word(const std::vector<std::string> &words, std::string &k) const;

public:
    GoodReads(const std::vector<Book> &books, const std::vector<Review> &reviews);

    void add_book(const std::string &title, unsigned pagesNumber, const std::string &publisher, const std::string &author);
    void add_review(const std::string &bookTitle, const std::string &text, unsigned int rating);

    float get_avg_rating() const;
    float get_avg_rating(const std::string &title) const;

    void search_reviews(const std::vector<std::string> &keywords) const;

    void print_book(const std::string &title) const;
};


#endif //GOODREADS_GOODREADS_H
