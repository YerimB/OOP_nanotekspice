/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Shell
*/

#include "Shell.hpp"


nts::Shell::Shell()
{
    _commands.insert({ "display", 0 });
    _commands.insert({ "dump", 1 });
    _commands.insert({ "simulate", 2 });
    _commands.insert({ "loop", 3 });
}

bool nts::Shell::TryParse(const std::string &line, const std::unique_ptr<nts::Track> &track)
{
    if (line.find("=") == std::string::npos)
        return false;

    std::string name = line.substr(0, line.find("="));
    std::string value = line.substr(line.find("="), line.length());
    value.replace(0, 1, "");

    try {
        auto component = track->getComponentByName(name);

        if (component->getPin(1).getName() != "input")
            throw NanoTekSpiceException("Parser", "You can only change inputs value.");

        if (value != "0" && value != "1")
            throw NanoTekSpiceException("Parser", "Invalid Tristate value.");

        component->getPin(1).setState(static_cast<Tristate>(std::stoi(value)));
    } catch (const PinException &e) {
        std::cerr << "\e[31m[" << e.GetComponent() << "]\e[0m " << e.what() << std::endl;
        std::exit(84);
    } catch (const NanoTekSpiceException &e) {
        std::cerr << "\e[31m[" << e.GetComponent() << "]\e[0m " << e.what() << std::endl;
        std::exit(84);
    }
    return true;
}

void nts::Shell::ParseLine(const std::string &line, const std::unique_ptr<nts::Track> &track)
{
    std::regex re(this->_commandRegex);
    std::smatch match;

    if (std::regex_match(line, match, re) && match.size() > 1) {
        switch (_commands[match[1]]) {
            case 0:
                this->DisplayCircuit(track); break;
            case 1:
                this->DumpCircuit(track); break;
            case 2:
                this->SimulateCircuit(track); break;
            case 3:
                this->LoopCircuit(track); break;
            default:
                break;
        }
    } else {
        if (!this->TryParse(line, track)) {
            std::cerr << "\e[31m[Error]\e[0m Invalid command '" << line << "'." << std::endl;
        }
    }
}

void nts::Shell::DisplayShell(const std::unique_ptr<nts::Track> &track)
{
    std::string line;

    this->SimulateCircuit(track);
    this->DisplayCircuit(track);
    std::cout << "> ";
    while (std::getline(std::cin, line)) {
        if (line.find("exit") != std::string::npos) {
            break;
        } else {
            this->ParseLine(line, track);
        }
        std::cout << "> ";
    }
}

void nts::Shell::DisplayCircuit(const std::unique_ptr<nts::Track> &track)
{
    for (const auto &component : track->getComponents()) {
        if (component == nullptr)
            continue;
        try {
            const auto &outputComponent = component->getPin("output");
            if (outputComponent.getName() == "output") {
                std::cout << component->getName() << "="
                << ((outputComponent.getState() == nts::UNDEFINED) ? "U" : std::to_string(outputComponent.getState()))
                << std::endl;
            }
        }
        catch (...) { continue; }
    }
}

void nts::Shell::DumpCircuit(const std::unique_ptr<nts::Track> &track)
{
    for (const auto &component : track->getComponents()) {
        if (component != nullptr)
            component->dump();
    }
}

void nts::Shell::SimulateCircuit(const std::unique_ptr<nts::Track> &track)
{
    for (auto &component : track->getComponents()) {
        try {
            if (component->getPin(1).getName() == "output") {
                component->compute(1);
            }
        } catch (const PinException &e) {
            continue;
        } catch (const NanoTekSpiceException &e) {
            std::cerr << "\e[31m[" << e.GetComponent() << "]\e[0m " << e.what() << std::endl;
            std::exit(84);
        }
    }
    track->UpdateClocks();
    track->ResetComputed();
}

void nts::Shell::LoopCircuit(const std::unique_ptr<nts::Track> &track)
{
    this->_loop = true;

    while (this->_loop) {
        this->SimulateCircuit(track);
    }
}