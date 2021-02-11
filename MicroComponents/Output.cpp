/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output
*/

#include "Output.hpp"

nts::Output::Output(const std::string &name) :
Component::Component(name)
{
    this->_pins.push_back(std::make_shared<Pin>(false, 1, "output"));
}

nts::Tristate nts::Output::compute(const std::size_t &pin)
{
    auto links = this->_pins[0]->getLinks();

    if (links.size() != 0)
        links.begin()->second->compute(links.begin()->first);
    return this->_pins[0]->getState();
}