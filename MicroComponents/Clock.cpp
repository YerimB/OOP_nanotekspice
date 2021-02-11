/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock
*/

#include "Clock.hpp"

nts::Clock::Clock(const std::string &name) :
Component::Component(name)
{
    this->_pins.push_back(std::make_shared<Pin>(true, 1, "clock", nts::UNDEFINED, true));
}

nts::Tristate nts::Clock::compute(const std::size_t &pin)
{
    this->_pins[0]->setState(this->_pins[0]->getState());
    return this->_pins[0]->getState();
}

void nts::Clock::updateComponent(void)
{
    this->getPin(1).updateClockState();
}