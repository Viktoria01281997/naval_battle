#pragma once
using namespace std;
const int a = 10;
int field[a][a]{};
int i = 1, k = 1;

int field2[a][a]{};
int c = 1, v = 1;

const int l = 10;
int field3[a][a]{};
int m = 1, n = 1;


int rand(int a, int b) {
	return rand() % (b - a + 1) + a;
}



void cons(int field[][a], const int size) {
	for (i = 0; i < size; i++) {			//расстановка номеров
		for (k = 0; k < size; k++) {
			field[0][k] = k;
			field[i][0] = i;
		}
	}
	for (i = 0; i < size; i++) {
		for (k = 0; k < size; k++) {
			cout << field[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
} //консоль
