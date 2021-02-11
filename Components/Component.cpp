/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Component
*/

#include "Component.hpp"

nts::Component::Component(const std::string &name) :
_name(name), _computed(false) {}

nts::Tristate nts::Component::compute(const std::size_t &pin)
{
    return this->_pins.at(pin - 1)->getState();
}

void nts::Component::addLink(const std::size_t &thisPin,  const std::shared_ptr<nts::IComponent> &thisComponent,
const std::shared_ptr<nts::IComponent> &otherComponent, const std::size_t &otherPin)
{
    try {
        this->getPin(thisPin).addLink(otherPin, otherComponent);
        otherComponent->getPin(otherPin).addLink(thisPin, thisComponent);
    } catch (const PinException &e) {
        std::cerr << "\e[31m[" << e.GetComponent() << "]\e[0m " << e.what() << std::endl;
        std::exit(84);
    }
}

nts::Pin &nts::Component::getPin(const std::size_t &value)
{
    for (auto &elem : this->_pins)
        if (elem->getId() == value)
            return (*elem);
    for (auto &gate : this->_gates) {
        for (auto &pin : gate->_pins)
            if (pin->getId() == value)
                return (*pin);
    }
    throw PinException("Component", "Pin not found.");
}

nts::Pin &nts::Component::getPin(const std::string &name)
{
    for (auto &elem : this->_pins)
        if (elem->getName() == name)
            return (*elem);
    for (auto &gate : this->_gates) {
        for (auto &pin : gate->_pins)
            if (pin->getName() == name)
                return (*pin);
    }
    throw PinException("Component", "Pin not found.");
}

nts::Component &nts::Component::getGateFromPinValue(const std::size_t &value)
{
    for (auto &elem : this->_gates) {
        for (auto &pin : elem->_pins)
            if (pin->getId() == value)
                return (*elem);
    }
    throw PinException("Component", "Component not found."); // Component not found
}

void nts::Component::dump(void) const
{
    std::cout << "\e[34mComponent\e[0m <\e[32m" << this->getName() << "\e[0m>" << std::endl;
    for (const auto &pin : this->_pins) {
        std::cout << std::fixed << std::right << std::setw(26)
                  << "\e[36mPin\e[0m \e[32m" << pin->getName()
                  << "\e[0m ↦ " << "[" << pin->getState() << "]";
        if (pin->isClock())
            std::cout << ", \e[36mPrevious State\e[0m ➜ [" << pin->getPrevState() << "]";
        std::cout << std::endl;
        if (pin->getLinks().size() != 0) {
            for (auto &elem : pin->getLinks())
                std::cout << std::fixed << std::right << std::setw(38)
                          << " \e[95mLinked to:\e[0m <\e[32m" << elem.second->getName()
                          << "\e[0m> \e[32m" << elem.second->getPin(elem.first).getName() << "\e[0m ⇋ \e[32m"
                          << pin->getName() << "\e[0m";
            std::cout << std::endl;
        }
        
    }
    if (this->_gates.size() != 0) {
        for (const auto &elem : this->_gates) {
            std::cout << std::fixed << std::right << std::setw(28);
            elem->dump();
        }
    }
    std::cout << std::endl;
}

const int nts::Component::latch(const std::vector<std::shared_ptr<Pin> > &bins) const
{
    int ret = 0;
    int tpow = 0;

    for (auto &elem : bins) {
        if (elem->getState() == nts::UNDEFINED) {
            ret = (-1);
            break;
        }
        ret += ((elem->getState() == nts::TRUE) ? (std::pow(2, tpow)) : 0);
        tpow++;
    }
    return (ret);
}

nts::Component::~Component()
{
    this->_pins.clear();
    this->_gates.clear();
}