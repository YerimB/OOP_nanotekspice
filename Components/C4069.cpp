/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4069
*/

#include "C4069.hpp"

nts::C4069::C4069(const std::string &name) :
nts::Component::Component(name)
{
    this->_gates.push_back(std::make_shared<Not>("Gate Not 1", 1, 2));
    this->_gates.push_back(std::make_shared<Not>("Gate Not 2", 3, 4));
    this->_gates.push_back(std::make_shared<Not>("Gate Not 3", 5, 6));
    this->_gates.push_back(std::make_shared<Not>("Gate Not 4", 9, 8));
    this->_gates.push_back(std::make_shared<Not>("Gate Not 5", 11, 10));
    this->_gates.push_back(std::make_shared<Not>("Gate Not 6", 13, 12));
}

nts::Tristate nts::C4069::compute(const std::size_t &pin)
{
    if (pin < 1 or pin == 7 or pin > 13)
        throw PinException("C4069", "Pin " + std::to_string(pin) + " doesn't exist.");
    return (this->getGateFromPinValue(pin).compute(pin));
}