/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4514
*/

#ifndef C4514_HPP_
#define C4514_HPP_

#include "Component.hpp"

namespace nts {
    class C4514 : public Component {
        public:
            C4514(const std::string &name = "4-to-16 Line Decoders");

        public:
            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}

#endif /* !C4514_HPP_ */