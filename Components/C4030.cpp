/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4030
*/

#include "C4030.hpp"

nts::C4030::C4030(const std::string &name) :
nts::Component::Component(name)
{
    this->_gates.push_back(std::make_shared<Xor>("Gate 1", 1, 2, 3));
    this->_gates.push_back(std::make_shared<Xor>("Gate 2", 5, 6, 4));
    this->_gates.push_back(std::make_shared<Xor>("Gate 3", 8, 9, 10));
    this->_gates.push_back(std::make_shared<Xor>("Gate 4", 12, 13, 11));
}

nts::Tristate nts::C4030::compute(const std::size_t &pin)
{
    if (pin < 1 or pin > 13 or pin == 7)
        throw PinException("C4030", "Pin " + std::to_string(pin) + " doesn't exist.");
    return (this->getGateFromPinValue(pin).compute(pin));
}
