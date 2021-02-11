/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Xor
*/

#ifndef XOR_HPP_
#define XOR_HPP_

#include "../Exceptions/Exceptions.hpp"
#include "../Components/Component.hpp"
#include "../Components/Pin.hpp"

namespace nts {
    class Xor : public Component {
        public:
            Xor(const std::string &name = "2-in OR Gate", uint nbA = 1, \
            uint nbB = 2, uint nbO = 3);
            ~Xor() = default;

        public:
            nts::Tristate compute(const std::size_t &pin = 1);
    };
}

#endif /* !XOR_HPP_ */