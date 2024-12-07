#include <stdio.h>
#include <stdlib.h>

/**
@brief Функция для нахождения пройденого расстояния
@param Параметр F - значение силы
@param Параметр А - значение работы
@return Возвращает значение пройденного расстояния
*/
double func_s(double F, double A);

/**
@brief проверяет вводимое значение, является ли оно числом
@return Возвращает введённое значение, если оно является числом
*/
float input(void);

/**
@brief Точка входа в программу
@return Возвращает в случае успеха
*/
int main(void) {
	printf("Введите значение затраченной силы (F) в кН:\t");
	double F = input();
	printf("Введите значение работы (А) в МДж:\t ");
	double A = input();
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
	// так как значение A вводится в мегаджоулях, значение А надо домножить на 1000000 для переведения в систему СИ
	// так как значение F вводится в килоньютонах, значение F надо домножить на 1000 для переведения в систему СИ
	// получается что формула выглядит так: A*1000000/F*1000 => после сокращения приобретёт вид А*1000/F, где 1000 = x
	const double x = 1000;
	return A * x / F;
}