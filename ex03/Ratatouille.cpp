/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-clement.muth
** File description:
** Ratatouille
*/

#include "Ratatouille.hpp"

#define assign(value) ({ \
    _stream << value; \
    return (*this); \
})

Ratatouille::Ratatouille(Ratatouille const& source) noexcept
{
    _stream << source._stream.str();
}

Ratatouille& Ratatouille::addCondiment(unsigned int condiment) noexcept
{
    assign(condiment);
}

Ratatouille& Ratatouille::addSauce(std::string const& sauce) noexcept
{
    assign(sauce);
}

Ratatouille& Ratatouille::addSpice(double spices) noexcept
{
    assign(spices);
}

Ratatouille& Ratatouille::addVegetable(unsigned char vegetable) noexcept
{
    assign(vegetable);
}

std::string Ratatouille::kooc() noexcept
{
    return (_stream.str());
}

Ratatouille& Ratatouille::operator=(Ratatouille& source) noexcept
{
    _stream.str("");
    _stream << source._stream.str();
    return (*this);
}