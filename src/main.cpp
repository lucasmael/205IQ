/*
** EPITECH PROJECT, 2019
** Work
** File description:
** main
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <sys/time.h>

double tab[202];

template<typename T>
T getNumberByStr(const std::string & str)
{
    T dat;

    (void)str;
    std::stringstream stream(str);
    stream >> dat;
    (void)str;
    return (dat);
}

bool check_num(char *str)
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

void fact(int o, int u)
{
    for (int i = 0; i < 201; i++) {
        (void)o;
        double res = ((1 / ((double)o * sqrt(2 * M_PI)))
        *
        (exp(-0.5 * pow(((double)i - (double)u) / (double)o, 2))));
        (void)o;
        tab[i] = res * 100;
    }
}

void process3(int u, int o)
{
    fact(o, u);
    std::cout << std::setprecision(5) << std::fixed;
    (void)o;
    for (int i = 0; i < 201; i++)
        std::cout << i << " " << (tab[i] / 100) << std::endl;
    (void)o;
} 

void process1(int u, int o, int q1)
{
    double res = 0;
    int i;

    fact(o, u);
    for (i = 0; i < q1; i++)
        res += tab[i];
    (void)o;
    std::cout << std::setprecision(1) << std::fixed;
    (void)o;
    std::cout << res << "% of people have an IQ inferior to " << q1 << std::endl;
}

void process2(int u, int o, int q1, int q2)
{
    double res = 0;
    int i;

    fact(o, u);
    for (i = q1; i < q2; i++)
        res += tab[i];
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << res << "% of people have an IQ between " << q1 << " and " << q2 << std::endl;
}

int main(int ac, char **av)
{
    int u = 0;
    int o = 0;
    int q1 = 0;
    int q2 = 0;

    if (ac >= 2 && (!strcmp(av[1], "-h") || !strcmp(av[1], "-help"))) {
        std::cout << "USAGE" << std::endl;
        std::cout << "\t" << av[0] << " u s [IQ1] [IQ2]" << std::endl << std::endl;
        std::cout << "DESCRIPTION" << std::endl;
        std::cout << "\tu\tmean" << std::endl;
        std::cout << "\ts\tstandard deviation" << std::endl;
        std::cout << "\tIQ1\tminimum IQ" << std::endl;
        std::cout << "\tIQ2\tmaximum IQ" << std::endl;
        return (0);
    }
    if (ac < 3 || ac > 5) {
        std::cout << "Bad usage." << std::endl;
        return (84);
    }
    if (!check_num(av[1]) || !check_num(av[2])) {
        std::cout << "Bad input." << std::endl;
        return (84);
    }
    try {
        u = getNumberByStr<int>(av[1]);
        o = getNumberByStr<int>(av[2]);
    } catch (std::exception & ex) {
        std::cout << "Bad input." << std::endl;
        return (84);
    }
    if (
        (o <= 0 || o > 200)
        ||
        (u <= 0 || o > 200)
        ){
        std::cout << "Bad input." << std::endl;
        return (84);
    }
    if (ac == 3)
        process3(u, o);
    else if (ac == 4) {
        if (!check_num(av[3])) {
            std::cout << "Bad input." << std::endl;
            return (84);
        }
        try {
            q1 = getNumberByStr<int>(av[3]);
        } catch (std::exception & ex) {
            std::cout << "Bad input." << std::endl;
            return (84);
        }
        if (
            (q1 <= 0 || q1 > 200)){
            std::cout << "Bad input." << std::endl;
            return (84);
        }
        process1(u, o, q1);
    } else {
        if (!check_num(av[3]) || !check_num(av[4])) {
            std::cout << "Bad input." << std::endl;
            return (84);
        }
        try {
            q1 = getNumberByStr<int>(av[3]);
            q2 = getNumberByStr<int>(av[4]);
        } catch (std::exception & ex) {
            std::cout << "Bad input." << std::endl;
            return (84);
        }
        if (
            (q1 <= 0 || q1 > 200)
            ||
            (q2 <= 0 || q2 > 200)
            ){
            std::cout << "Bad input." << std::endl;
            return (84);
        }
        if (q1 > q2) {
            std::cout << "Bad input." << std::endl;
            return (84);
        } else
            process2(u, o, q1, q2);
    }
    return (0);
}
