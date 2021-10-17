
##
## EPITECH PROJECT, 2021
## B-CPP-300-STG-3-1-CPPD10-clement.muth
## File description:
## Makefile
##


tests_run:
	g++  ex01/*.cpp tests/*.cpp -o unit_tests --coverage -lcriterion
	- ./unit_tests

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(EXEC)

re:	fclean all

.PHONY:	clean fclean re all