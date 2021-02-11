/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Adder
*/

#ifndef ADDER_HPP_
#define ADDER_HPP_

#include "../Exceptions/Exceptions.hpp"
#include "../Components/Component.hpp"
#include "../Components/Pin.hpp"

namespace nts {
    class Adder : public Component {
        public:
            Adder(const std::string &name = "2-in ADDER Gate", \
            uint nbA = 1, uint nbB = 2, uint nbO = 3);
            ~Adder() = default;

        public:
            nts::Tristate compute(const std::size_t &pin = 1);
    };
}

#endif /* !ADDER_HPP_ */
