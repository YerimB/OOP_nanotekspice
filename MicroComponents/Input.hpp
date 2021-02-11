/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Input
*/

#ifndef Input_HPP_
#define Input_HPP_

#include "../Exceptions/Exceptions.hpp"
#include "../Components/Component.hpp"
#include "../Components/Pin.hpp"

namespace nts {
    class Input : public Component {
        public:
            Input(const std::string &name = "Input");
            ~Input() = default;

        public:
            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}


#endif /* !Input_HPP_ */
