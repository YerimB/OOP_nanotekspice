/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Or
*/

#ifndef OR_HPP_
#define OR_HPP_

#include "../Exceptions/Exceptions.hpp"
#include "../Components/Component.hpp"
#include "../Components/Pin.hpp"

namespace nts {
    class Or : public Component {
        public:
            Or(const std::string &name = "2-in OR Gate", uint nbA = 1, \
            uint nbB = 2, uint nbO = 3);
            ~Or() = default;

        public:
            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}

#endif /* !OR_HPP_ */