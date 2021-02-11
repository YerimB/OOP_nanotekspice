/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4094
*/

#ifndef C4094_HPP_
#define C4094_HPP_

#include "Component.hpp"

namespace nts {
    class C4094 : public Component {
        public:
            C4094(const std::string &name = "8-Bit shifter");

        public:
            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}

#endif /* !C4094_HPP_ */
