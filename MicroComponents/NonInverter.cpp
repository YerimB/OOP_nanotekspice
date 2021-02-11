/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NonInverter
*/

#include "NonInverter.hpp"

nts::NonInverter::NonInverter(const std::string &name, \
const uint &nbA, const uint &nbB, const uint &nbO) :
Component::Component(name)
{
    this->_pins.push_back(std::make_shared<Pin>(false, nbA, "Input"));
    this->_pins.push_back(std::make_shared<Pin>(false, nbB, "Disable"));
    this->_pins.push_back(std::make_shared<Pin>(true, nbO, "Output"));
}

nts::Tristate nts::NonInverter::compute(const std::size_t &pin)
{
    auto aPin = this->getPin(pin);
    auto links = aPin.getLinks();

    if (links.size() != 0 && !aPin.isOutput()) {
        links.begin()->second->compute(links.begin()->first);
        return aPin.getState();
    } else if (!aPin.isOutput())
        return aPin.getState();
    if (aPin.isOutput()) {
        for (auto &elem : this->_pins)
            if (!elem->isOutput())
                this->compute(elem->getId());
    }
    if (this->_pins[1]->getState() != nts::FALSE)
        this->_pins[2]->setState();
    else
        this->_pins[2]->setState(this->_pins[0]->getState());
    return aPin.getState();
}