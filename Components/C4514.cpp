/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4514
*/

#include "C4514.hpp"

nts::C4514::C4514(const std::string &name) :
nts::Component::Component(name)
{
    // Inputs DATA n
    this->_pins.push_back(std::make_shared<Pin>(false, 1, "Strobe"));
    this->_pins.push_back(std::make_shared<Pin>(false, 2, "nA"));
    this->_pins.push_back(std::make_shared<Pin>(false, 3, "nB"));
    this->_pins.push_back(std::make_shared<Pin>(false, 21, "nC"));
    this->_pins.push_back(std::make_shared<Pin>(false, 22, "nD"));

    // Outputs S(n in [4..20])
    this->_pins.push_back(std::make_shared<Pin>(true, 11, "Output S0"));
    this->_pins.push_back(std::make_shared<Pin>(true, 9, "Output S1"));
    this->_pins.push_back(std::make_shared<Pin>(true, 10, "Output S2"));
    this->_pins.push_back(std::make_shared<Pin>(true, 8, "Output S3"));
    this->_pins.push_back(std::make_shared<Pin>(true, 7, "Output S4"));
    this->_pins.push_back(std::make_shared<Pin>(true, 6, "Output S5"));
    this->_pins.push_back(std::make_shared<Pin>(true, 5, "Output S6"));
    this->_pins.push_back(std::make_shared<Pin>(true, 4, "Output S7"));
    this->_pins.push_back(std::make_shared<Pin>(true, 18, "Output S8"));
    this->_pins.push_back(std::make_shared<Pin>(true, 17, "Output S9"));
    this->_pins.push_back(std::make_shared<Pin>(true, 20, "Output S10"));
    this->_pins.push_back(std::make_shared<Pin>(true, 19, "Output S11"));
    this->_pins.push_back(std::make_shared<Pin>(true, 14, "Output S12"));
    this->_pins.push_back(std::make_shared<Pin>(true, 13, "Output S13"));
    this->_pins.push_back(std::make_shared<Pin>(true, 16, "Output S14"));
    this->_pins.push_back(std::make_shared<Pin>(true, 15, "Output S15"));

    // Specials
    this->_pins.push_back(std::make_shared<Pin>(false, 23, "Inhibit"));
}

nts::Tristate nts::C4514::compute(const std::size_t &pin)
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
    inputPinNb = this->latch(std::vector<std::shared_ptr<Pin> >({_pins[1], _pins[2], _pins[3], _pins[4]}));
    if (inputPinNb == (-1) or this->getPin(23).getState() == nts::UNDEFINED) {
        for (auto &elem : this->_pins)
            if (elem->isOutput())
                elem->setState();
    } else if (this->getPin(23).getState() == nts::TRUE) {
        for (auto &elem : this->_pins)
            if (elem->isOutput())
                elem->setState(nts::FALSE);
    } else {
        for (auto &elem : this->_pins)
            if (elem->isOutput())
                elem->setState((this->_pins.at(0)->getState() == nts::TRUE) ? nts::FALSE : nts::TRUE);
        this->getPin("Output S" + std::to_string(inputPinNb)).setState(this->_pins.at(0)->getState());
    }
    return aPin.getState();
}