/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <array>
#include <memory>
#include <cmath>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        FALSE = false,
        TRUE = true,
    };

    class Pin;

    class IComponent
    {
        public:
            virtual ~IComponent() = default;

        public:
            virtual nts::Tristate compute(const std::size_t &pin = 1) = 0;
            virtual void addLink(const std::size_t &thisPin, const std::shared_ptr<IComponent> &thisComponent,
                const std::shared_ptr<nts::IComponent> &otherComponent, const std::size_t &otherPin) = 0;
            virtual nts::Pin &getPin(const std::size_t &value) = 0;
            virtual nts::Pin &getPin(const std::string &name) = 0;
            virtual void dump() const = 0;
            virtual const std::string &getName() const = 0;
            virtual nts::IComponent &getGateFromPinValue(const std::size_t &) = 0;
            virtual const bool &isComputed(void) = 0;
            virtual void setComputed(const bool &state) = 0;
            virtual void updateComponent(void) = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */