/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** D_FlipFlop
*/

#ifndef D_FLIPFLOP_HPP_
#define D_FLIPFLOP_HPP_

#include "../Components/Component.hpp"

namespace nts {
    class D_FlipFlop : public Component {
        public:
            D_FlipFlop(const std::string &name, const std::array<uint, 6> &pins);
            ~D_FlipFlop() = default;

            nts::Tristate compute(const std::size_t &pin) final;
    };
}

#endif /* !D_FLIPFLOP_HPP_ */
