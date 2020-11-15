//
// Created by giuli on 15/11/2020.
//

#include "GoodReads.h"

GoodReads::GoodReads(const std::vector<Book> &books, const std::vector<Review> &reviews) : books(books),
                                                                                           reviews(reviews) {}

unsigned GoodReads::find_book(const std::string& title) const{
    bool found=false;
    unsigned index;
    for(unsigned i=0; i<books.size() && !found; i++){
        if(title==books[i].getTitle()) {
            found=true;
            index=i;
         }
    }
return index;
}

bool GoodReads::includes_all(const std::vector<std::string> &words, const std::vector<std::string> &keywords) const{
    bool ret=true;
    for(unsigned i=0; i<keywords.size() && ret; i++){
        std::string kw=keywords[i];
        if(!includes_word(words, kw)) ret=false;
    }
    return ret;
}

bool GoodReads::includes_word(const std::vector<std::string> &words, std::string &k) const{
    bool found = false;

    for(unsigned i=0; i<words.size() && !found; i++){
        if(words[i]==k) found = true;
    }

    return found;
}

void GoodReads::add_book(const std::string &title, unsigned pagesNumber, const std::string &publisher, const std::string &author){
    books.push_back(Book(title,pagesNumber,publisher,author));
}

void GoodReads::add_review(const std::string &bookTitle, const std::string &text, unsigned int rating){
    unsigned rev_index=reviews.size();

    reviews.push_back(Review(bookTitle,text,rating));
    unsigned index=find_book(bookTitle);

    books[index].add_review(rev_index,rating);
}

float GoodReads::get_avg_rating() const{
    float sum=0.0;
    for(unsigned i=0; i<books.size(); i++){
        sum+=get_avg_rating(books[i].getTitle());
    }
    return sum/books.size();
}

float GoodReads::get_avg_rating(const std::string &title) const{
    unsigned index=find_book(title);
    return books[index].getAvgRating();
}

void GoodReads::search_reviews(const std::vector<std::string> &keywords) const {

    for (unsigned i=0; i<reviews.size(); i++){
        if(includes_all(reviews[i].getWords(),keywords)) {
            reviews[i].to_string();
        }
    }
}

void GoodReads::print_book(const std::string &title) const{
unsigned index=find_book(title);
books[index].to_string();
}