/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Track
*/

#ifndef TRACK_HPP_
#define TRACK_HPP_

#include <map>
#include <vector>
#include <csignal>

#include "MicroComponents/Output.hpp"
#include "MicroComponents/Input.hpp"
#include "MicroComponents/True.hpp"
#include "MicroComponents/False.hpp"
#include "MicroComponents/Clock.hpp"
#include "MicroComponents/FlipFlop.hpp"

#include "Components/Component.hpp"
#include "Components/C4001.hpp"
#include "Components/C4008.hpp"
#include "Components/C4011.hpp"
#include "Components/C4013.hpp"
#include "Components/C4030.hpp"
#include "Components/C4040.hpp"
#include "Components/C4069.hpp"
#include "Components/C4071.hpp"
#include "Components/C4081.hpp"
#include "Components/C4094.hpp"
#include "Components/C4503.hpp"
#include "Components/C4512.hpp"
#include "Components/C4514.hpp"

namespace nts
{
    class Track {
        public:
            Track() = default;
            ~Track();
            const bool addSingleVar(const std::string &, const int &);
            const bool openFileGetAvs(char **av);
            void createComponent(const std::string &type, const std::string &name);
            const std::shared_ptr<IComponent> &getComponentByName(const std::string &);
            const void UpdateClocks() const;
            void ResetComputed();

            inline const std::vector<std::shared_ptr<IComponent>> &getComponents() const { return this->_components; };
            inline const std::map<std::string, nts::Tristate> &getAvs() const { return this->_avs; };

        protected:
        private:
            std::vector<std::shared_ptr<IComponent>> _components;
            std::map<std::string, nts::Tristate> _avs;
    };
}

#endif /* !TRACK_HPP_ */