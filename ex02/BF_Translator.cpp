/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-clement.muth
** File description:
** BF_Translator
*/

#include "BF_Translator.hpp"

BF_Translator::BF_Translator() noexcept
{
    _commands['-'] = &BF_Translator::memoryDown;
    _commands[','] = &BF_Translator::readMemory;
    _commands['.'] = &BF_Translator::writeMemory;
    _commands['['] = &BF_Translator::loopMemory;
    _commands[']'] = &BF_Translator::backFile;
    _commands['+'] = &BF_Translator::memoryUp;
    _commands['<'] = &BF_Translator::cursorDown;
    _commands['>'] = &BF_Translator::cursorUp;
}

int BF_Translator::translate(std::string const& in, std::string const& out) noexcept
{
    try {
        bf_command command;
        char c;

        _in.open(in.data(), std::ios::in);
        _out.open(out.data(), std::ios::trunc | std::ios::out);
        if (!_in.is_open() || !_out.is_open()) throw std::exception();
        fileHeader();
        while (!_in.eof()) {
            c = _in.get();
            command = _commands[c];
            if (command) (this->*command)();
            else if (!isspace(c) && c != -1) throw std::exception();
        }
        fileFooter();
        CLOSE_ALL(_in, _out);
    } catch (std::exception& e) {
        CLOSE_ALL(_in, _out);
        return (-1);
    }
    return (0);
}