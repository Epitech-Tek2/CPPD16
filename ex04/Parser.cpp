/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-clement.muth
** File description:
** Parser
*/

#include "Parser.hpp"
#include <sstream>

Parser::Parser() noexcept :
    _result{0} {}

Parser::Parser(Parser const& source) noexcept :
    _tmp{source._tmp}, _out{source._out}, _result{source._result} {}

int Parser::result() const noexcept
{
    return (_result);
}

void Parser::feed(std::string const& operation) noexcept
{
    std::string tmp;
    int tmpF;
    int tmpS;

    for (unsigned int i{0}; i < operation.size();) {
        tmp.clear();
        if (isNumber(operation[i])) {
            while (isNumber(operation[i])) tmp += operation[i++];
            std::stringstream(tmp) >> tmpF;
            _out.push(tmpF);
        } else if (operator(operation[i])) {
            _tmp.push(operation[i]);
            i++;
        } else if (operation[i] == ')') {
            i++;
            while (_tmp.top() != '(') FEED_PROCESS;
            _tmp.pop();
        } else i++;
    }
    while (!_tmp.empty()) FEED_PROCESS;
    _result += _out.top();
    _out.pop();
}

Parser& Parser::operator=(Parser const& parser) noexcept
{
    _tmp = parser._tmp;
    _out = parser._out;
    _result = parser._result;
    return (*this);
}

void Parser::reset() noexcept
{
    std::stack<int> clear;

    _tmp = clear;
    _out = clear;
    _result = 0;
}