#include "Exceptions.hpp"

nts::NanoTekSpiceException::NanoTekSpiceException(const std::string &component, const std::string &message) :
_component(component), _message(message) {}

nts::ParserException::ParserException(const std::string &component, const std::string &message) :
NanoTekSpiceException(component, message) {}

nts::PinException::PinException(const std::string &component, const std::string &message) :
NanoTekSpiceException(component, message) {}