/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include "../Track.hpp"
#include "../Exceptions/Exceptions.hpp"

namespace nts {
	class Parser {
		public:
			Parser() = default;
			~Parser();

			void CreateCircuit(const std::unique_ptr<nts::Track> &track, const std::string &file);

			inline std::map <std::string, std::string> GetComponents() const { return this->_components; };
			inline std::map <std::string, std::string> GetLinks() const { return this->_links; };

		private:
			void ReadFile(const std::string &file);
			void ParseLine(const std::string &line);

			std::map <std::string, std::string> _components;
			std::map <std::string, std::string> _links;

			// Regex
			const std::string _regexSection = "^[ \\t]*(.chipsets:|.links:)[ \\t]*$";
			const std::string _regexChipset = "^[ \\t]*([a-zA-Z0-9]*)[ \\t]+([a-zA-Z0-9]*)[ \\t]*$";
			const std::string _regexLink = "^[ \\t]*([A-Za-z0-9]*:[0-9]*)[ \\t]+([A-Za-z0-9]*:[0-9]*)[ \\t]*$";
			const std::string _regexComment = "^[ \\t]*(#.*)[ \\t]*$";

			bool _hasChipset = false;
			bool _hasLink = false;
	};
}
#endif /* !PARSER_HPP_ */
