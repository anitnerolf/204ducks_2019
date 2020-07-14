//
// EPITECH PROJECT, 2020
// sdfg
// File description:
// dfg
//

#include "../include/my.hpp"

int	main(int ac, char **av)
{
    Ducks duck;
    if (ac == 2) {
	if (av[1][0] == '-' && av[1][1] == 'h' && !av[1][2])
	    duck.usage();
	else {
	    if (duck.check_if_number(av[1]) == -1) {
		std::cerr << "First argument must be a number!" << std::endl;
		exit(84);
	    } else {
		if (atof(av[1]) < 0.0 || atof(av[1]) > 2.5) {
		    std::cerr << "Number must be between 0 and 2.5!" << std::endl;
		    exit(84);
		} else {
		    duck.print_values(atof(av[1]));
		}
	    }
	}
    } else
	exit(84);
    return 0;
}
