#include <cpr/cpr.h>
#include <print>
#include <iostream>
#include <greeter/greeter.h>
#include <yfinance/quote.hpp>
#include "matplotlibcpp.h"

int main() {
    using namespace farra;
    yf::Quote q {"BTC-EUR"};
    q.getHistory("3mo", "max");

    namespace plt = matplotlibcpp;
    plt::plot({1,3,2,4});
    plt::show();

    return 0;
}