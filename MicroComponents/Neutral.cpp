/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Neutral
*/

#include "Neutral.hpp"

nts::Neutral::Neutral(const std::string &name, const uint &nbI, const uint &nbO) :
Component::Component(name)
{
    this->_pins.push_back(std::make_shared<Pin>(false, nbI, "Input"));
    this->_pins.push_back(std::make_shared<Pin>(true, nbO, "Output"));
}

nts::Tristate nts::Neutral::compute(const std::size_t &pin)
{
    auto aPin = this->getPin(pin);
    auto links = aPin.getLinks();

    if (links.size() != 0 && !aPin.isOutput()) {
        links.begin()->second->compute(links.begin()->first);
        return aPin.getState();
    } else if (!aPin.isOutput())
        return aPin.getState();
    for (auto &elem : this->_pins)
        if (!elem->isOutput())
            this->compute(elem->getId());
    this->_pins[1]->setState(this->_pins[0]->getState());
    return aPin.getState();
}