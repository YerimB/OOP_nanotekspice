/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** True
*/

#include "True.hpp"

nts::True::True(const std::string &name) :
Component::Component(name)
{
    this->_pins.push_back(std::make_shared<Pin>(true, 1, "true"));

    this->_pins[0]->setState(nts::TRUE);
}

nts::Tristate nts::True::compute(const std::size_t &pin)
{
    this->_pins[0]->setState(this->_pins[0]->getState());

    return this->_pins[0]->getState();
}