/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "../Exceptions/Exceptions.hpp"
#include "../Components/Component.hpp"
#include "../Components/Pin.hpp"

namespace nts {
    class False : public Component {
        public:
            False(const std::string &name = "False");
            ~False() = default;

        public:
            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}

#endif /* !False_HPP_ */
