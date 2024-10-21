#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
* @brief функция для нахождения значения параметра y
* @param x_start начальное значение параметра x
* @param x_end конечное значение параметра x
* @param x_delta значение шага для параметра x
* @return возвращает значение параметра y
*/
double func_for_finding_y(const double x_start, const double x_end, const double x_delta);

/**
* @brief считает значение рекурентного соотношения 
* @param x значение параметра x
* @param n значение параметра n
* @param x_delta значение параметра x_delta (шаг для параметра x)
* @return возвращает значение рекурентного соотношения
*/
double recurrent(double x, int n, double x_delta);

/**
@brief проверяет вводимое значение, является ли оно числом
@return Возвращает введённое значение, если оно является числом
*/
double input(void);

/**
@brief Точка входа в программу
@return Возвращает в случае успеха
*/
int main(void) {
	const double x_start = input();
	const double x_end = input();
	const double x_delta = input();
	func_for_finding_y(x_start, x_end, x_delta);
}

double func_for_finding_y(const double x_start, const double x_end, const double x_delta) {
	double current = 1;
	double summ = 0;
	int n = 0;
	for (double x = x_start; x <= x_end; x += x_delta) {
		current *= recurrent(x, n, x_delta);
		summ += current;
		printf("%lf\t%lf\t%lf\n", x, (( exp(x) + exp(-1 * x)) / 4), summ);
		n += 1;
	}
}
	
double recurrent(double x, int n, double x_delta) {
	return (x * x + 2*(x*x_delta)+x_delta*x_delta) / (double)(4 * n * n + 6 * n + 2);
}

double input(void) {
	double number = 0.0;
	if (scanf_s("%lf", &number) != 1) {
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return number;
}