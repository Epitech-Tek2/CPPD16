/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-clement.muth
** File description:
** DomesticKoala
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction& action) noexcept :
    _action(action), _knowAction(256) {}

DomesticKoala::DomesticKoala(DomesticKoala const& other) noexcept :
    _action(other._action), _knowAction(other._knowAction) {}

DomesticKoala& DomesticKoala::operator=(DomesticKoala const& other) noexcept
{
    _action = other._action;
    _knowAction = other._knowAction;
    return (*this);
}

std::vector<DomesticKoala::methodPointer_t> const *DomesticKoala::getActions() const noexcept
{
    return (&_knowAction);
}

void DomesticKoala::learnAction(unsigned char command, methodPointer_t action)
{
    _knowAction[command] = action;
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    _knowAction[command] = nullptr;
}

void DomesticKoala::doAction(unsigned char command, std::string const& param)
{
    methodPointer_t func = _knowAction[command];

    if (func) (_action.*func)(param);
}

void DomesticKoala::setKoalaAction(KoalaAction& action)
{
    _action = action;
}