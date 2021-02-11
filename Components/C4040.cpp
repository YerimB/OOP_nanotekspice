/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4040
*/

#include "C4040.hpp"

nts::C4040::C4040(const std::string &name) :
nts::Component::Component(name)
{
    this->_gates.push_back(std::make_shared<Neutral>("Reset", 11, 40));

    this->_gates.push_back(std::make_shared<FlipFlop>("FF1", std::array<uint, 4>({9, 41, 10, 81})));
    this->_gates.push_back(std::make_shared<FlipFlop>("FF2", std::array<uint, 4>({7, 42, 62, 82})));
    this->_gates.push_back(std::make_shared<FlipFlop>("FF3", std::array<uint, 4>({6, 43, 63, 83})));
    this->_gates.push_back(std::make_shared<FlipFlop>("FF4", std::array<uint, 4>({5, 44, 64, 84})));
    this->_gates.push_back(std::make_shared<FlipFlop>("FF5", std::array<uint, 4>({3, 45, 65, 85})));
    this->_gates.push_back(std::make_shared<FlipFlop>("FF6", std::array<uint, 4>({2, 46, 66, 86})));
    this->_gates.push_back(std::make_shared<FlipFlop>("FF7", std::array<uint, 4>({4, 47, 67, 87})));
    this->_gates.push_back(std::make_shared<FlipFlop>("FF8", std::array<uint, 4>({13, 48, 68, 88})));
    this->_gates.push_back(std::make_shared<FlipFlop>("FF9", std::array<uint, 4>({12, 49, 69, 89})));
    this->_gates.push_back(std::make_shared<FlipFlop>("FF10", std::array<uint, 4>({14, 50, 70, 90})));
    this->_gates.push_back(std::make_shared<FlipFlop>("FF11", std::array<uint, 4>({15, 51, 71, 91})));
    this->_gates.push_back(std::make_shared<FlipFlop>("FF12", std::array<uint, 4>({1, 52, 72, 92})));

    // Reset
    this->_gates[0]->getPin(40).addLink(81, this->_gates[1]);
    this->_gates[0]->getPin(40).addLink(82, this->_gates[2]);
    this->_gates[0]->getPin(40).addLink(83, this->_gates[3]);
    this->_gates[0]->getPin(40).addLink(84, this->_gates[4]);
    this->_gates[0]->getPin(40).addLink(85, this->_gates[5]);
    this->_gates[0]->getPin(40).addLink(86, this->_gates[6]);
    this->_gates[0]->getPin(40).addLink(87, this->_gates[7]);
    this->_gates[0]->getPin(40).addLink(88, this->_gates[8]);
    this->_gates[0]->getPin(40).addLink(89, this->_gates[9]);
    this->_gates[0]->getPin(40).addLink(90, this->_gates[10]);
    this->_gates[0]->getPin(40).addLink(91, this->_gates[11]);
    this->_gates[0]->getPin(40).addLink(92, this->_gates[12]);

    this->_gates[1]->getPin(81).addLink(40, this->_gates[0]);
    this->_gates[2]->getPin(82).addLink(40, this->_gates[0]);
    this->_gates[3]->getPin(83).addLink(40, this->_gates[0]);
    this->_gates[4]->getPin(84).addLink(40, this->_gates[0]);
    this->_gates[5]->getPin(85).addLink(40, this->_gates[0]);
    this->_gates[6]->getPin(86).addLink(40, this->_gates[0]);
    this->_gates[7]->getPin(87).addLink(40, this->_gates[0]);
    this->_gates[8]->getPin(88).addLink(40, this->_gates[0]);
    this->_gates[9]->getPin(89).addLink(40, this->_gates[0]);
    this->_gates[10]->getPin(90).addLink(40, this->_gates[0]);
    this->_gates[11]->getPin(91).addLink(40, this->_gates[0]);
    this->_gates[12]->getPin(92).addLink(40, this->_gates[0]);

    // Gates links
    this->_gates[1]->getPin(9).addLink(62, this->_gates[2]);
    this->_gates[2]->getPin(7).addLink(63, this->_gates[3]);
    this->_gates[3]->getPin(6).addLink(64, this->_gates[4]);
    this->_gates[4]->getPin(5).addLink(65, this->_gates[5]);
    this->_gates[5]->getPin(3).addLink(66, this->_gates[6]);
    this->_gates[6]->getPin(2).addLink(67, this->_gates[7]);
    this->_gates[7]->getPin(4).addLink(68, this->_gates[8]);
    this->_gates[8]->getPin(13).addLink(69, this->_gates[9]);
    this->_gates[9]->getPin(12).addLink(70, this->_gates[10]);
    this->_gates[10]->getPin(14).addLink(71, this->_gates[11]);
    this->_gates[11]->getPin(15).addLink(72, this->_gates[12]);

    this->_gates[2]->getPin(62).addLink(9, this->_gates[1]);
    this->_gates[3]->getPin(63).addLink(7, this->_gates[2]);
    this->_gates[4]->getPin(64).addLink(6, this->_gates[3]);
    this->_gates[5]->getPin(65).addLink(5, this->_gates[4]);
    this->_gates[6]->getPin(66).addLink(3, this->_gates[5]);
    this->_gates[7]->getPin(67).addLink(2, this->_gates[6]);
    this->_gates[8]->getPin(68).addLink(4, this->_gates[7]);
    this->_gates[9]->getPin(69).addLink(13, this->_gates[8]);
    this->_gates[10]->getPin(70).addLink(12, this->_gates[9]);
    this->_gates[11]->getPin(71).addLink(14, this->_gates[10]);
    this->_gates[12]->getPin(72).addLink(15, this->_gates[11]);
}

nts::Tristate nts::C4040::compute(const std::size_t &pin)
{
    if (pin < 1 or pin == 8 or pin > 15)
        throw PinException("C4040", "Pin " + std::to_string(pin) + " doesn't exist.");
    if (this->isComputed())
        return (this->getPin(pin).getState());
    this->setComputed(true);
    return (this->getGateFromPinValue(1).compute(1));
}