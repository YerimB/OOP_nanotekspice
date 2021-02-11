/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Not
*/

#ifndef NOT_HPP_
#define NOT_HPP_

#include "../Exceptions/Exceptions.hpp"
#include "../Components/Component.hpp"
#include "../Components/Pin.hpp"

namespace nts {
    class Not : public Component {
        public:
            Not(const std::string &name = "Pin Inverter - (NOT Gate)", \
            const uint &nbI = 0, const uint &nbO = 1);
            ~Not() = default;

        public:
            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}

#endif /* !NOT_HPP_ */
