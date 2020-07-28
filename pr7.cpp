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
