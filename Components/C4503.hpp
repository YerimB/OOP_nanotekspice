/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4503
*/

#ifndef C4503_HPP_
#define C4503_HPP_

#include "../MicroComponents/Neutral.hpp"
#include "../MicroComponents/NonInverter.hpp"

namespace nts {
    class C4503 : public Component {
        public:
            C4503(const std::string &name = "Hex NonInvert 3-state Buffer");

        public:
            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}

#endif /* !C4503_HPP_ */