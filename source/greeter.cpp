#include <format>
#include <greeter/greeter.h>

using namespace greeter;

Greeter::Greeter(std::string _name) : name(std::move(_name)) {}

std::string Greeter::greet(LanguageCode lang) const {
  switch (lang) {
    default:
    case LanguageCode::EN:
      return std::format("Hello, {}!", name);
    case LanguageCode::DE:
      return std::format("Hallo {}!", name);
    case LanguageCode::ES:
      return std::format("¡Hola {}!", name);
    case LanguageCode::FR:
      return std::format("Bonjour {}!", name);
  }
}
