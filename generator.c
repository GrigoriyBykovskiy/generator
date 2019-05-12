// generator.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "malloc.h"
#define OUTPUTFILENORMSEL "output_norm_sel.csv"
#define OUTPUTFILESEL "output_sel.csv"
int *fib_gen(int x_next, int x_prev, int m, int length) {
	int *storage;
	if ((storage = (int*)malloc(length * sizeof(int))) != NULL) {
		int element;
		storage[0] = x_prev;
		storage[1] = x_next;
		for (int i = 0; i < length - 2; i++) {
			element = (storage[i] + storage[i+1]) % m;
			storage[i+2] = element;
		}
		return storage;
	}
	else {
		printf("Out of memory!\n");
	}
};
int *lkg(int a, int x, int c, int m, int length) {
	int *storage;
	if ((storage = (int*)malloc(length * sizeof(int))) != NULL) {
		int element;
		storage[0] = x;
		for (int i = 0; i < length - 1; i++) {
			element = (a*storage[i] + c) % m;
			storage[i + 1] = element;
		}
		return storage;
	}
	else {
		printf("Out of memory!\n");
	}
};
float *normalize(int *selection, int m, int length) {
	float *normalize_selection;
	if ((normalize_selection = (float*)malloc(length * sizeof(float))) != NULL) {
		for (int i = 0; i < length; i++) {
			printf("%d\n", selection[i]);
			normalize_selection[i] = selection[i] / (float)m;
			printf("%f\n", normalize_selection[i]);
		}
		return normalize_selection;
	}
};
void create_outputfile(float *selection,int length) {
	FILE *output=fopen(OUTPUTFILENORMSEL,"w+");
	if (output != NULL) {
		for (int i = 0; i < length;i++) {
			fprintf(output, "%f;\n", selection[i]);
		}
		fclose(output);
	}
	else {
		printf("Something was wrong!\n");
	}
};
int main() {
	int *selection = fib_gen(11, 56, 10000, 500);
	float *normalize_selection = normalize(&selection[0], 10000, 500);
	create_outputfile(&normalize_selection[0], 500);
	/*int *selection = lkg(61,625,7,10000000,500);
	FILE *output = fopen(OUTPUTFILESEL, "w+");
	if (output != NULL) {
		for (int i = 0; i < 500; i++) {
			fprintf(output, "%d;\n", selection[i]);
		}
		fclose(output);
	}
	else {
		printf("Something was wrong!\n");
	}
	float *normalize_selection = normalize(&selection[0], 10000000, 500);
	create_outputfile(&normalize_selection[0], 500);*/
	return 0;
}