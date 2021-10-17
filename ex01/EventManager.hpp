/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-clement.muth
** File description:
** EventManager
*/

#pragma once

#include <list>
#include <iostream>
#include <string>
#include "Event.hpp"

#define cOut(message) std::cout << message << std::endl

class EventManager {
    public:
        EventManager() noexcept;
        EventManager(EventManager const& other) noexcept;
        ~EventManager();

        EventManager& operator=(EventManager const&rhs) noexcept;

        void addEvent(Event const& event) noexcept;
        void removeEventsAt(unsigned int time) noexcept;
        void dumpEvents() const noexcept;
        void dumpEventAt(unsigned int time) const noexcept;
        void addTime(unsigned int time) noexcept;
        void addEventList(std::list<Event> const& events) noexcept;
        unsigned int getTime() const noexcept;
        std::list<Event> getEvent() const noexcept;
        static bool sortList(Event const& event1, Event const& event2) noexcept;

    private:
        unsigned int _time;
        std::list<Event> _events;
};