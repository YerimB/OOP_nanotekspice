/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4011
*/

#ifndef C4011_HPP_
#define C4011_HPP_

#include "Component.hpp"
#include "../MicroComponents/And.hpp"
#include "../MicroComponents/Not.hpp"

namespace nts {
    class C4011 : public Component {
        public:
            C4011(const std::string &name = "Quad 2-in NAND");

            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}
#endif
