/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <iomanip>

#include "IComponent.hpp"
#include "Pin.hpp"

namespace nts
{
    class Component : public nts::IComponent {
        public:
            Component(const std::string &name);
            ~Component();

        public:
            nts::Tristate compute(const std::size_t &pin = 1) override;
            void addLink(const std::size_t &thisPin, const std::shared_ptr<IComponent> &thisComponent,
                        const std::shared_ptr<nts::IComponent> &otherComponent, const std::size_t &otherPin) override;
            void dump(void) const override;
            const int latch(const std::vector<std::shared_ptr<Pin> > &bins) const;
            nts::Pin &getPin(const std::size_t &value) override;
            nts::Pin &getPin(const std::string &name) override;
            nts::Component &getGateFromPinValue(const std::size_t &) override;
            const std::string &getName() const override { return this->_name; };
            inline const bool &isComputed(void) override { return this->_computed; };
            inline void setComputed(const bool &state) override { this->_computed = state; };
            inline void updateComponent(void) override {};

        protected:
            std::string _name;

        protected:
            std::vector<std::shared_ptr<nts::Pin>> _pins;
            std::vector<std::shared_ptr<Component>> _gates;
            bool _computed;
    };
}

#endif /* !COMPONENT_HPP_ */