/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4081
*/

#include "C4081.hpp"

nts::C4081::C4081(const std::string &name) :
nts::Component::Component(name)
{
    this->_gates.push_back(std::make_shared<And>("AndGate 1", 1, 2, 3));
    this->_gates.push_back(std::make_shared<And>("AndGate 2", 5, 6, 4));
    this->_gates.push_back(std::make_shared<And>("AndGate 3", 8, 9, 10));
    this->_gates.push_back(std::make_shared<And>("AndGate 4", 12, 13, 11));
}

nts::Tristate nts::C4081::compute(const std::size_t &pin)
{
    if (pin < 1 or pin > 13 or pin == 7)
        throw PinException("C4081", "Pin " + std::to_string(pin) + " don't exist.");
    return (this->getGateFromPinValue(pin).compute(pin));
}