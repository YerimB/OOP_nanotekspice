/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** 4071
*/

#ifndef C4071_HPP_
#define C4071_HPP_

#include "../MicroComponents/Or.hpp"

namespace nts {
    class C4071 : public nts::Component {
        public:
            C4071(const std::string &name = "Quad 2-in OR");

        public:
            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}

#endif