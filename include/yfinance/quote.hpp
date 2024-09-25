#pragma once

#include <concepts>

namespace farra::yf
{
    template<typename... Args>
    concept all_types_convertible = std::conjunction_v<std::is_convertible<Args, std::string>...>;

    static inline constexpr auto QUERY_YAHOO_URL = "https://query1.finance.yahoo.com/v8/finance/chart"; 

    template<std::size_t N>
    struct Quote
    {
        template<all_types_convertible... Args>
        explicit Quote(Args&&... symbols){}

    private:
        //array of something
        std::array<int, N> something{};
    };


    //=========================================================================
	// CTAD
	//=========================================================================
    template<typename... Args>
    Quote(Args...)
    -> Quote< sizeof...(Args) >;
}