/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Track
*/

#include "Track.hpp"

std::map<std::string, uint> components {
    { "4001", 4001 }, { "4008", 4008 },
    { "4011", 4011 }, { "4013", 4013 },
    { "4030", 4030 }, { "4040", 4040 },
    { "4069", 4069 }, { "4071", 4071 },
    { "4081", 4081 }, { "4094", 4094 },
    { "4503", 4503 }, { "4512", 4512 },
    { "4514", 4514 }, { "output", 0 },
    { "input", 1 }, { "true", 2 },
    { "false", 3 }, { "clock", 4}
};

const bool nts::Track::addSingleVar(const std::string &name, const int &val)
{
    if (name.empty() or val < 0 or val > 1)
        return (false);
    _avs.insert({name, static_cast<nts::Tristate>(val)});
    return (true);
}

const bool nts::Track::openFileGetAvs(char **av)
{
    std::string tmp(av[1]);
    size_t cPos = 0;

    if ((cPos = tmp.find('.')) == std::string::npos or tmp.substr(cPos) != ".nts")
        return (false);
    for (uint idx = 2; av[idx]; ++idx) {
        tmp = av[idx];
        if ((cPos = tmp.find('=')) == std::string::npos or (cPos + 1) == tmp.length() or\
        !this->addSingleVar(tmp.substr(0, cPos), std::stoi(tmp.substr(cPos + 1)))) {
            return (false);
        }
    }
    return (true);
}

void nts::Track::createComponent(const std::string &type, const std::string &name)
{
    if (components.find(type) == components.end())
        throw NanoTekSpiceException("Track", "Component " + type + " doesn't exist.");
    switch (components[type])
    {
        case 0:
            this->_components.push_back(std::make_shared<Output>(name)); break;
        case 1:
            this->_components.push_back(std::make_shared<Input>(name)); break;
        case 2:
            this->_components.push_back(std::make_shared<True>(name)); break;
        case 3:
            this->_components.push_back(std::make_shared<False>(name)); break;
        case 4:
            this->_components.push_back(std::make_shared<Clock>(name)); break;
        case 4001:
            this->_components.push_back(std::make_shared<C4001>(name)); break;
        case 4008:
            this->_components.push_back(std::make_shared<C4008>(name)); break;
        case 4011:
            this->_components.push_back(std::make_shared<C4011>(name)); break;
        case 4013:
            this->_components.push_back(std::make_shared<C4013>(name)); break;
        case 4030:
            this->_components.push_back(std::make_shared<C4030>(name)); break;
        case 4040:
            this->_components.push_back(std::make_shared<C4040>(name)); break;
        case 4069:
            this->_components.push_back(std::make_shared<C4069>(name)); break;
        case 4071:
            this->_components.push_back(std::make_shared<C4071>(name)); break;
        case 4081:
            this->_components.push_back(std::make_shared<C4081>(name)); break;
        case 4094:
            this->_components.push_back(std::make_shared<C4094>(name)); break;
        case 4503:
            this->_components.push_back(std::make_shared<C4503>(name)); break;
        case 4512:
            this->_components.push_back(std::make_shared<C4512>(name)); break;
        case 4514:
            this->_components.push_back(std::make_shared<C4514>(name)); break;
        default:
            throw NanoTekSpiceException("Track", "No such component.");
    }
}

const std::shared_ptr<nts::IComponent> &nts::Track::getComponentByName(const std::string &name)
{
    for (const auto &component : this->_components) {
        if (component->getName() == name)
            return component;
    }
    throw NanoTekSpiceException("Track", "Component not found.");
}

void const nts::Track::UpdateClocks() const
{
    for (const auto &component : this->_components) {
        try {
            component->updateComponent();
        }
        catch (const NanoTekSpiceException &e){
            std::cerr << "\e[31m[" << e.GetComponent() << "]\e[0m " << e.what() << std::endl;
            std::exit(84);
        }
    }
}

void nts::Track::ResetComputed()
{
    for (const auto &component : this->_components) {
        if (component->isComputed()) {
            (*component).setComputed(false);
        }
    }
}

nts::Track::~Track()
{
    this->_components.clear();
    this->_avs.clear();
}