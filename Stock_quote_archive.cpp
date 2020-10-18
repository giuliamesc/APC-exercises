//
// Created by giuli on 18/10/2020.
//

#include "Stock_quote_archive.h"

void Stock_quote_archive::add_stock_quote(const std::string &s){
    unsigned i=0;
    bool bol = false;
    while (i<stocks.size() && bol==false) {
        if (stocks[i].getSymbol() == s) bol = true;
        else i++;
    }
    if(!bol) stocks.push_back(Stock_quote(s));
    else std::cout << "Already in the database" << std::endl;
}

void Stock_quote_archive::add_last_sale_price(float p, const std::string &s){
    unsigned i=0;
    bool bol = false;
    while (i<stocks.size() && bol==false) {
        if (stocks[i].getSymbol() == s) bol = true;
        else i++;
    }
    if (bol) stocks[i].add_price(p);
    else std::cout << "Error!" << std::endl;

}

void Stock_quote_archive::print_quote(const std::string &s) const{
    for (unsigned i=0; i<stocks.size(); i++){
        if(stocks[i].getSymbol()==s) stocks[i].print_vector();
    }
}

void Stock_quote_archive::print_stocks() const{
    for (unsigned i=0; i<stocks.size(); i++){
        std::cout << stocks[i].getSymbol() << std::endl;
    }
}
