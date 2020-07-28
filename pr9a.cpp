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
void copy_column(int ** des, int ** src, int jt,int j,int n) {
	for (int i = 0; i < n; i++) {
		des[i][jt] = src[i][j];
	}
}
int ** delete_row_col(int ** arr, int &n) {
	int i_m = 0, j_m = 0,max=arr[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > max) {
				i_m = i;
				j_m = j;
				max = arr[i][j];
			}
		}
	}
	for (int i = 0,it=0; i < n; i++) {
		if (i!=i_m) {
			if (i != it) {
				copy_row(arr[it], arr[i],n);
			}
			it++;
		}
	}
	for (int j = 0, jt = 0; j < n; j++) {
		if (j != j_m) {
			if (j != jt) {
				copy_column(arr, arr, jt,j,n);
			}
			jt++;
		}
	}
	n--;
	int **A = new int*[n];
	for (int i = 0; i < n; i++) {
		A[i] = new int[n];
	}
	for (int i = 0; i < n ; i++) {
		copy_row(A[i], arr[i], n);
	}
	for (int i = 0; i < n+1; i++) {
		delete[]arr[i];
	}
	delete[] arr;
	return A;
}
int main()
{
	int n;
	cout << "Enter matrix size: ";
	cin >> n;
	int **A=new int*[n];
	for (int i = 0; i < n; i++) {
		A[i] = new int[n];
	}
	cout << "Enter matrix:\n";
	input_array(A, n);
	A = delete_row_col(A, n);
	cout << "Result:\n";
	output_array(A, n);
	for (int i = 0; i < n; i++) {
		delete[]A[i];
	}
	delete[] A;
 }
