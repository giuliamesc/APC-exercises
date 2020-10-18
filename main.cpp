#include <iostream>
#include "Stock_quote.h"
#include "Stock_quote_archive.h"
int main() {
    Stock_quote_archive arch;
    arch.add_stock_quote("Umbretti");
    arch.add_stock_quote("Pusheen");
    arch.add_last_sale_price(40.3,"Umbretti");
    arch.add_last_sale_price(40.7,"Umbretti");
    arch.add_last_sale_price(40.8,"Umbretti");
    arch.add_last_sale_price(56.3, "Pusheen");
    arch.add_last_sale_price(58.3, "Pusheen");
    arch.print_quote("Umbretti");
    arch.print_quote("Pusheen");

    return 0;
}
