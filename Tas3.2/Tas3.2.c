#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

/**
* @brief вычисляет сумму первых n членов последовательности (k = 1, 2, 3 ..., n).
* @param n значение последнего члена последовательности
* @return возвращает сумму первых n членов последовательности (k = 1, 2, 3 ..., n)
*/
double func_for_finding_summ_1(const int n);

/**
* @brief вычисляет сумму всех членов последовательности, не меньших заданного числа e
* @param e значение параметра e
* @return возвращает сумму всех членов последовательности, не меньших заданного числа e
*/
double func_for_finding_summ_2(const double e);

/**
* @brief вычисляет рекуррентное соотношение относительно данного значения элемента последовательности
* @param k значение данного элемента последовательности
* @return возвращает полученное значение
*/
double recurrent(const int k);

/**
@brief проверяет вводимое значение, является ли оно числом
@return Возвращает введённое значение, если оно является числом
*/
double input(void);

/**
 * @brief Точка входа в программу.
 * @return Возвращает в случае успеха.
*/
int main(void) {

	printf("введите значение n:\t");
	int n = input();
	printf("введите значение e:\t");
	double e = input();

	if (n < 0 || e <= 0) {
		printf("input error");
		exit(EXIT_FAILURE);
	}

	printf("%lf\n%lf", func_for_finding_summ_1(n), func_for_finding_summ_2(e));

	return 0;
}

double func_for_finding_summ_1(const int n) {
	double current = 1;
	double summ = current; 

	for (int k = 0; k < n; k++) {
		current *= recurrent(k);
		summ += current;
	}
	printf("конец первой функции");
	return summ;
}

double func_for_finding_summ_2(const double e) {

	double current = 1;
	double summ = 0;

	for (int k = 0; fabs(current)>e-DBL_EPSILON; k++) {
		summ += current;
		current *= recurrent(k);
	}
	printf("конец второй функции");
	 return summ;
}

double recurrent(const int k) {
	return pow(-1, k) / (double)(4 * k * k + 6 * k + 2);
}

double input(void) {
	double number = 0;
	if (scanf_s("%lf", &number) != 1) {
		printf("input error");
		exit(EXIT_FAILURE);
	}
	return number;
}