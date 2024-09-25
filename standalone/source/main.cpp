#include <cpr/cpr.h>
#include <print>


int main(int argc, char** argv) {
    cpr::Response r = cpr::Get(cpr::Url{"https://query1.finance.yahoo.com/v8/finance/chart/EURUSD=X?interval=15m&range=1d"});
    r.status_code;                  // 200
    r.header["content-type"];       // application/json; charset=utf-8
    r.text;                         // JSON text string

    std::println("Text: {}", r.text);
    return 0;

}