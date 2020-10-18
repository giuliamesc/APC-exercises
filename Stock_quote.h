//
// Created by giuli on 18/10/2020.
//

#ifndef STOCKQUOTES_STOCK_QUOTE_H
#define STOCKQUOTES_STOCK_QUOTE_H

#include <vector>
#include <iostream>
#include <string>

class Stock_quote {
private:
    const std::string symbol;
    std::vector<float> last_prices;
public:
    //constructor
    Stock_quote(const std::string &symbol);

    //getters
    const std::string &getSymbol() const;
    const std::vector<float> &getLastPrices() const;
    void add_price(const float p);
    void print_vector() const;
};


#endif //STOCKQUOTES_STOCK_QUOTE_H
