//
// Created by giuli on 15/11/2020.
//

#ifndef GOODREADS_BOOK_H
#define GOODREADS_BOOK_H

#include <vector>
#include <iostream>
#include <string>

class Book {
private:
    std::vector<unsigned> ratings_distr;
    unsigned int pages_number;
    std::string publisher;
    unsigned review_count;
    std::string author;
    std::string title;
    float avg_rating;
    std::vector<unsigned> review_indexes;

    float compute_rating();

public:
    Book(const std::string &t, unsigned int pag, const std::string &pub, const std::string &au) : title(t), pages_number(pag), publisher(pub), author(au) {}

    void add_review(unsigned index, unsigned stars);

    void to_string() const;

    const std::string &getTitle() const {
        return title;
    }

    float getAvgRating() const {
        return avg_rating;
    }

    const std::vector<unsigned int> &getReviewIndexes() const {
        return review_indexes;
    }

};

#endif //GOODREADS_BOOK_H
