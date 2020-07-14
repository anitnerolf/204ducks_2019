//
// EPITECH PROJECT, 2020
// Ducks
// File description:
// 204
//

#include "../include/my.hpp"

Ducks::Ducks()
{
}

Ducks::~Ducks()
{
}

void	Ducks::usage(void)
{
    std::cout << "USAGE\n\t./204ducks a\n\nDESCRIPTION" << std::endl;
    std::cout << "\ta\tconstant" << std::endl;
}

int     Ducks::check_if_number(std::string str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if ((str[i] <= 57 && str[i] >= 48) || str[i] == '.')
	    j = 1;
        else
            j = -1;
        i++;
    }
    return j;
}


double	Ducks::calculate(double a, double t)
{
    double calc = a * exp(-t) + (4 - 3 * a) * exp(-2 * t) + (2 * a - 4) * exp(-4 * t);
    return (calc);
}

double	Ducks::calculateNegative(double a, double t)
{
    double calc = -a * exp(-t) - (4 - 3 * a) / 2 * exp(-2 * t) - (2 * a - 4) / 4 * exp(-4 * t);
    return (calc);
}

double	Ducks::getAverageReturnTime(double t, double a)
{
    double result = 0;
    for ( ; t < 100; t = t + 0.0001)
	result = result + this->calculate(a, t) * t / 10000;
    return result;
}

double	Ducks::getStandardDeviation(double t, double a, double res)
{
    double result = 0;
    for ( ; t < 100; t = t + 0.0001)
	result = result + pow(t - res, 2) * this->calculate(a, t) / 10000;
    return sqrt(result);
}

double	Ducks::getReturnTime(double t, double a, double percentage)
{
    double calc = 0;
    for ( ; t < 1000; t = t + 0.01)
    {
	calc = this->calculateNegative(a, t / 60) - this->calculateNegative(a, 0);
    	if (calc >= percentage)
    	    return (t);
    }
    return 0;
}

double	Ducks::getPercentage(double t, double a)
{
    double calc = 0;
    calc = this->calculateNegative(a, t) - this->calculateNegative(a, 0);
    return (calc);
}

void	Ducks::print_values(double a)
{
    std::cout << "Average return time: " << (int)this->getAverageReturnTime(0, a) << "m " << ceil((this->getAverageReturnTime(0, a) - (int)this->getAverageReturnTime(0, a)) * 60) << "s" << std::endl;
    std::cout << "Standard deviation: "<< std::fixed << std::setprecision(3) <<this->getStandardDeviation(0, a, this->getAverageReturnTime(0, a)) << std::endl;
    double five = this->getReturnTime(0.0, a, 0.5);
    double nine = this->getReturnTime(0.0, a, 0.99);
    std::cout << "Time after which 50% of the ducks are back: "<< (int)five / 60 << "m " << (int)fmod(five, 60) / 10 << (int)fmod(five, 10) << "s" << std::endl;
    std::cout << "Time after which 99% of the ducks are back: "<< (int)nine / 60 << "m " << (int)fmod(nine, 60) / 10 << (int)fmod(nine, 10) << "s" << std::endl;
    std::cout << "Percentage of ducks back after 1 minute: " << std::fixed << std::setprecision(1) << this->getPercentage(1, a) * 100 << "%" << std::endl;
    std::cout << "Percentage of ducks back after 2 minutes: " << std::fixed << std::setprecision(1) << this->getPercentage(2, a) * 100 << "%" << std::endl;
}
