/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-clement.muth
** File description:
** Ratatouille
*/

#pragma once

#include <iostream>
#include <ostream>
#include <sstream>

class Ratatouille {
    public:
        Ratatouille() = default;
        Ratatouille(Ratatouille const& source) noexcept;
        virtual ~Ratatouille() = default;

        Ratatouille& addCondiment(unsigned int condiment) noexcept;
        Ratatouille& addSauce(std::string const& sauce) noexcept;
        Ratatouille& addSpice(double spices) noexcept;
        Ratatouille& addVegetable(unsigned char vegetable) noexcept;

        Ratatouille& operator=(Ratatouille& source) noexcept;

        std::string kooc() noexcept;

    protected:
        std::ostringstream _stream;
};