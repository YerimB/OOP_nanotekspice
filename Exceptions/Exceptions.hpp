/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Exceptions
*/

#ifndef EXCEPTIONS_HPP_
#define EXCEPTIONS_HPP_

#include <exception>
#include <string>

namespace nts {
	class NanoTekSpiceException : public std::exception {
		public:
			NanoTekSpiceException(const std::string &component = "NanoTekSpice",
								 const std::string &message = "Unknown Error.");
			virtual ~NanoTekSpiceException() = default;
			virtual const char *what() const throw() {
				return (this->_message.c_str());
			};

			inline const std::string GetComponent() const { return this->_component; };

		protected:
			const std::string _message;
			const std::string _component;
	};

	class ParserException : public NanoTekSpiceException {
		 public:
			ParserException(const std::string &component, const std::string &message);
	};

	class PinException : public NanoTekSpiceException {
		public:
			PinException(const std::string &component, const std::string &message);
	};
}
#endif /* !EXCEPTIONS_HPP_ */
