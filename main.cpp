/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** main
*/

#include "Track.hpp"
#include "Parser/Parser.hpp"
#include "Shell/Shell.hpp"

nts::Shell shell;

void SigIntCallback(int nb)
{
    if (shell.GetLoopState() == true)
        shell.SetLoopState(false);
}

int main(int ac, char **av)
{
    signal(SIGINT, SigIntCallback);

    if (ac == 1)
        return 84;
    nts::Parser parser;
    std::unique_ptr<nts::Track> track = std::make_unique<nts::Track>();

    if (!track->openFileGetAvs(av))
        return 84;
    parser.CreateCircuit(track, av[1]);
    shell.DisplayShell(track);

    return 0;
}