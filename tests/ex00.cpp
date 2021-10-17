/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD16-clement.muth
** File description:
** ex00
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <string>
#include "../ex01/Event.hpp"
#include "../ex01/EventManager.hpp"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static std :: list < Event > createTodoList ()
    {
    std :: list < Event > todo ;
    todo . push_front ( Event (19 , "The vengeance of the Koala") ) ;
    todo . push_front ( Event (20 , "The return of the vengeance of the Koala") ) ;
    todo . push_front ( Event (21 , "The come back of the vengeance of the Koala") ) ;
    todo . push_front ( Event (22 , "The sequel to the vengeance.") ) ;
    todo . push_front ( Event (9 , " What the hell do you mean 'this morning' ?!") ) ;
    todo . push_front ( Event (1 , "No, no, you're pushing it now ...") ) ;
    return todo ;
    }

static void populateEvents ( EventManager & em )
    {
    em . addEvent ( Event (10 , "Eat") ) ;
    em . addEvent ( Event (12 , "Finish the exercises") ) ;
    em . addEvent ( Event (12 , "Understand the thing") ) ;
    em . addEvent ( Event (15 , "Set the rights") ) ;
    em . addEvent ( Event (8 , "Ask what the hell a const_iterator is") ) ;
    em . addEvent ( Event (11 , "Wash my hands so that my keyboard doesn't smell like kebab") ) ;
}

Test(ex01, test_ex0, .init=redirect_all_stdout)
{
    EventManager em ;
    populateEvents ( em ) ;
    em . dumpEvents () ;
    std :: cout << "=====" << std :: endl ;
    em . removeEventsAt (12) ;
    em . dumpEvents () ;
    std :: cout << "=====" << std :: endl ;
    em . addTime (10) ;
    std :: cout << "=====" << std :: endl ;
    em . dumpEvents () ;
    std :: cout << "=====" << std :: endl ;
    em . addEventList ( createTodoList () ) ;
    em . dumpEvents () ;
    std :: cout << "=====" << std :: endl ;
    em . dumpEventAt (15) ;
    std :: cout << "=====" << std :: endl ;
    em . addTime (14) ;

    cr_assert_stdout_eq_str("8: Ask what the hell a const_iterator is\n"\
                            "10: Eat\n"\
                            "11: Wash my hands so that my keyboard doesn't smell like kebab\n"\
                            "12: Finish the exercises\n"\
                            "12: Understand the thing\n"\
                            "15: Set the rights\n"\
                            "=====\n"\
                            "8: Ask what the hell a const_iterator is\n"\
                            "10: Eat\n"\
                            "11: Wash my hands so that my keyboard doesn't smell like kebab\n"\
                            "15: Set the rights\n"\
                            "=====\n"\
                            "Ask what the hell a const_iterator is\n"\
                            "Eat\n"\
                            "=====\n"\
                            "11: Wash my hands so that my keyboard doesn't smell like kebab\n"\
                            "15: Set the rights\n"\
                            "=====\n"\
                            "11: Wash my hands so that my keyboard doesn't smell like kebab\n"\
                            "15: Set the rights\n"\
                            "19: The vengeance of the Koala\n"\
                            "20: The return of the vengeance of the Koala\n"\
                            "21: The come back of the vengeance of the Koala\n"\
                            "22: The sequel to the vengeance.\n"\
                            "=====\n"\
                            "15: Set the rights\n"\
                            "=====\n"\
                            "Wash my hands so that my keyboard doesn't smell like kebab\n"\
                            "Set the rights\n"\
                            "The vengeance of the Koala\n"\
                            "The return of the vengeance of the Koala\n"\
                            "The come back of the vengeance of the Koala\n"\
                            "The sequel to the vengeance.\n");
}