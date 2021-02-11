/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** FlipFlop
*/

#ifndef FLIPFLOP_HPP_
#define FLIPFLOP_HPP_

#include "../Components/Component.hpp"

namespace nts {
    class FlipFlop : public Component {
        public:
            FlipFlop(const std::string &name, const std::array<uint, 4> &pins);
            ~FlipFlop() = default;

            nts::Tristate compute(const std::size_t &pin) final;
    };
}

#endif /* !FLIPFLOP_HPP_ */