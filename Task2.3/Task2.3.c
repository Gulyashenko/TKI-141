#include <stdio.h>
#include <stdlib.h>

/**
* @brief перечисление фигур
*/
enum figures
{
    /**
    *@brief треугольник
    */
    Triangle = 1,
    /**
    * @brief квадрат
    */
    Square, 
    /**
    * @brief прямоугольник
    */
    Rectangle,
    /**
    * @brief трапеция
    */
    Trapeze, 
    /**
    * @brief параллелограм
    */
    Parallelogram
};

/**
 * @brief позволяет ввести значение и проверяет его(является ли числом)
 * @return возврашает введённое значение, если оно является числом
 */
int input(void);

/**
 * @brief точка входа в программу
 * @return возвращает в случае успеха
 */
int main(void)
{
    printf("введите название фигуры(число от 1 до 5):\t");
    int figure_name = input();
    
    switch (figure_name) {
    case Triangle:
        printf("формула площади треугольника S = 0.5*h*a");
        break;
    case Square:
        printf("формула площади квадрата S = a*a");
        break;
    case Rectangle:
        printf("формула площади прямоугольника S = a*b");
        break;
    case Trapeze:
        printf("формула площади трапеции S = 0.5*(a+b)*h");
        break;
    case Parallelogram:
        printf("формула площади параллелограма  S = a*b*cos(a^b)");
        break;
    default: 
        printf("input error, try again");
        break;
    }

    return 0;
}

int input(void) {
    int number;
    if (scanf_s("%f", &number) != 1) {
        printf("input error");
        exit(EXIT_FAILURE);
    }
    return number;
}