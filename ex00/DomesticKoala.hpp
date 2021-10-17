/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-clement.muth
** File description:
** DomesticKoala
*/

#pragma once

#include <iostream>
#include <vector>

#include "KoalaAction.hpp"

class DomesticKoala {
    public:
        typedef void (KoalaAction::*methodPointer_t)(std::string const& action);

        DomesticKoala (KoalaAction &) noexcept;
        DomesticKoala ( const DomesticKoala &) noexcept;
        ~DomesticKoala() = default;

        DomesticKoala & operator =(const DomesticKoala &) noexcept;
        std::vector<methodPointer_t> const *getActions() const noexcept;
        void learnAction ( unsigned char command , methodPointer_t action );
        void unlearnAction ( unsigned char command);
        void doAction ( unsigned char command , const std :: string & param);
        void setKoalaAction ( KoalaAction &);

    private:
        KoalaAction _action;
        std::vector<methodPointer_t> _knowAction;
};