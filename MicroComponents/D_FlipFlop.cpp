/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** D_FlipFlop
*/

#include "D_FlipFlop.hpp"

nts::D_FlipFlop::D_FlipFlop(const std::string &name, const std::array<uint, 6> &pins) :
Component(name)
{
    this->_pins.push_back(std::make_shared<Pin>(true, pins[0], "Q"));
    this->_pins.push_back(std::make_shared<Pin>(true, pins[1], "QB"));
    this->_pins.push_back(std::make_shared<Pin>(false, pins[2], "Clock", nts::UNDEFINED, true));
    this->_pins.push_back(std::make_shared<Pin>(false, pins[3], "Reset"));
    this->_pins.push_back(std::make_shared<Pin>(false, pins[4], "Data"));
    this->_pins.push_back(std::make_shared<Pin>(false, pins[5], "Set"));
}

nts::Tristate nts::D_FlipFlop::compute(const std::size_t &pin)
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
    if (this->_pins.at(3)->getState() != nts::FALSE or this->_pins.at(5)->getState() != nts::FALSE) {
        this->_pins.at(0)->setState(this->_pins.at(5)->getState());
        this->_pins.at(1)->setState(this->_pins.at(3)->getState());
        return aPin.getState();
    }
    if (this->_pins.at(4)->getState() == nts::UNDEFINED) {
        this->_pins.at(0)->setState();
        this->_pins.at(1)->setState();
    } else if (this->_pins.at(2)->getState() == nts::TRUE
    && this->_pins.at(2)->getPrevState() == nts::FALSE) {
        this->_pins.at(0)->setState((this->_pins.at(4)->getState() == nts::TRUE) ? nts::TRUE : nts::FALSE);
        this->_pins.at(1)->setState((this->_pins.at(4)->getState() == nts::TRUE) ? nts::FALSE : nts::TRUE);
    }
    return aPin.getState();
}