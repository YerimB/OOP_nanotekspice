/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4040
*/

#ifndef C4040_HPP_
#define C4040_HPP_

#include "../MicroComponents/Neutral.hpp"
#include "../MicroComponents/FlipFlop.hpp"

namespace nts {
    class C4040 : public Component {
        public:
            C4040(const std::string &name = "12-bit Binary Counter");

            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}

#endif /* !C4040_HPP_ */
