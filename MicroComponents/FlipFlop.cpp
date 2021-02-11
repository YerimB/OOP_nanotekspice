/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** FlipFlop
*/

#include "FlipFlop.hpp"

nts::FlipFlop::FlipFlop(const std::string &name, const std::array<uint, 4> &pins) :
Component::Component(name)
{
    this->_pins.push_back(std::make_shared<Pin>(true, pins[0], "Q-" + name, nts::UNDEFINED));
    this->_pins.push_back(std::make_shared<Pin>(true, pins[1], "QB-" + name));
    this->_pins.push_back(std::make_shared<Pin>(false, pins[2], "Clock-" + name, nts::UNDEFINED, true));
    this->_pins.push_back(std::make_shared<Pin>(false, pins[3], "Reset-" + name));
}

nts::Tristate nts::FlipFlop::compute(const std::size_t &pin)
{
    auto &aPin = this->getPin(pin);
    auto &links = aPin.getLinks();

    if (links.size() != 0 && !aPin.isOutput()) {
        links.begin()->second->compute(links.begin()->first);
        return aPin.getState();
    } else if (!aPin.isOutput())
        return aPin.getState();
    for (auto &elem : this->_pins)
        if (!elem->isOutput())
            this->compute(elem->getId());
    if (this->_pins.at(3)->getState() != nts::FALSE) {
        this->_pins.at(0)->setState((this->_pins.at(3)->getState() == nts::TRUE) ? nts::FALSE : nts::UNDEFINED);
        this->_pins.at(2)->setState();
        // this->_pins.at(1)->setState((this->_pins.at(3)->getState() == nts::TRUE) ? nts::FALSE : nts::UNDEFINED);
    } else if (this->_pins.at(2)->getState() == nts::FALSE && \
    this->_pins.at(2)->getPrevState() == nts::TRUE) {
        std::cout << "Flipping output from " << this->getName() << std::endl;
        this->_pins.at(0)->setState((this->_pins.at(0)->getState() == nts::FALSE) ? nts::TRUE : nts::FALSE);
        // this->_pins.at(1)->setState((this->_pins.at(0)->getState() == nts::FALSE) ? nts::TRUE : nts::FALSE);
    }
    std::cout << "-> GATE: " << this->getName() << std::endl;
    std::cout << "Actual = " << this->_pins.at(2)->getState() << ", previous = " << this->_pins.at(2)->getPrevState() << std::endl;
    return aPin.getState();
}