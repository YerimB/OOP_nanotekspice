/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Neutral
*/

#ifndef NEUTRAL_HPP_
#define NEUTRAL_HPP_

#include "../Exceptions/Exceptions.hpp"
#include "../Components/Component.hpp"
#include "../Components/Pin.hpp"

namespace nts {
    class Neutral : public Component {
        public:
            Neutral(const std::string &name = "Neutral Gate", \
            const uint &nbI = 1, const uint &nbO = 2);
            ~Neutral() = default;

        public:
            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}

#endif /* !NEUTRAL_HPP_ */
