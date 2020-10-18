//
// Created by giuli on 18/10/2020.
//

#include "Stock_quote.h"

Stock_quote::Stock_quote(const std::string &s) : symbol(s) {}

const std::string &Stock_quote::getSymbol() const {
    return symbol;
}

const std::vector<float> &Stock_quote::getLastPrices() const {
    return last_prices;
}

void Stock_quote::add_price(const float p){
    last_prices.push_back(p);
}

void Stock_quote::print_vector() const {
    std::cout << symbol << std::endl;
    for(float last_price : last_prices){
        std::cout << "\t" << last_price;
    }
    std::cout <<"\n"<< "Done"<<std::endl;
}