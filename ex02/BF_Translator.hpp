/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-clement.muth
** File description:
** BF_Translator
*/

#pragma once

#include <iostream>
#include <fstream>
#include <map>

#define CLOSE_ALL(in, out) ({ \
    in.close(); \
    out.close(); \
})

class BF_Translator {

    typedef void (BF_Translator::*bf_command)();

    public:
        BF_Translator() noexcept;
        virtual ~BF_Translator() = default;

        int translate(std::string const& in, std::string const& out) noexcept;

    protected:
        std::fstream _in;
        std::fstream _out;
        std::map<char, bf_command> _commands;

        void backFile() { _out << "\t}\n"; };
        void cursorDown() { _out << "\tcursor--;\n"; };
        void cursorUp() { _out << "\tcursor++;\n"; };
        void fileFooter() { _out << "}\n"; };
        void fileHeader() { _out << "#include <string.h>\n" << "#include <stdlib.h>\n" << "#include <unistd.h>\n" << "#define MEMORY_MAX 60*1024\n\n"
        << "int main(void)\n" << "{\n" << "\tchar memory[MEMORY_MAX];\n" << "\tint cursor = 0;\n\n"
        << "\tmemset(memory, 0, MEMORY_MAX);\n"; };
        void loopMemory() { _out << "\twhile (memory[cursor]) {\n"; };
        void memoryDown() { _out << "\tmemory[cursor]--;\n"; };
        void memoryUp() { _out << "\tmemory[cursor]++;\n"; };
        void readMemory() { _out << "\tread(0, &memory[cursor], 1);\n"; };
        void writeMemory() { _out << "\twrite(1, &memory[cursor], 1);\n"; };
};
