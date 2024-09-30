#include <stdio.h>
#include <math.h>
#define M_PI (3.14159265358979323846)

/**
@brief функция для вычесления объёма конуса вписанного в шар
@param a значение угла в осевом сечении конуса при его вершине
@param R значение радиуса шара, в который вписан конус
@return возвращает значение объёма конуса вписанного в шар
*/
float func_V(float a, float R);

/**
@brief функция для вычесления площади боковой поверхности конуса вписанного в шар
@param a значение угла в осевом сечении конуса при его вершине
@param R значение радиуса шара, в который вписан конус
@return возвращает значение площади боковой поверхности конуса вписанного в шар
*/
float func_S(float a, float R);

/**
 * @brief Точка входа в программу.
 * @return Возвращает в случае успеха.
*/
int main() {
	float a, R;
	printf("Enter a in radians:\t");
	scanf_s("%f", &a);
	printf("Enter R:\t");
	scanf_s("%f", &R);
	float V = func_V(a, R);
	float S = func_S(a, R);
	printf("Volume of a cone:%f\nLateral surface area of a cone:%f", V, S);
	return 0;
}

float func_V(float a, float R) {
	float V = pow(2*R*(1-(sin(a)*sin(a)))*sin(a), 3) * (2 * R * (1 - (sin(a) * sin(a)))*cos(a)) / 3 * M_PI;
	return V;
}

float func_S(float a, float R) {
	float S = (2 * R * (1 - (sin(a) * sin(a))) * sin(a)) * (2 * R * (1 - (sin(a) * sin(a)))) * M_PI;
	return S;
}