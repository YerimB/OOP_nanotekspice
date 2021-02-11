/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4512
*/

#ifndef C4512_HPP_
#define C4512_HPP_

#include "Component.hpp"

namespace nts
{
    class C4512 : public Component {
        public:
            C4512(const std::string &name = "8-ch Data Selector");

            nts::Tristate compute(const std::size_t &pin = 1) final;
    };
}

#endif /* !C4512_HPP_ */
