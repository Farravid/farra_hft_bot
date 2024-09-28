#pragma once

#include <concepts>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

//TODO: Move to a clang compiler

namespace farra::yf
{
    template<typename... Args>
    concept all_types_convertible = std::conjunction_v<std::is_convertible<Args, std::string>...>;

    static inline constexpr auto QUERY_YAHOO_URL = "https://query1.finance.yahoo.com/v8/finance/chart"; 

    //template<std::size_t N>
    struct Quote
    {
        // template<all_types_convertible... Args>
        // explicit Quote(Args&&... symbols)
        // {
        //     symbol = symbols;
        // }

        explicit Quote(std::string _symbol)
            : symbol{_symbol}
        {}

        std::string symbol{};

        auto getHistory(std::string interval = "15m", std::string range = "1d")
        {
            const std::string api_url = std::format("{}/{}?interval={}&range={}", 
            QUERY_YAHOO_URL, symbol, interval, range);
            
            constexpr auto header_title = "User-Agent";
            constexpr auto header_text  = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36";

            cpr::Response r = cpr::Get(cpr::Url{api_url}, cpr::Header{{header_title, header_text}});

            nlohmann::json data = nlohmann::json::parse(r.text);
            data = data["chart"]["result"][0]["indicators"]["quote"][0]["close"];

            return data.get<std::vector<float>>();
        }

    private:
        //[[nodiscard]] nlohmann::json get_json_data
    

        struct test { int x{}; int y{}; int z{}; int w{}; };

    private:
        //array of something
        //std::array<int, N> something{};
    };


    //=========================================================================
	// CTAD
	//=========================================================================
    // template<typename... Args>
    // Quote(Args...)
    // -> Quote< sizeof...(Args) >;
}