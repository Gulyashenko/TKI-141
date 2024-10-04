#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float input(void);
/**
@brief функция для вычесления объёма конуса вписанного в шар
@param the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex значение угла в осевом сечении конуса вписанного в шар при его вершине
@param the_radius_of_the_ball_into_which_the_cone_is_inscribed значение радиуса шара, в который вписан конус
@return возвращает значение объёма конуса вписанного в шар
*/
float a_function_for_finding_the_volume_of_a_cone_inscribed_in_a_ball(float the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex, float the_radius_of_the_ball_into_which_the_cone_is_inscribed);

/**
@brief функция для вычесления площади боковой поверхности конуса вписанного в шар
@param the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex значение угла в осевом сечении конуса при его вершине
@param the_radius_of_the_ball_into_which_the_cone_is_inscribed значение радиуса шара, в который вписан конус
@return возвращает значение площади боковой поверхности конуса вписанного в шар
*/
float a_function_for_calculating_the_area_of_the_lateral_surface_of_a_cone_inscribed_in_a_ball(float the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex, float the_radius_of_the_ball_into_which_the_cone_is_inscribed);

/**
 * @brief Точка входа в программу.
 * @return Возвращает в случае успеха.
*/
int main(void) {

	printf("Enter a in radians:\t");
	float the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex = input();

	printf("Enter R:\t");
	float the_radius_of_the_ball_into_which_the_cone_is_inscribed = input();

	printf("Volume of a cone:%f\nLateral surface area of a cone:%f", a_function_for_finding_the_volume_of_a_cone_inscribed_in_a_ball(the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex, the_radius_of_the_ball_into_which_the_cone_is_inscribed), a_function_for_calculating_the_area_of_the_lateral_surface_of_a_cone_inscribed_in_a_ball(the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex, the_radius_of_the_ball_into_which_the_cone_is_inscribed));
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

float a_function_for_finding_the_volume_of_a_cone_inscribed_in_a_ball(float the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex, float the_radius_of_the_ball_into_which_the_cone_is_inscribed) {
	return pow(2 * the_radius_of_the_ball_into_which_the_cone_is_inscribed * (1 - (sin(the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex) * sin(the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex))) * sin(the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex), 3) * (2 * the_radius_of_the_ball_into_which_the_cone_is_inscribed * (1 - (sin(the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex) * sin(the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex))) * cos(the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex)) / 3 * M_PI;
}

float a_function_for_calculating_the_area_of_the_lateral_surface_of_a_cone_inscribed_in_a_ball(float the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex, float the_radius_of_the_ball_into_which_the_cone_is_inscribed) {
	return (2 * the_radius_of_the_ball_into_which_the_cone_is_inscribed * (1 - (sin(the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex) * sin(the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex))) * sin(the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex)) * (2 * the_radius_of_the_ball_into_which_the_cone_is_inscribed * (1 - (sin(the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex) * sin(the_value_of_the_cone_angle_at_the_axial_section_at_its_vertex)))) * M_PI;
}