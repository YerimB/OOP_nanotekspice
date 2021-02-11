/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Not
*/

#include "Not.hpp"

nts::Not::Not(const std::string &name, const uint &nbI, const uint &nbO) :
nts::Component::Component(name)
{
    this->_pins.push_back(std::make_shared<Pin>(false, nbI, "In"));
    this->_pins.push_back(std::make_shared<Pin>(true, nbO, "Out"));
}

nts::Tristate nts::Not::compute(const std::size_t &pin)
{
    auto &aPin = this->getPin(pin);
    auto &links = aPin.getLinks();

    if (links.size() != 0 && !aPin.isOutput()) {
        links.begin()->second->compute(links.begin()->first);
        return aPin.getState();
    } else if (aPin.isOutput()) {
        this->compute(this->_pins.at(0)->getId());
        if (this->_pins.at(0)->getState() == nts::UNDEFINED)
            aPin.setState();
        else
            aPin.setState((this->_pins.at(0)->getState() == nts::TRUE) ? nts::FALSE : nts::TRUE);
    }
    return (aPin.getState());
}