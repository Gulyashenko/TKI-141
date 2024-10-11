#include <stdio.h>
#include <stdlib.h>
/**
@brief перечисление названий дней недели
*/
enum days { Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

/**
@brief перечисление названий месяцев
*/
enum months { January = 1, February, March, April, May, June, July, August, September, October, November, December };

int input(void);

/**
@brief Функция для нахождения названия дня недели относительно введённого числа
@param Параметр month - вводимое число, означающее день недели
@return Возвращает название дня недели относительно введённого числа
*/
const char* func_for_day(int day);

/**
@brief Функция для нахождения названия месяца относительно введённого числа
@param Параметр month - вводимое число, означающее месяц
@return Возвращает название месяца относительно введённого числа
*/
const char* func_for_month(int month);

/**
@brief Точка входа в программу
@return Возвращает в случае успеха
*/
int main(void) {
    int day, month;
    printf("Print the number of day (from 1 till 7):\t");
    day = input();
    printf("Print the number of month (from 1 till 12):\t");
    month = input();

    printf("Day:\t%s\n", func_for_day(day));
    printf("Month:\t%s", func_for_month(month));

    return 0;
}

int input(void) {
    int number = 0;
    if (scanf_s("%d", &number) != 1) {
        printf("Your input isn't a numbern");
        exit(EXIT_FAILURE);
    }
    return number;
}

const char* func_for_day(int day) {
    switch (day) {
    case Monday:
        return "Monday";
    case Tuesday:
        return "Tuesday";
    case Wednesday:
        return "Wednesday";
    case Thursday:
        return "Thursday";
    case Friday:
        return "Friday";
    case Saturday:
        return "Saturday";
    case Sunday:
        return "Sunday";
    default:
        return "Invalid input, try again";
    }
}

const char* func_for_month(int month) {
    switch (month) {
    case January:
        return "January";
    case February:
        return "February";
    case March:
        return "March";
    case April:
        return "April";
    case May:
        return "May";
    case June:
        return "June";
    case July:
        return "July";
    case August:
        return "August";
    case September:
        return "September";
    case October:
        return "October";
    case November:
        return "November";
    case December:
        return "December";
    default:
        return "Invalid input, try again";
    }
}