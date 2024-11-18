#include <stdio.h>
#include <stdlib.h>

/**
* @brief варианты заполнения массива числовыми значениями
*/
enum mass_input_choise {
	/**
	* @brief ручным способом
	*/
	arms = 1,
	/**
	* @brief заполнение случайными числами
	*/
	random = 2
};

/**
* @brief проверяет вводимое значение (является ли числом)
* @return возвращает введённое значение, если оно является числом
*/
int input(const char* message);

/**
* @brief Функция для печати массива.
* @param mass - массив.
* @param size - длинна массива.
* @return Массив.
*/
void print_mass(int* mass, const size_t size);

/**
* @brief Функция проверки интервала массива на правильность.
* @param min_l минимальный возможный элемент массива.
* @param max_l максимальный возможный элемент массива.
*/
void true_interval(const int min_l, const int max_l);

/**
* @brief Функция для проверки массива.
* @param массив.
* @remarks завершение программы, в случае несуществования массива.
*/
void true_mass(int* mass);

/**
* @brief Функция для проверки длинны массива.
* @param int_size - длинна массива.
* @remarks Экстренное завершение программы, в случае неправильной длинны массива.
*/
void true_size(const size_t size);

/**
@brief функция для нахождения максимального значения массива
@param массив в котором мы ищем максимальный элемент
@return возвращает значение максимального элемента массива
*/
int find_min_el_mass(int* mass, const size_t size);

/**
* @brief функция для замены минимального элемента массива на центральный элемент того же массива
* @param массив с которым мы работаем
* @return возвращает полученный массив
*/
void replace_min_el_mid_el(int* mass, const size_t size);

/**
* @brief функция для вывода индексов элементов, которые больше предыдущих
* @param массив с которым мы работаем
*/
void more_el_index_print(int* mass, const size_t size);

/**
* @brief функция для определения присутствия хотя бы двух пар соседних элементов с одным и тем же знаком
* @param массив с которым мы работаем
*/
void two_pairs(int* mass, const size_t size);

/**
* @brief Функция для ручного ввода элементов массива
* @param size длинна массива
* @param mass массив
* @param mass1 массив равный первому
* @param min_l значение минимально допустимого значения элемента массива
* @param max_l значение максимально допустимого значения элемента массива
*/
void arm_mass_input(int* mass, const size_t size, const int min_l, const int max_l);

/**
* @brief Функция для рандомного ввода элементов массива
* @param size длинна массива
* @param mass массив
* @param mass1 массив равный первому
* @param min_l значение минимально допустимого значения элемента массива
* @param max_l значение максимально допустимого значения элемента массива
*/
void random_mass_input(int* mass, const size_t size, const int min_l, const int max_l);

/**
* @brief функция для инициализации массива
* @param input_choise значение выбора варианта заполнения массива
* @param size длинна массива
* @param min_l значение минимально допустимого значения элемента массива
* @param max_l значение максимально допустимого значения элемента массива
*/
int* mass_inicialisation(const int input_choise, const size_t size, const int min_l, const int max_l);

/**
* @brief точка входа в программу
* @return возвращает в случае успеха
*/
int main(void) {
	int input_choise = input("введите вариант ввода элементов массива");
	int task_choise = input("введите номер задания которое надо выполнить (1, 2 или 3)");
	int max_l = input("введите максимальное допустимое значение элемента массива");
	int min_l = input("введите минимальное допустимое значение элемента массива");
	const size_t size = input("Введите длинну массива");

	int* mass = mass_inicialisation(input_choise, size, min_l, max_l);

	printf("ответ на задание 1");
	replace_min_el_mid_el(mass, size);

	printf("ответ на задание 2");
	more_el_index_print(mass, size);

	printf("ответ на задание 3");
	two_pairs(mass, size);
}

int input(const char* message) {
	printf("%s", message);
	int number = 0;
	if (scanf_s("%i", &number) != 1) {
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return number;
}

int find_min_el_mass(int* mass, const size_t size){
	int min = mass[0];
	for (size_t i = 1; i < size; ++i) {
		if (mass[i] < min) {
			min = mass[i];
		}
	}
	return min;
}

void replace_min_el_mid_el(int* mass, const size_t size) {
	int central_el = size/2;
	int cent_num = mass[central_el];
	mass[central_el] = find_min_el_mass(mass, size);
	print_mass(mass, size);
	mass[central_el] = cent_num;
}

void more_el_index_print(int* mass, const size_t size) {
	for (size_t i = 1; i < size; ++i) {
		if (mass[i - 1] < mass[i]) {
			printf("%i\t", i);
		}
	}
}

void two_pairs(int* mass, const size_t size) {
	int value_pairs = 0;
	for (int i = 1; i < size; ++i) {
		if ((mass[i - 1] < 0 && mass[i] < 0) || (mass[i - 1] == 0 && mass[i] == 0) || (mass[i - 1] > 0 && mass[i] > 0)) {
			value_pairs++;
		}
	}
	printf("%i", value_pairs);
}

void print_mass(int* mass, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%Iu %d\n", i, mass[i]);
	}
}

void true_mass(int* mass)
{
	if (mass == NULL)
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
}

void true_size(const size_t size)
{
	if ((int)size <= 0 || (int)size % 2 == 0)
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
}

void true_interval(const int min_l, const int max_l)
{
	if (min_l > max_l)
	{
		printf("Oшибка ввода интервала");
		exit(EXIT_FAILURE);
	}
}

void arm_mass_input(int* mass, const size_t size, const int min_l, const int max_l) {
	for (size_t i = 0; i < size; i++)
	{
		printf("Введите число от %d до %d: ", min_l, max_l);
		int element = get_value("");
		if (element < min_l || element > max_l)
		{
			printf("input error");
			exit(EXIT_FAILURE);
		}
		mass[i] = element;
	}
}

void random_mass_input(int* mass, const size_t size, const int min_l, const int max_l)
{
	unsigned int ttime = time(NULL);
	srand(ttime);
	for (size_t i = 0; i < size; i++)
	{
		mass[i] = min_l + rand() % (max_l - min_l + 1);
	}
}

int* mass_inicialisation(const int input_choise, const size_t size, const int min_l, const int max_l) {
	int* mass = (int*)malloc(size * sizeof(int));
	int* mass1 = (int*)malloc(size * sizeof(int));
	if (mass == NULL)
	{
		printf("Ошибка: недостаточно памяти.\n");
		exit("EXIT_FAILURE");
	}
	switch (input_choise) {
	case arms:
		arm_mass_input(mass, size, min_l, max_l);
	case random:
		random_mass_input(mass, size, min_l, max_l);
	}
	return mass;
}