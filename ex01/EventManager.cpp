/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-clement.muth
** File description:
** EventManager
*/

#include "EventManager.hpp"

EventManager::EventManager() noexcept :
    _time{0} {}

EventManager::~EventManager()
{
    _events.clear();
}

EventManager::EventManager(EventManager const& other) noexcept :
    _events{other._events} {}

EventManager& EventManager::operator=(EventManager const&rhs) noexcept
{
    _events = rhs._events;
    return (*this);
}

void EventManager::addEvent(Event const& event) noexcept
{
    for (std::list<Event>::const_iterator i = _events.begin(); i != _events.end(); i++)
        if (event.getTime() < i->getTime()) {
            _events.insert(i, event);
            return;
        }
    _events.push_back(event);
}

void EventManager::removeEventsAt(unsigned int time) noexcept
{
    for (std::list<Event>::iterator i = _events.begin(); _events.end() != i; i++)
        if (i->getTime() == time) {
            i = _events.erase(i);
            i--;
        }
}

void EventManager::dumpEvents() const noexcept
{
    for (std::list<Event>::const_iterator i = _events.begin(); _events.end() != i; i++)
        cOut(i->getTime() << ": " << i->getEvent());
}

void EventManager::dumpEventAt(unsigned int time) const noexcept
{
    for (std::list<Event>::const_iterator i = _events.begin(); _events.end() != i; i++)
        if (i->getTime() == time) cOut(i->getTime() << ": " << i->getEvent());
}

void EventManager::addTime(unsigned int time) noexcept
{
    unsigned int prev = _time;

    _time += time;
    for (std::list<Event>::const_iterator i = _events.begin(); i != _events.end(); i++)
        if (i->getTime() <= _time && i->getTime() >= prev) {
            cOut(i->getEvent());
            i = _events.erase(i);
            i--;
        }
}

void EventManager::addEventList(std::list<Event> const& events) noexcept
{
    for (std::list<Event>::const_iterator i = events.begin(); events.end() != i; i++)
        if (i->getTime() > _time) addEvent((*i));
}

unsigned int EventManager::getTime() const noexcept
{
    return (_time);
}

std::list<Event> EventManager::getEvent() const noexcept
{
    return (_events);
}