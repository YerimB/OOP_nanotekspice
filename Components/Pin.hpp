/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Pin
*/

#ifndef PIN_H_
#define PIN_H_

#include "IComponent.hpp"
#include "../Exceptions/Exceptions.hpp"

namespace nts
{
    class Pin {
        public:
            Pin(const bool &isOutput, const uint &id, const std::string & = "Unnamed",\
            const nts::Tristate & = nts::UNDEFINED, const bool & = false);
            Pin(const nts::Pin &);
            ~Pin();

        public:
            inline const nts::Tristate &getState() const { return this->_state; };
            inline const nts::Tristate &getPrevState(void) const { return this->_prevState; };
            inline const std::string &getName() const { return this->_name; };
            inline const auto &getLinks() const { return this->_links; };
            inline const uint &getId(void) const { return this->_id; };

        public:
            inline void setName(const std::string &name) { this->_name = name; };
            inline const bool isClock(void) const { return (this->_isClock); };
            inline const bool isOutput(void) const { return (this->_isOutput); };

        public:
            void setState(const nts::Tristate &state = nts::UNDEFINED, const bool &updateLinks = true);
            void addLink(const uint &, const std::shared_ptr<nts::IComponent> &);
            inline void setId(const uint &id) { this->_id = id; };
            void updateClockState(void);

        private:
            const bool _isOutput;
            nts::Tristate _state;
            std::string _name;
            uint _id;
            const bool _isClock;
            nts::Tristate _prevState;
            std::map<uint, std::shared_ptr<nts::IComponent>> _links;
    };
}

#endif /* !PIN_HPP_ */