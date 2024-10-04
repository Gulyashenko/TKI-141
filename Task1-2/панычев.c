#include <stdio.h>
#include <math.h>
#define M_PI (3.14159265358979323846)

/**
@brief ������� ��� ���������� ������ ����
@param R �������� ������� ����
@return ���������� �������� ������ ����
*/
float func_V_ball(float R);

/**
@brief ������� ��� ���������� ������� ���������� ����
@param R �������� ������� ����
@return ���������� �������� ������� ���������� ����
*/
float func_S_ball(float R);

/**
 * @brief ����� ����� � ���������.
 * @return ���������� � ������ ������.
*/
int main() {
	float R;
	printf("Enter R:\t");
	scanf_s("%f", &R);
	float V = func_V_ball(R);
	float S = func_S_ball(R);
	printf("Volume of a ball:%f\nLateral surface area of a ball:%f", V, S);
	return 0;
}

float func_V_ball(float R) {
	float V = pow(R, 3) * 4 / 3 * M_PI;
	return V;
}

float func_S_ball(float R) {
	float S = 4*R*R*M_PI;
	return S;
}