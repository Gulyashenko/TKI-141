#include <math.h>
#include <stdio.h>

/**
* @brief функция для вычисления значения b.
* @param x Значение переменной x.
* @param y Значение переменной y.
* @param z Значение переменной z.
* @return Результат вычисления b.
*/
double func_b(const double x, const double y, const double z);

/**
* @brief функция для вычисления значения а.
* @param x Значение переменной x.
* @param y Значение переменной y.
* @param z Значение переменной z.
* @return Результат вычисления а.
*/
double func_a(const double x, const double y, const double z)

/**
 * @brief Точка входа в программу.
 * @return Возвращает в случае успеха.
*/
int main(void)
{
	const double x = 0.2;
	const double y = 0.004;
	const double z = 1.1;

	printf("a = %f \nb = %f", func_a(x, y, z), func_b(x, y, z));

	return 0;
}

double func_a(const double x, const double y, const double z)
{
	return pow(sin(pow((x * x + z), 2)), 3) - sqrt(x / y);
}

double func_b(const double x, const double y, const double z)
{
	return x * x / z + cos(pow((x + y), 3));
}
