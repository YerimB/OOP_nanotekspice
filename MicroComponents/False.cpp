/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** False
*/

#include "False.hpp"

nts::False::False(const std::string &name) :
Component::Component(name)
{
    this->_pins.push_back(std::make_shared<Pin>(true, 1, "false"));

    this->_pins[0]->setState(nts::FALSE);
}

nts::Tristate nts::False::compute(const std::size_t &pin)
{
    this->_pins[0]->setState(this->_pins[0]->getState());

    return this->_pins[0]->getState();
}