/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** And
*/

#include "And.hpp"

nts::And::And(const std::string &name, uint nbA, uint nbB, uint nbO) :
Component::Component(name)
{
    this->_pins.push_back(std::make_shared<Pin>(false, nbA, std::to_string(nbA)));
    this->_pins.push_back(std::make_shared<Pin>(false, nbB, std::to_string(nbB)));
    this->_pins.push_back(std::make_shared<Pin>(true, nbO, std::to_string(nbO)));
}

nts::Tristate nts::And::compute(const std::size_t &pin)
{
    auto aPin = this->getPin(pin);
    auto links = aPin.getLinks();

    if (links.size() != 0 && !aPin.isOutput()) {
        links.begin()->second->compute(links.begin()->first);
        return aPin.getState();
    } else if (aPin.isOutput()) {
        for (auto &elem : this->_pins)
            if (!elem->isOutput())
                this->compute(elem->getId());
    }
    if (this->_pins.at(0)->getState() == nts::FALSE or \
    this->_pins.at(1)->getState() == nts::FALSE)
        this->_pins.at(2)->setState(nts::FALSE);
    else if (this->_pins.at(0)->getState() == nts::UNDEFINED or \
    this->_pins.at(1)->getState() == nts::UNDEFINED)
        this->_pins.at(2)->setState(nts::UNDEFINED);
    else
        this->_pins.at(2)->setState(nts::TRUE);
    return aPin.getState();
}