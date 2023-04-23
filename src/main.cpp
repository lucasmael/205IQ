/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cmath>

int check_letter(std::string str)
{
    int i = 0;

    while (str[i]) {
        if ((str[i] <= '9' && str[i] >= '0') || str[i] == '.' || str[i] == ',')
            i++;
        else
            return 84;
    }
    return 0;
}

float my_calculation(int u, int o, int i)
{
    double res = 0;

    res = (1 / ((double)o * sqrt(2 * M_PI))) * exp(-0.5 * pow(((double)u - (double)i) / (double)o, 2));
    std::cout << std::setprecision(5);
    printf("%d %.5lf\n", i, res);
    return res;
}

float my_calculation2(int u, int o, int q1, double i)
{
    double res = 0;

    while (i < q1) {
        res = res + (1 / ((double)o * sqrt(2 * M_PI))) * exp(-0.5 * pow(((double)u - (double)i) / (double)o, 2));
        i = i + 0.01;
    }
    return res;
}


float my_calculation3(int u, int o, int q2, double i)
{
    double res = 0;

    while (i < q2) {
        res = res + (1 / ((double)o * sqrt(2 * M_PI))) * exp(-0.5 * pow(((double)u - (double)i) / (double)o, 2));
        i = i + 0.01;
    }
    return res;
}

void case_1(int u, int o)
{
    double r = 0;

    for (int i = 0; i <= 200; i++) {
        my_calculation(u, o, i);
    }
}

void case_2(int u, int o, int q1)
{
    double res = my_calculation2(u, o, q1, 0.0);

    printf("%.1lf%% of people have an IQ inferior to %d", res, q1);
}

void case_3(int u, int o, int q1, int q2)
{
    double res = my_calculation2(u, o , q2, q1);
    printf("%.1lf%% of people have an IQ between %d and %d", res, q1, q2);
}

bool isNumeric(char *str)
{
    bool allow = true;

    for (int i = 0; str[i]; i++)
        if ((str[i] <= '9' && str[i] >= '0'))
            continue;
        else {
            allow = false;
            break;
        }
    return (allow);
}


int main(int ac, char **av)
{
    if (ac == 1) 
    {
        std::cout << "no argument" << std::endl;
        return 84;
    }
    if (strcmp("-h", av[1]) == 0)
    {
        std::cout << "USAGE" << std::endl;
        std::cout << "  ./205IQ u s [IQ1] [IQ2]" << std::endl << std::endl;
        std::cout << "DESCRIPTION" << std::endl;
        std::cout << "     u     mean" << std::endl;
        std::cout << "     s     standard deviation" << std::endl;
        std::cout << "     IQ1   minimum IQ" << std::endl;
        std::cout << "     IQ2   maximum IQ" << std::endl;
        return 0;
    }
    if (ac < 3 || ac > 5)
    {
        std::cerr << "./205IQ -h" << std::endl;
        return 84;
    }
    for (int i = 1; av[i] != NULL; i++)
    {
        if (check_letter(av[i]) == 84)
           return 84;
    }
    if (atoi(av[4]) >= 200) 
    {
        std::cout << "IQ must be between 0 and 200" << std::endl;
        return 84;
    }
    if (ac == 3)
        case_1(atoi(av[1]), atoi(av[2]));
    else if (ac == 4)
    {
        case_2(atoi(av[1]), atoi(av[2]), atoi(av[3]));
    }
    else
    {
        if (atoi(av[4]) < atoi(av[3]))
            return 84;
        case_3(atoi(av[1]), atoi(av[2]), atoi(av[3]), atoi(av[4]));
    }
    return 0;
}
