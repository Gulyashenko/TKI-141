#include <math.h>
#include <stdio.h>

/**
* @brief функция для вычисления значения а.
* @param x Значение переменной x.
* @param y Значение переменной y.
* @param z Значение переменной z.
* @return Результат вычислени а.
*/
double func_a(double x, double y, double z);

/**
* @brief функция для вычисления значения b.
* @param x Значение переменной x.
* @param y Значение переменной y.
* @param z Значение переменной z.
* @return Результат вычислени b.
*/
double func_b(double x, double y, double z);

/**
 * @brief Точка входа в программу.
 * @return Возвращает в случае успеха.
*/
int main()
{
	const double x = 0.2;
	const double y = 0.004;
	const double z = 1.1;

	double a = func_a(x, y, z);
	double b = func_b(x, y, z);

	printf("a = %f \nb = %f", a, b);

	return 0;
}

double func_a(double x, double y, double z)
{
	return pow(sin(pow((x * x + z), 2)), 3) - sqrt(x / y);
}

double func_b(double x, double y, double z)
{
	return x * x / z + cos(pow((x + y), 3));
}