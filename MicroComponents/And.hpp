/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** And
*/

#ifndef AND_HPP_
#define AND_HPP_

#include "../Exceptions/Exceptions.hpp"
#include "../Components/Component.hpp"
#include "../Components/Pin.hpp"

namespace nts {
    class And : public Component {
        public:
            And(const std::string &name = "2-in AND Gate", uint nbA = 1, \
            uint nbB = 2, uint nbO = 3);
            ~And() = default;

        public:
            nts::Tristate compute(const std::size_t &pin = 1);
    };
}

#endif /* !AND_HPP_ */
