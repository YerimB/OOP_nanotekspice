/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Shell
*/

#ifndef SHELL_HPP_
#define SHELL_HPP_

#include <string>
#include <iostream>
#include <map>
#include <regex>
#include "../Track.hpp"


namespace nts {
    class Shell {
        public:
            Shell();
            ~Shell() = default;
            void DisplayShell(const std::unique_ptr<nts::Track> &);
            void ParseLine(const std::string &, const std::unique_ptr<nts::Track> &);
            void ExecCommand(const std::string &, const std::unique_ptr<nts::Track> &);
            bool TryParse(const std::string &, const std::unique_ptr<nts::Track> &);

            void DisplayCircuit(const std::unique_ptr<nts::Track> &);
            void DumpCircuit(const std::unique_ptr<nts::Track> &);
            void LoopCircuit(const std::unique_ptr<nts::Track> &);
            void SimulateCircuit(const std::unique_ptr<nts::Track> &);

            inline const bool &GetLoopState() const { return this->_loop; };
            inline void SetLoopState(const bool &state) { this->_loop = state; };

            void SigIntCallback(int);
        private:
            bool _loop = false;
            std::map<std::string, uint> _commands;
            const std::string _commandRegex = "^\\s*(display|dump|loop|simulate)\\s*$";
    };
}
#endif /* !SHELL_HPP_ */
