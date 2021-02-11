/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "../Exceptions/Exceptions.hpp"
#include "../Components/Component.hpp"
#include "../Components/Pin.hpp"

namespace nts {
    class True : public Component {
        public:
            True(const std::string &name = "True");
            ~True() = default;

        public:
            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}

#endif /* !TRUE_HPP_ */
