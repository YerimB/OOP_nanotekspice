/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** 4030
*/

#ifndef C4030_HPP_
#define C4030_HPP_

#include "../MicroComponents/Xor.hpp"

namespace nts {
    class C4030 : public nts::Component {
        public:
            C4030(const std::string &name = "Quad 2-in XOR");

        public:
            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}

#endif