/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4008
*/

#ifndef C4008_HPP_
#define C4008_HPP_

#include "../MicroComponents/Adder.hpp"

namespace nts {
    class C4008 : public Component {
        public:
            C4008(const std::string &name = "4-bit Full Adder CO");

        public:
            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}

#endif