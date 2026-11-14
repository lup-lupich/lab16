#define _CRT_SECURE_NO_WARNINGS
#define XMIN -1
#define XMAX 1
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int task1(void);
double* full_elements(double* ptr_array, int size);
double* calc_elements(double* ptr_array, int size);
int put_elements(double* ptr_array, int size);
int task2(void);
double* full_elements_rand(double* ptr_array, int size);
int delete_elements(double* ptr_arr, int size);
double* insert(double* ptr_arr, int size, int num);

int main(void) {

	setlocale(LC_CTYPE, "RUS");

	task1();
	task2();

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
		return NULL;
	}

	for (int i = 0; i < size; i++) *(array2 + i) = -1 * *(ptr_array + i);

	return array2;
}

int put_elements(double* ptr_array, int size) {

	for (int i = 0; i < size; i++) printf("%d элемент: %f\n", i + 1, *(ptr_array + i));

	return 0;
}

int task2(void) {

	double *rand_array;
	int size;
	int num = -999;

	printf("Введите размер массива: ");
	scanf("%d", &size);
	printf("\n");

	rand_array = (double*)malloc(size * sizeof(double));

	if (rand_array == NULL) {

		printf("error");

		return -1;
	}

	full_elements_rand(rand_array, size);

	size = delete_elements(rand_array, size);

	rand_array = insert(rand_array, &size, num);

	put_elements(rand_array, size);

	free(rand_array);

	return 0;
}

double* full_elements_rand(double* ptr_array, int size) {

	int stime;
	long ltime;

	ltime = time(NULL);
	stime = (unsigned)ltime / 2;
	srand(stime);

	for (int i = 0; i < size; i++) {

		*(ptr_array + i) = XMIN + (XMAX - XMIN) * (double)rand() / RAND_MAX;
	}

	return ptr_array;
}

int delete_elements(double* ptr_arr, int size) {

	int new_size = size;

	for (int i = 0; i < new_size; i++) {

		if (*(ptr_arr + i) < 0) {

			for (int temp = i; temp < new_size - 1; temp++) {
				*(ptr_arr + temp) = *(ptr_arr + temp + 1);
			}
			new_size -= 1;

			i--;
		}
	}

	return new_size;
}

double* insert(double* ptr_arr, int* size, int num) {

	int new_size = *size;
	int j;

	for (int i = 0; i < *size; i++) {

		if (*(ptr_arr + i) > 0) new_size += 1;
	}

	double* ptr_arr_new = (double*)realloc(ptr_arr, new_size * sizeof(double));

	if (ptr_arr_new == NULL) return NULL;

	 j = new_size - 1;

	for (int i = *size - 1; i >= 0; i--) {

		*(ptr_arr_new + j) = *(ptr_arr_new + i);
		j--;

		if (*(ptr_arr_new + i) > 0) {
			*(ptr_arr_new + j) = num;
			j--;
		}
	}

	*size = new_size;

	return ptr_arr_new;
}