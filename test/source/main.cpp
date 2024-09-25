// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

// #include <doctest/doctest.h>

#include <gtest/gtest.h>
#include <greeter/greeter.h>
#include <greeter/version.h>

TEST(TestCategory, TestName) 
{
    using namespace greeter;

    Greeter greeter("Tests");

    EXPECT_EQ(greeter.greet(LanguageCode::EN), "Hello, Tests!");
    EXPECT_EQ(greeter.greet(LanguageCode::DE), "Hallo Tests!");
    EXPECT_EQ(greeter.greet(LanguageCode::ES), "¡Hola Tests!");
    EXPECT_EQ(greeter.greet(LanguageCode::FR), "Bonjour Tests!");
}

TEST(TestCategory, TestVersion) 
{
	static_assert(std::string_view(GREETER_VERSION) == std::string_view("1.0"));
  	EXPECT_EQ(std::string(GREETER_VERSION), std::string("1.0"));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
