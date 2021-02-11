/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** 4001
*/

#ifndef C4001_HPP_
#define C4001_HPP_

#include "../MicroComponents/Or.hpp"
#include "../MicroComponents/Not.hpp"

namespace nts {
    class C4001 : public Component {
        public:
            C4001(const std::string &name = "Quad 2-in NOR");

        public:
            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}

#endif