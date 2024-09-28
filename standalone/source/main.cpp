#include <cpr/cpr.h>
#include <print>
#include <iostream>
#include <greeter/greeter.h>
#include <yfinance/quote.hpp>
#include "matplotlibcpp.h"

int main() {
    using namespace farra;
    yf::Quote q {"BTC-EUR"};
    auto x = q.getHistory("1d", "ytd");

    namespace plt = matplotlibcpp;

    // Example vector
    std::vector<double> values = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};

    // Plot the values
    plt::plot(x);

    plt::show();

    return 0;
}