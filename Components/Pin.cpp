/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Pin
*/

#include "Pin.hpp"

nts::Pin::Pin(const bool &isOutput, const uint &id, const std::string &name, \
const nts::Tristate &state, const bool &isClock) :
_isOutput(isOutput), _state(state), _name(name), _id(id), \
_isClock(isClock), _prevState(nts::UNDEFINED) {}

nts::Pin::Pin(const Pin &other) :
_isOutput(other._isOutput), _id(other._id), _isClock(other._isClock)
{
    this->_links = other._links;
    this->_name = other._name;
    this->_prevState = other._prevState;
    this->_state = other._state;
}

void nts::Pin::setState(const nts::Tristate &state, const bool &updateLinks)
{
    if (this->_isClock and this->_state != state) {
        if (state == nts::UNDEFINED)
            this->_prevState = nts::UNDEFINED;
        else
            this->_prevState = this->_state;
    }
    if (this->_isOutput and this->_links.size() != 0 and updateLinks) {
        for (auto &elem : this->_links)
            elem.second->getPin(elem.first).setState(state);
    }
    this->_state = state;
}

void nts::Pin::addLink(const uint &pin, const std::shared_ptr<nts::IComponent> &other)
{
    if (!this->_isOutput and this->_links.size() != 0)
        throw PinException("Pin::addLink", "Cannot link more than one pin to an input.");
    this->_links.insert({pin, other});
}

void nts::Pin::updateClockState(void)
{
    this->_prevState = this->_state;
    this->_state = ((this->_state == nts::TRUE) ? nts::FALSE : nts::TRUE);
    if (this->_isOutput and this->_links.size() != 0) {
        for (auto &elem : this->_links)
            elem.second->getPin(elem.first).setState(_state);
    }
}

nts::Pin::~Pin() {}