/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Parser
*/

#include "Parser.hpp"

void nts::Parser::ReadFile(const std::string &file)
{
    std::ifstream reader(file);
    std::string line;

    if (!reader.is_open())
        exit(84);

    try {
        while (std::getline(reader, line))
        {
            if (line.empty())
                continue;
            this->ParseLine(line);
        }
    } catch (const nts::ParserException &error) {
        std::cout << "Parser [ReadFile]: " << error.what() << std::endl;
        exit(84);
    }
}

void nts::Parser::ParseLine(const std::string &line)
{
    std::smatch match;

    std::regex re(this->_regexChipset);
    if (std::regex_match(line, match, re) && match.size() == 3) {
		if (!this->_hasChipset)
			throw ParserException("Parser", "No chipsets section specified before declaration.");
		this->_components.insert(std::make_pair(match[2], match[1]));
		return;
    }

    re = std::regex(this->_regexLink);
    if (std::regex_match(line, match, re) && match.size() == 3) {
		if (!this->_hasLink)
			throw ParserException("Parser", "No links section specified before declaration.");
		this->_links.insert(std::make_pair(match[2], match[1]));
		return;
    }

    re = std::regex(this->_regexComment);
    if (std::regex_match(line, match, re) && match.size() > 1) {
        return;
    }

    re = std::regex(this->_regexSection);
    if (std::regex_match(line, match, re) && match.size() > 1) {
        if (match[1] == ".chipsets:")
            this->_hasChipset = true;
        else if (match[1] == ".links:")
            this->_hasLink = true;
        return;
    }

    throw nts::ParserException("Parser", "Invalid line format: " + line);
}

void nts::Parser::CreateCircuit(const std::unique_ptr<nts::Track> &track, const std::string &file)
{
    this->ReadFile(file);

    if (!this->_hasChipset || !this->_hasLink) {
        std::cerr << "Missing chipset or link section." << std::endl;
        std::exit(84);
    }

    for (const auto &item : this->GetComponents()) {
        try {
            track->createComponent(item.second, item.first);
        } catch (const NanoTekSpiceException &e) {
            std::cerr << e.GetComponent() << ": " << e.what() << std::endl;
            std::exit(84);
        }
    }

    for (const auto &item : track->getAvs()) {
        for (const auto &component : track->getComponents()) {
            if (item.first == component->getName()){
                component->getPin(1).setState(static_cast<Tristate>(item.second));
                break;
            }
        }
    }

    for (const auto &item : this->GetLinks()) {
        std::string link1_name = item.first.substr(0, item.first.find(":"));
        std::string link1 = item.first.substr(item.first.find(":"), item.first.length());
        link1.replace(0, 1, "");

        std::string link2_name = item.second.substr(0, item.second.find(":"));
        std::string link2 = item.second.substr(item.second.find(":"), item.second.length());
        link2.replace(0, 1, "");

        track->getComponentByName(link1_name)->addLink(std::stoi(link1),
            track->getComponentByName(link1_name),
            track->getComponentByName(link2_name),
            std::stoi(link2));
    }

    for (const auto &component : track->getComponents()) {
        try {
            if (component->getPin(1).getName() == "input" || component->getPin(1).getName() == "clock") {
                if (component->getPin(1).getState() == nts::UNDEFINED) {
                    std::cerr << component->getName() << " is not initialized." << std::endl;
                    std::exit(84);
                }
            }
        } catch (const PinException &e) {}

        try {
            if (component->getPin(1).getName() == "output") {
                if (component->getPin(1).getLinks().size() == 0) {
                    std::cerr << component->getName() << " is not linked." << std::endl;
                    std::exit(84);
                }
            }
        } catch (const PinException &e) {}
    }
}

nts::Parser::~Parser()
{
    this->_components.clear();
    this->_links.clear();
}