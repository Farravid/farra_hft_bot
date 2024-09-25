#include <cpr/cpr.h>
#include <print>
#include <nlohmann/json.hpp>
#include <iostream>
#include <greeter/greeter.h>
#include <yfinance/quote.hpp>

int main(int argc, char** argv) {

	std::string s {"GOOG"};
	farra::yf::Quote q ("test1", "test2", s);

	//static_assert(std::is_convertible_v<decltype("test"), std::string>);

	//static_assert(farra::yf::all_types_string<std::string, std::string>);
	// cpr::Response r = cpr::Get(cpr::Url{"https://query1.finance.yahoo.com/v8/finance/chart/EURUSD=X?interval=15m&range=1d"});
	// r.status_code;                  // 200
	// r.header["content-type"];       // application/json; charset=utf-8
	// r.text; 
	

	// nlohmann::json data = nlohmann::json::parse(r.text);
	// auto data2 = data["chart"]["result"][0]["meta"];

	// //std::cout << "Parsed JSON: " << data2.dump(4) << std::endl; 

	// std::println("Thing: {}",data2["currency"].get<std::string>());

	// //std::println("Fruit: {}", data["fruit"]);
	// //auto m = data["meta"];
	// //std::println("Currency: {}", data["meta"]);
	// //std::println("Text: {}", data);
	return 0;
	// return 0;
}