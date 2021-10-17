/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-clement.muth
** File description:
** Parser
*/

#pragma once

#include <iostream>
#include <string>
#include <stack>

#define isNumber(ope) ((ope >= '0' && ope <= '9') ? (true) : (false))
#define operator(ope) ((ope == '+' || ope == '-' || ope == '*' || ope == '/' || ope == '%' || ope == '(') ? (true) : (false))
#define topPop(tmp, out) ({\
    tmp = out.top();\
    out.pop();\
})
#define dispatchOpe(tmpf, tmps) ((_tmp.top() == '+') ? (_out.push(tmps + tmpf)) : \
(_tmp.top() == '-') ? (_out.push(tmps - tmpf)) : \
(_tmp.top() == '*') ? (_out.push(tmps * tmpf)) : \
(_tmp.top() == '/') ? (_out.push(tmps / tmpf)) : \
(_tmp.top() == '%') ? (_out.push(tmps % tmpf)) : (void)0)
#define FEED_PROCESS ({ \
    topPop(tmpF, _out); \
    topPop(tmpS, _out); \
    dispatchOpe(tmpF, tmpS); \
    _tmp.pop(); \
})

class Parser {
    public:
        Parser() noexcept;
        Parser(Parser const& source) noexcept;
        virtual ~Parser() = default;

        int result() const noexcept;
        void feed(std::string const& feed) noexcept;
        void reset() noexcept;

        Parser& operator=(Parser const& parser) noexcept;

    protected:
        std::stack<int> _tmp;
        std::stack<int> _out;
        int _result;
};