/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-clement.muth
** File description:
** Event
*/

#pragma once

#include <iostream>

class Event {
    public:
        Event() noexcept;
        Event(unsigned int time, std::string const& event) noexcept;
        Event(Event const& other) noexcept;
        ~Event() = default;

        Event& operator=(Event const& rhs) noexcept;

        unsigned int getTime() const noexcept;
        std::string const& getEvent() const noexcept;
        void setTime(unsigned int time) noexcept;
        void setEvent(std::string const& event) noexcept;

    private:
        unsigned int _time;
        std::string _event;
};