/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4069
*/

#ifndef C4069_HPP_
#define C4069_HPP_

#include "Component.hpp"
#include "../MicroComponents/Not.hpp"

namespace nts {
    class C4069 : public Component {
        public:
            C4069(const std::string &name = "Inverter Circuit");

            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}

#endif /* !C4069_HPP_ */