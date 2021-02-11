/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4512
*/

#include "C4512.hpp"

nts::C4512::C4512(const std::string &name) :
nts::Component::Component(name)
{
    // Inputs X0 -> X7
    for (int i = 1; i <= 9; i += 1) {
        if (i == 8)
            continue;
        this->_pins.push_back(std::make_shared<Pin>(false, i, "Input I" + std::to_string(i)));
    }

    this->_pins.push_back(std::make_shared<Pin>(false, 10, "Inhibit"));
    this->_pins.push_back(std::make_shared<Pin>(false, 11, "Address A"));
    this->_pins.push_back(std::make_shared<Pin>(false, 12, "Address B"));
    this->_pins.push_back(std::make_shared<Pin>(false, 13, "Address C"));
    this->_pins.push_back(std::make_shared<Pin>(true, 14, "Output Z"));
    this->_pins.push_back(std::make_shared<Pin>(false, 15, "OE"));
}

nts::Tristate nts::C4512::compute(const std::size_t &pin)
{
    int inputPinNb = 0;
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

    if (this->_pins.at(13)->getState() == nts::TRUE) {
        this->_pins.at(12)->setState();
        return aPin.getState();
    }
    if (this->_pins.at(8)->getState() == nts::TRUE) {
        this->_pins.at(12)->setState(nts::FALSE);
        this->_pins.at(13)->setState(nts::FALSE);
        return aPin.getState();
    }

    inputPinNb = this->latch(std::vector<std::shared_ptr<Pin> >({_pins[9], _pins[10], _pins[11]}));
    if (inputPinNb == -1)
        this->_pins.at(12)->setState();
    else
        this->_pins.at(12)->setState(this->getPin(inputPinNb).getState());
    return aPin.getState();
}