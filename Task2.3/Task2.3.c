#include <stdio.h>
#include <stdlib.h>

/**
* @brief перечисление фигур
*/
enum figures{Treugolnik = 1, Kvadrat, Pryamougolnik, Trapeciya, Parallelogram};

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
    printf("введите название фигуры(число от 1 до 5:\t");
    int figure_name = input();
    
    switch (figure_name) {
    case Treugolnik:
        printf("формула площади треугольника");
        break;
    case Kvadrat:
        printf("формула площади квадрата");
        break;
    case Pryamougolnik:
        printf("формула площади прямоугольника");
        break;
    case Trapeciya:
        printf("формула формула трапеции");
        break;
    case Parallelogram:
        printf("формула трапеции параллелограма");
        break;
    }

    return 0;
}

int input(void) {
    int number;
    if (scanf_s("%lf", &number) != 1) {
        printf("input error");
        exit(EXIT_FAILURE);
    }
    return number;
}