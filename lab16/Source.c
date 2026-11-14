#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int task1(void);
double* full_elements(double* ptr_array, int size);
double* calc_elements(double* ptr_array, int size);
int put_elements(double* ptr_array, int size);

int main(void) {

	setlocale(LC_CTYPE, "RUS");

	task1();

	return 0;
}

int task1(void) {

	double* ptr_array, *ptr_array2;
	int size;

	printf("Введите размер массива: ");
	scanf("%d", &size);
	printf("\n");

	ptr_array = (double*)malloc(size * sizeof(double));

	if (ptr_array == NULL) {
		puts("error");
		return -1;
	}

	full_elements(ptr_array, size);

	ptr_array2 = calc_elements(ptr_array, size);

	if (ptr_array2 == NULL) {
		puts("error");
		return -1;
	}

	put_elements(ptr_array, size);
	put_elements(ptr_array2, size);

	free(ptr_array);
	free(ptr_array2);

	return 0;
}

double* full_elements(double* ptr_array, int size) {

	double start = 1, end = 3;
	double step = (end - start) / (size - 1.);

	for (int i = 0; i < size; i++) {
		*(ptr_array + i) = start * start * start - 4 * start * start + 2;
		start += step;
	}

	return ptr_array;
}

double* calc_elements(double* ptr_array, int size) {

	double* array2;

	array2 = (double*)malloc(size * sizeof(double));

	if (array2 == NULL) {
		puts("error");
		return NULL;
	}

	for (int i = 0; i < size; i++) *(array2 + i) = -1 * *(ptr_array + i);

	return array2;
}

int put_elements(double* ptr_array, int size) {

	for (int i = 0; i < size; i++) printf("%d элемент: %f\n", i + 1, *(ptr_array + i));

	return 0;
}