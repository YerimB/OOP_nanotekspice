/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NonInverter
*/

#ifndef NONINVERTER_HPP_
#define NONINVERTER_HPP_

#include "../Exceptions/Exceptions.hpp"
#include "../Components/Component.hpp"
#include "../Components/Pin.hpp"

namespace nts {
    class NonInverter : public Component {
        public:
            NonInverter(const std::string &name = "Non Inverting Gate", \
            const uint &nbA = 1, const uint &nbB = 2, const uint &nbO = 3);
            ~NonInverter() = default;

        public:
            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}

#endif /* !NONINVERTER_HPP_ */
