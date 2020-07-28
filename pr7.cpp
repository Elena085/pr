#include <stdio.h>
#include <iostream>
#include <fstream>
void input_matrixc(int matrix[][5], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> matrix[i][j];
		}
	}
}
void input_matrixf(int matrix[][5], int m, int n) {
	std::ifstream fin("input.txt");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fin >> matrix[i][j];
		}
	}
	fin.close();
}
void output_matrix(int matrix[][5], int *X, int Y, int m, int n) {
	std::ofstream fin("output.txt");
	std::cout << "A\n";
	fin << "A\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << " ";
			fin << matrix[i][j] << " ";
		}
		std::cout << std::endl;
		fin << std::endl;
	}
	std::cout << "X\n";
	fin << "X\n";
	for (int i = 0; i < m; i++) {
		std::cout << X[i] << " ";
		fin << X[i] << " ";
	}
	std::cout << "\nY = " << Y;
	fin << "\nY = " << Y;
	fin.close();
}
int calculate_Y_rec(int *ptr, int min, int n,int k) {
	if (n > 0) {
		if (*ptr==min) {
			
			k++;
			return calculate_Y_rec(ptr + 1, min, n - 1,k);
		}
		else if (*ptr<min ) {
			min = *ptr;
			k = 1;
			return calculate_Y_rec(ptr + 1, min, n - 1,k);
		}
		return calculate_Y_rec(ptr + 1, min, n - 1,k);
	}
	return k;
}
int calculate_Y(int *ptr, int n) {
	int min = *ptr;
	int k = 1;
	return calculate_Y_rec(ptr+1, min, n-1,k);
}
int* solution(void(*input_matrix)(int(*)[5], int, int)) {
#define N 5
#define M 5
	int A[M][N];
	int X[M] = { 0 };
	int Y;
	input_matrix(A, M, N);
	Y = calculate_Y(*A, N);
	int max = A[0][0];
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N&&A[i][j]>=0; j++) {
			X[i] += A[i][j];
		}
	}
	
	output_matrix(A, X, Y, M, N);
	return X;
#undef N 
#undef M 
}
