//
// Created by giuli on 15/11/2020.
//

#include "Book.h"

float Book::compute_rating(){
    unsigned sum_ratings=0;
    for(unsigned i=0; i<5; i++){
        sum_ratings+=(i+1)*ratings_distr[i];
    }
    avg_rating = sum_ratings/review_count;
}

void Book::to_string() const{

    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Publisher: " << publisher << std::endl;
    std::cout << "Pages: " << pages_number << std::endl;

}

void Book::add_review(unsigned index, unsigned stars){
    review_count++;
    ratings_distr[stars-1]++;
    review_indexes.push_back(index);
}