/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4503
*/

#include "C4503.hpp"

nts::C4503::C4503(const std::string &name):
nts::Component::Component(name)
{
    this->_gates.push_back(std::make_shared<Neutral>("Disable-4", 1, 40));
    this->_gates.push_back(std::make_shared<NonInverter>("NonInverter Gate 1", 2, 51, 3));
    this->_gates.push_back(std::make_shared<NonInverter>("NonInverter Gate 2", 4, 52, 5));
    this->_gates.push_back(std::make_shared<NonInverter>("NonInverter Gate 3", 6, 53, 7));
    this->_gates.push_back(std::make_shared<NonInverter>("NonInverter Gate 4", 10, 54, 9));

    this->_gates.push_back(std::make_shared<Neutral>("Disable-2", 15, 41));
    this->_gates.push_back(std::make_shared<NonInverter>("NonInverter Gate 5", 12, 55, 11));
    this->_gates.push_back(std::make_shared<NonInverter>("NonInverter Gate 6", 14, 56, 13));

    this->_gates[0]->getPin(40).addLink(51, this->_gates[1]);
    this->_gates[0]->getPin(40).addLink(52, this->_gates[2]);
    this->_gates[0]->getPin(40).addLink(53, this->_gates[3]);
    this->_gates[0]->getPin(40).addLink(54, this->_gates[4]);

    this->_gates[1]->getPin(51).addLink(40, this->_gates[0]);
    this->_gates[2]->getPin(52).addLink(40, this->_gates[0]);
    this->_gates[3]->getPin(53).addLink(40, this->_gates[0]);
    this->_gates[4]->getPin(54).addLink(40, this->_gates[0]);

    this->_gates[5]->getPin(41).addLink(55, this->_gates[6]);
    this->_gates[5]->getPin(41).addLink(56, this->_gates[7]);

    this->_gates[6]->getPin(55).addLink(41, this->_gates[5]);
    this->_gates[7]->getPin(56).addLink(41, this->_gates[5]);
}

nts::Tristate nts::C4503::compute(const std::size_t &pin)
{
    if (pin < 1 or pin == 8 or pin > 15)
        throw PinException("C4503", "Pin " + std::to_string(pin) + " doesn't exist.");
    return (this->getGateFromPinValue(pin).compute(pin));
}
