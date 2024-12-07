#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Ищет значение y относительно значения x
 * @param x - значение вводимого x
 * @param a - константа
 * @return возвращает значение найденного y
 */
double func_for_y(const double a, const double x);

/**
 * @brief позволяет ввести значение и проверяет его(является ли числом)
 * @return возврашает введённое значение, если оно является числом
 */
double input(void);

/**
 * @brief точка входа в программу
 * @return возвращает в случае успеха
 */
int main(void)
{
    const double a = 20.3;
    printf("введите значение x:\t");
    double x = input();
    printf("Y = %lf", func_for_y(a, x));
    return 0;
}

double input(void) {
    double number;
    if (scanf_s("%lf", &number) != 1) {
        printf("input error");
        exit(EXIT_FAILURE);
    }
    return number;
}

double func_for_y(const double a, const double x) {
    if (x < 1) {
        return log(x + 1);
    }
    else {
        return sin(2 * sqrt(abs(a * x)));
    }
}