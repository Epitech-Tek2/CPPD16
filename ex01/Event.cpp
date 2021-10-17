/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-clement.muth
** File description:
** Event
*/

#include "Event.hpp"

Event::Event() noexcept :
    _time{0} {}

Event::Event(unsigned int time, std::string const& event) noexcept :
    _time{time}, _event{event} {}

Event::Event(Event const& other) noexcept
{
    _event = other._event;
    _time = other._time;
}

Event& Event::operator=(Event const& rhs) noexcept
{
    _time = rhs._time;
    _event = rhs._event;
    return (*this);
}

unsigned int Event::getTime() const noexcept
{
    return (_time);
}

std::string const& Event::getEvent() const noexcept
{
    return (_event);
}

void Event::setTime(unsigned int time) noexcept
{
    _time = time;
}

void Event::setEvent(std::string const& event) noexcept
{
    _event = event;
}