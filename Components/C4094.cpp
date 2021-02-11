/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4094
*/

#include "C4094.hpp"

nts::C4094::C4094(const std::string &name) :
Component::Component(name)
{
    // Inputs
    this->_pins.push_back(std::make_shared<Pin>(false, 1, "Strobe"));
    this->_pins.push_back(std::make_shared<Pin>(false, 2, "Data"));
    this->_pins.push_back(std::make_shared<Pin>(false, 3, "Clock", nts::UNDEFINED, true));
    this->_pins.push_back(std::make_shared<Pin>(false, 15, "OE"));

    // Outputs
    this->_pins.push_back(std::make_shared<Pin>(true, 4, "Q1"));
    this->_pins.push_back(std::make_shared<Pin>(true, 5, "Q2"));
    this->_pins.push_back(std::make_shared<Pin>(true, 6, "Q3"));
    this->_pins.push_back(std::make_shared<Pin>(true, 7, "Q4"));
    this->_pins.push_back(std::make_shared<Pin>(true, 14, "Q5"));
    this->_pins.push_back(std::make_shared<Pin>(true, 13, "Q6"));
    this->_pins.push_back(std::make_shared<Pin>(true, 12, "Q7"));
    this->_pins.push_back(std::make_shared<Pin>(true, 11, "Q8"));

    this->_pins.push_back(std::make_shared<Pin>(true, 10, "QP-SIGMA"));
    this->_pins.push_back(std::make_shared<Pin>(true, 9, "Q-SIGMA"));
}

nts::Tristate nts::C4094::compute(const std::size_t &pin)
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

    if (this->isComputed())
        return aPin.getState();
    // Actualizing Serial Outputs
    if (this->_pins[2]->getState() == nts::TRUE and \
    this->_pins[2]->getPrevState() == nts::FALSE)
        this->getPin(9).setState(this->getPin(12).getState());
    else if (this->_pins[2]->getState() == nts::FALSE and \
    this->_pins[2]->getPrevState() == nts::TRUE)
        this->getPin(10).setState(this->getPin(12).getState());
    else {
        this->getPin(9).setState();
        this->getPin(10).setState();
    }

    // Actualizing Parallel Outputs
    if (this->getPin(15).getState() != nts::TRUE or this->getPin(1).getState() == nts::UNDEFINED) {
        for (auto &elem : this->_pins)
            if (elem->isOutput() and elem->getId() != 10 and elem->getId() != 9)
                elem->setState();
    } else if (this->getPin(1).getState() == nts::TRUE) {
        if (this->_pins[2]->getState() == nts::TRUE and \
        this->_pins[2]->getPrevState() == nts::FALSE) {
            for (uint idx = 8; idx > 1; --idx)
                this->getPin("Q" + std::to_string(idx)).setState(this->getPin("Q" + std::to_string(idx - 1)).getState());
            this->getPin(4).setState(this->getPin(2).getState());
        }
    }
    this->setComputed(true);
    return aPin.getState();
}