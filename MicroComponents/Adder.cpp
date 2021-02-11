/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Adder
*/

#include "Adder.hpp"

nts::Adder::Adder(const std::string &name, uint nbA, uint nbB, uint nbO) :
Component::Component(name)
{
    this->_pins.push_back(std::make_shared<Pin>(false, nbA, "A" + std::to_string(nbA)));
    this->_pins.push_back(std::make_shared<Pin>(false, nbB, "B" + std::to_string(nbB)));
    this->_pins.push_back(std::make_shared<Pin>(false, 40, "C-In"));
    this->_pins.push_back(std::make_shared<Pin>(true, 41, "C-Out"));
    this->_pins.push_back(std::make_shared<Pin>(true, nbO, "S" + std::to_string(nbO)));
}

nts::Tristate nts::Adder::compute(const std::size_t &pin)
{
    int prov = 0;
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
    if (this->_pins[0]->getState() == nts::UNDEFINED or \
    this->_pins[1]->getState() == nts::UNDEFINED or this->_pins[2]->getState() == nts::UNDEFINED) {
        this->_pins[3]->setState();
        this->_pins[4]->setState();
    } else {
        prov = this->_pins[0]->getState() + this->_pins[1]->getState() + this->_pins[2]->getState();
        this->_pins[3]->setState(static_cast<nts::Tristate>((prov > 1) ? 1 : 0));
        this->_pins[4]->setState(static_cast<nts::Tristate>(prov % 2));
    }
    return aPin.getState();
}