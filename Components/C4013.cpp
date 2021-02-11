/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4013
*/

#include "C4013.hpp"

nts::C4013::C4013(const std::string &name) :
nts::Component::Component(name)
{
    this->_gates.push_back(std::make_shared<D_FlipFlop>("D_FlipFlop 1", std::array<uint, 6>({1, 2, 3, 4, 5, 6})));
    this->_gates.push_back(std::make_shared<D_FlipFlop>("D_FlipFlop 2", std::array<uint, 6>({13, 12, 11, 10, 9, 8})));
}

nts::Tristate nts::C4013::compute(const std::size_t &pin)
{
    if (pin < 1 or pin == 7 or pin > 13) {
        std::cerr << "Pin is out of range or not computable (ex: 7)." << std::endl;
        std::exit(84);
    }
    return (this->getGateFromPinValue(pin).compute(pin));
}