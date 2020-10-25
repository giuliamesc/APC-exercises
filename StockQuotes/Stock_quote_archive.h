//
// Created by giuli on 18/10/2020.
//

#ifndef STOCKQUOTES_STOCK_QUOTE_ARCHIVE_H
#define STOCKQUOTES_STOCK_QUOTE_ARCHIVE_H

#include "Stock_quote.h"

class Stock_quote_archive {
private:
    std::vector<Stock_quote> stocks;
public:
    Stock_quote_archive()=default;
    void add_stock_quote(const std::string &s);
    void add_last_sale_price(float p, const std::string &s);
    void print_quote(const std::string &s) const;
    void print_stocks() const;
};


#endif //STOCKQUOTES_STOCK_QUOTE_ARCHIVE_H
