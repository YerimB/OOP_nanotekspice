/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4008
*/

#include "C4008.hpp"

nts::C4008::C4008(const std::string &name) :
nts::Component::Component(name)
{
    this->_gates.push_back(std::make_shared<Adder>("AdderGate 1", 7, 6, 10));
    this->_gates.push_back(std::make_shared<Adder>("AdderGate 2", 5, 4, 11));
    this->_gates.push_back(std::make_shared<Adder>("AdderGate 3", 3, 2, 12));
    this->_gates.push_back(std::make_shared<Adder>("AdderGate 4", 1, 15, 13));

    this->_gates[0]->getPin("C-In").setId(9);
    this->_gates[3]->getPin("C-Out").setId(14);

    this->_gates[0]->getPin(41).addLink(40, this->_gates[1]);
    this->_gates[1]->getPin(41).addLink(40, this->_gates[2]);
    this->_gates[2]->getPin(41).addLink(40, this->_gates[3]);

    this->_gates[1]->getPin(40).addLink(41, this->_gates[0]);
    this->_gates[2]->getPin(40).addLink(41, this->_gates[1]);
    this->_gates[3]->getPin(40).addLink(41, this->_gates[2]);
}

nts::Tristate nts::C4008::compute(const std::size_t &pin)
{
    if (pin < 1 or pin == 8 or pin > 15)
        throw PinException("C4008", "Pin " + std::to_string(pin) + " doesn't exist.");
    return (this->getGateFromPinValue(pin).compute(pin));
}
