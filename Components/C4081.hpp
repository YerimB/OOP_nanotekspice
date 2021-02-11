/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4081
*/

#ifndef C4081_HPP_
#define C4081_HPP_

#include "../MicroComponents/And.hpp"

namespace nts
{
    class C4081 : public Component {
        public:
            C4081(const std::string &name = "Quad 2-in AND");

        public:
            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}

#endif /* !C4081_HPP_ */