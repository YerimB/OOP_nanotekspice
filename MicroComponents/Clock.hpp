/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "../Exceptions/Exceptions.hpp"
#include "../Components/Component.hpp"
#include "../Components/Pin.hpp"

namespace nts {
    class Clock : public Component {
        public:
            Clock(const std::string &name = "Clock");
            ~Clock() = default;

        public:
            nts::Tristate compute(const std::size_t &pin = 1) final;
            void updateComponent(void) final;
    };
}

#endif /* !CLOCK_HPP_ */
