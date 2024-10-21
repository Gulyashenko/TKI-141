#include <stdio.h>
#include <stdlib.h>
/**
@brief перечисление названий дней недели
*/
enum days {
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6,
    Sunday = 7
};

/**
@brief перечисление названий месяцев
*/
enum months { 
    January = 1,
    February = 2,
    March = 3,
    April = 4, 
    May = 5,
    June = 6,
    July = 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12
};

int input(void);

/**
@brief Точка входа в программу
@return Возвращает в случае успеха
*/
int main(void) {
    printf("Print the number of day (from Monday till Sunday):\t");
    int day = input();
    printf("Print the number of month (from January till December):\t");
    int month = input();

    switch (day) {
    case Monday:
        printf("Monday\n");
        break;
    case Tuesday:
        printf("Tuesday\n");
        break;
    case Wednesday:
        printf("Wednesday\n");
        break;
    case Thursday:
        printf("Thursday\n");
        break;
    case Friday:
        printf("Friday\n");
        break;
    case Saturday:
        printf("Saturday\n");
        break;
    case Sunday:
        printf("Sunday\n");
        break;
    default:
        printf("Invalid input, try again\n");
        break;
    }

    switch (month) {
    case January:
        printf("January");
        break;
    case February:
        printf("February");
        break;
    case March:
        printf("March");
        break;
    case April:
        printf("April");
        break;
    case May:
        printf("May");
        break;
    case June:
        printf("June");
        break;
    case July:
        printf("July");
        break;
    case August:
        printf("August");
        break;
    case September:
        printf("September");
        break;
    case October:
        printf("October");
        break;
    case November:
        printf("November");
        break;
    case December:
        printf("December");
        break;
    default:
        printf("Invalid input, try again");
        break;
    }

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