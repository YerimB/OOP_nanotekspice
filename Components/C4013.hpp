/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4013
*/

#ifndef C4013_HPP_
#define C4013_HPP_

#include "Component.hpp"
#include "../MicroComponents/D_FlipFlop.hpp"

namespace nts
{
    class C4013 : public Component {
        public:
            C4013(const std::string &name = "Dual D-Type Flip/Flop");

            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}

#endif /* !C4013_HPP_ */