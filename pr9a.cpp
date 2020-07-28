#include <iostream>
using namespace std;
void input_array(int ** arr,int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}
void output_array(int ** arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout<< arr[i][j]<<" ";
		}
		cout << endl;
	}
}
void copy_row(int * des, int * src, int n) {
	for (int i = 0; i < n; i++) {
		des[i] = src[i];
	}
}
