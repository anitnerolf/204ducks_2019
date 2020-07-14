/*
** EPITECH PROJECT, 2020
** asdfgn
** File description:
** dfgh
*/

#ifndef MY_HPP_
#define MY_HPP_

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
#include <limits>
#include <utility>

class	Ducks
{
public:
    Ducks();
    ~Ducks();
    void	usage(void);
    int check_if_number(std::string str);
    void	print_values(double a);
    double	calculate(double a, double t);
    double	calculateNegative(double a, double t);
    double	getAverageReturnTime(double t, double a);
    double	getStandardDeviation(double t, double a, double res);
    double	getReturnTime(double t, double a, double percentage);
    double	getPercentage(double t, double a);
};

#endif /* MY_HPP_ */
