#include <stdio.h>
#include <stdlib.h>

/**
* @brief проверяет вводимое значение(является ли числом)
* @return возвращает значение если оно является числом
*/
double input(void);

/**
* @brief считаеn значение y относительно значения х и выводит значение х и у
* @param x_start значение х с которого начнётся табулирование функции
* @param x_end значение х на котором закончится табулирование функции
* @param x_delta значение шага между значениями табулирования функции
*/
void func_for_y(const double x_start,const double x_end,const double x_delta);

/**
* @brief точка входа в программу
* @return возвращает в случае успеха
*/
int main(void) {
	printf("Введите значения х с которого начнётся табулирование функции\t");
	const double x_start = input();
	printf("Введите значение х на котором закончится табулирование функции\t");
	const double x_end = input();
	printf("Введите значение шага между значениями табулирования функции\t");
	const double x_delta = input();
	printf("x\t|\ty\n");
	func_for_y(x_start, x_end, x_delta);
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

void func_for_y(const double x_start,const double x_end,const double x_delta) {
	for (double x = x_start; x < x_end+x_delta; x += x_delta) {
		const double y = x - x / 3 + x / 5 - 1 / 3;
		printf("%lf|%lf\n", x_start, y);
	}
}