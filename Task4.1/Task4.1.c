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
* @param сообщение которое нужно вывести перед вводом
* @return возвращает введённое значение, если оно является числом
*/
int input(const char* message);

/**
* @brief Функция для печати массива.
* @param mass - массив.
* @param size - длинна массива.
* @return Массив.
*/
void print_mass(const int* mass, const size_t size);

/**
* @brief Функция проверки интервала массива на правильность.
* @param min_l минимальный возможный элемент массива.
* @param max_l максимальный возможный элемент массива.
*/
void true_interval(const int min_l, const int max_l);

/**
* @brief функция для нахождения максимального значения массива
* @param массив в котором мы ищем максимальный элемент
* @param size - длинна массива.
* @return возвращает значение максимального элемента массива
*/
int find_min_el_mass(const int* mass, const size_t size);

/**
* @brief функция для замены минимального элемента массива на центральный элемент того же массива
* @param массив с которым мы работаем
* @param размер массива
* @return возвращает полученный массив
*/
void replace_min_el_mid_el(int* mass, const size_t size);

/**
* @brief функция для вывода индексов элементов, которые больше предыдущих
* @param массив с которым мы работаем
* @param размер массива
*/
void more_el_index_print(const int* mass, const size_t size);

/**
* @brief функция для определения присутствия хотя бы двух пар соседних элементов с одным и тем же знаком
* @param массив с которым мы работаем
* @param размер массива
* @return возвращает количество пар соседних элементов с одним знаком
*/
int two_pairs(const int* mass, const size_t size);

/**
* @brief Функция для ручного ввода элементов массива
* @param size длинна массива
* @param mass массив
* @param min_l значение минимально допустимого значения элемента массива
* @param max_l значение максимально допустимого значения элемента массива
*/
void arm_mass_input(int* mass, const size_t size, const int min_l, const int max_l);

/**
* @brief Функция для рандомного ввода элементов массива
* @param size длинна массива
* @param mass массив
* @param min_l значение минимально допустимого значения элемента массива
* @param max_l значение максимально допустимого значения элемента массива
*/
void random_mass_input(int* mass, const size_t size, const int min_l, const int max_l);

/**
* @brief Функция для проверки существования массива.
* @param mass  массив.
* @remarks Экстренное завершение программы, в случае неправильной длинны массива.
*/
void check_mass(const int* mass);

/**
* @brief проверяет вводимое значение
* @remarks Экстренное завершение программы, в случае неправильной длинны массива.
*/
size_t input_size(void);

/**
* @brief копирует массив
* @param mass - массив который нужно скопировать
* @param size - длинна массива
* @remarks возвращает новый массив идентичный копируемому
*/
int* copy_mass(const int* mass, const size_t size);

/**
 * @brief Функция создания массива
 * @param размер создаваемого массива
 * @return возвращает созданный по размеру массив
 */
int* create_mass(size_t const size);

/**
* @brief точка входа в программу
* @return возвращает в случае успеха
*/
int main(void) {
	printf("Как Вы хотите заполнить массив ? \n % d - ручной ввод, % d - случайный ввод\n", arms, random);
	int choose_input = input("");
	int max_l = input("введите максимальное допустимое значение элемента массива");
	int min_l = input("введите минимальное допустимое значение элемента массива");
	true_interval(min_l, max_l);

	const size_t size = input_size();

	int* mass = create_mass(size);
	switch (choose_input) {
	case arms:
		arm_mass_input(mass, size, min_l, max_l);
	case random:
		random_mass_input(mass, size, min_l, max_l);
	}
	int* mass1 = copy_mass(mass, size);

	replace_min_el_mid_el(mass1, size);

	printf("ответ на задание 1:\t");
	print_mass(mass1, size);

	printf("\nответ на задание 2:\t");
	more_el_index_print(mass, size);

	printf("\nответ на задание 3:%d\t", two_pairs(mass, size));

	return 0;
}

int input(const char* message) {
	if (message != NULL) {
		printf("%s", message);
	}
	int number = 0;
	if (scanf_s("%i", &number) != 1) {
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return number;
}

int find_min_el_mass(const int* mass, const size_t size) {
	check_mass(mass);
	int min = mass[0];
	for (size_t i = 1; i < size; ++i) {
		if (mass[i] < min) {
			min = mass[i];
		}
	}
	return min;
}

void replace_min_el_mid_el(int* mass1, const size_t size) {
	check_mass(mass1);
	size_t central_el = size / 2;
	int cent_num = mass1[central_el];
	mass1[central_el] = find_min_el_mass(mass1, size);
}

void more_el_index_print(const int* mass, const size_t size) {
	check_mass(mass);
	for (size_t i = 1; i < size; ++i) {
		if (mass[i - 1] < mass[i]) {
			printf("%d\t", i);
		}
	}
}

int two_pairs(const int* mass, const size_t size) {
	check_mass(mass);
	int value_pairs = 0;
	for (size_t i = 1; i < size; ++i) {
		if (mass[i] * mass[i - 1] > 0) {
			value_pairs++;
		}
	}
	return value_pairs;
}

void print_mass(const int* mass, const size_t size)
{
	check_mass(mass);
	for (size_t i = 0; i < size; i++)
	{
		printf("%d,", mass[i]);
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
		int element = input("");
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

void check_mass(const int* mass) {
	if (mass == NULL)
	{
		printf("Ошибка: недостаточно памяти.\n");
		exit("EXIT_FAILURE");
	}
}

size_t input_size(void)
{
	int size = input("введите значение размера массива");
	if (input <= 0)
	{
		puts("Input error");
		exit(EXIT_FAILURE);
	}
	return (size_t)size;
}

int* copy_mass(const int* mass, const size_t size)
{
	int* mass1 = create_mass(size);
	for (size_t i = 0; i < size; i++) {
		mass1[i] = mass[i];
	}
	return mass1;
}

int* create_mass(size_t const size)
{
	int* mass = (int*)malloc(size * sizeof(int));
	check_mass(mass);
	return mass;
}