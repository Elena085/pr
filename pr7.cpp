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
