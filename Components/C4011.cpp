/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4011
*/

#include "C4011.hpp"

nts::C4011::C4011(const std::string &name) :
nts::Component::Component(name)
{
    this->_gates.push_back(std::make_shared<And>("AndGate 1", 1, 2, 0));
    this->_gates.push_back(std::make_shared<And>("AndGate 2", 5, 6, 0));
    this->_gates.push_back(std::make_shared<And>("AndGate 3", 8, 9, 0));
    this->_gates.push_back(std::make_shared<And>("AndGate 4", 12, 13, 0));

    this->_gates.push_back(std::make_shared<Not>("NotGate 1", 0, 3));
    this->_gates.push_back(std::make_shared<Not>("NotGate 2", 0, 4));
    this->_gates.push_back(std::make_shared<Not>("NotGate 3", 0, 10));
    this->_gates.push_back(std::make_shared<Not>("NotGate 4", 0, 11));

    this->_gates[4]->getPin(0).addLink(0, this->_gates[0]);
    this->_gates[5]->getPin(0).addLink(0, this->_gates[1]);
    this->_gates[6]->getPin(0).addLink(0, this->_gates[2]);
    this->_gates[7]->getPin(0).addLink(0, this->_gates[3]);

    this->_gates[0]->getPin(0).addLink(0, this->_gates[4]);
    this->_gates[1]->getPin(0).addLink(0, this->_gates[5]);
    this->_gates[2]->getPin(0).addLink(0, this->_gates[6]);
    this->_gates[3]->getPin(0).addLink(0, this->_gates[7]);
}

nts::Tristate nts::C4011::compute(const std::size_t &pin)
{
    if (pin < 1 or pin == 7 or pin > 13) {
        std::cerr << "Pin is out of range or not computable (ex: 7)." << std::endl;
        std::exit(84);
    }
    return (this->getGateFromPinValue(pin).compute(pin));
}