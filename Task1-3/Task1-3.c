#include <stdio.h>
#include <stdlib.h>

/**
@brief Функция для нахождения пройденого расстояния
@param Параметр F - значение силы
@param Параметр А - значение работы
@return Возвращает значение пройденного расстояния
*/
double func_s(double F, double A);

float input(void);

/**
@brief Точка входа в программу
@return Возвращает в случае успеха
*/
int main(void) {
	double F,A;
	printf("Введите значение затраченной силы (F) в кН:\t");
	F = input();
	printf("Введите значение работы (А) в МДж:\t ");
	A = input();
	printf("%f", func_s(F, A));
	return 0;
}

float input(void) {
	float input_value;
	if (scanf_s("%f", &input_value) != 1) {
		printf("input error");
		exit(EXIT_FAILURE);
	}
	return input_value;

}

double func_s(double F, double A) {
	double s = A * 1000 / F;
	return s;
}