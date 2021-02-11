/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "../Exceptions/Exceptions.hpp"
#include "../Components/Component.hpp"
#include "../Components/Pin.hpp"

namespace nts {
    class Output : public Component {
        public:
            Output(const std::string &name = "Output");
            ~Output() = default;

        public:
            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}


#endif /* !OUTPUT_HPP_ */
