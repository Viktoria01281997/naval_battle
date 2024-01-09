#include<iostream>
#include "Header.h"



void manual_placement();
void explosion();
void comp_hod(bool &ch, int &x, int &y);
void check(bool &bo);
void random_palubs();

int main() {
	int x = 0, y = 0;
	bool ch = false;
	srand(time(NULL));
	random_palubs();
	manual_placement();
	bool bo = true;
	while (bo == true) {
		cout << "Enter coordinares from 1 to 9." << endl;
		cout << "If the ship is wounded, the result will be \"There is a breakthrough!\" " << endl;
		cout << "If the ship is sunk, the result will be \"fall\" " << endl;
		cons(field3, a);
		cons(field2, a);
		explosion();
		comp_hod(ch, x, y);
		system("pause");
		system("CLS");
		check(bo);
	}
	
	return 0;
}

void random_palubs() {
	for (int x = 1; x <= 4; x++) {
		if ((i != 0) && (k != 0)) {
			i = rand(1, 9);
			k = rand(1, 9);
			if ((field[i][k - 1] != 1) && (field[i][k + 1] != 1)) {
				field[i][k] = 1;
			}
			else {
				x--;
			}
		}
	}
	for (int x = 1; x <= 3; x++) {
		if ((i != 0) && (k != 0)) {
			i = rand(1, 9);
			k = rand(1, 8);
			if ((field[i][k - 1] != 1) && (field[i][k + 1] != 1) && (field[i][k + 2] != 1)) {
				field[i][k] = 1;
				field[i][k + 1] = 1;
			}
			else {
				x--;
			}
		}
	}
	for (int x = 1; x <= 2; x++) {
		if ((i != 0) && (k != 0)) {
			i = rand(1, 9);
			k = rand(1, 7);
			if ((field[i][k - 1] != 1) && (field[i][k + 1] != 1) && (field[i][k + 3] != 1)) {
				field[i][k] = 1;
				field[i][k + 1] = 1;
				field[i][k + 2] = 1;
			}
			else {
				x--;
			}
		}
	}
	int x = 1;
	while (x == 1) {
		if ((i != 0) && (k != 0)) {
			i = rand(1, 9);
			k = rand(1, 6);
			if ((field[i][k - 1] != 1) && (field[i][k + 1] != 1) && (field[i][k + 4] != 1)) {
				field[i][k] = 1;
				field[i][k + 1] = 1;
				field[i][k + 2] = 1;
				field[i][k + 3] = 1;
				x++;
			}
			else {
				x = 1;
			}
		}
	}

}	//палубы в рандомном порядке

void manual_placement() {				//расстановка кораблей игроком
	int i = 0;
	while (i < 20) {
		cons(field3, a);
		int x = 0, y = 0;
		cin >> x >> y;
		field3[x][y] = 1;
		i++;
		system("cls");
	}
	//cons(field3, a);
}

void explosion() {
	
	int r = 0;
	while (r == 0) {
		int x = 0, y = 0;
		cin >> x >> y;
		if (x > 9 || y > 9) {
			cout << "Incorrect value. Try again. The number should not exceed 9.";
			break;
		}
		if (field[x][y] == 1) {
			field[x][y] = 0;
			cout << "There is a breakthrough!" << endl;
			field2[x][y] = 8;
			if ((field[x][y - 1] == 0) && (field[x][y + 1] == 0)) {
				cout << "fall" << endl;
			}
		}
		else if (field[x][y] == 0) {
			cout << "Past!" << endl;
			field2[x][y] = 9;
		}
		++r;
	}
}

void comp_hod(bool &ch, int &x, int &y) {
	int o = 0;
	
	if (ch == true) {
		if (field3[x][y+1] == 1) {
			field3[x][y + 1] = 8;
			++y;
			return;
		}
		else if (field3[x][y + 1] != 1) {
			field3[x][y + 1] = 9;
			ch = false;
			return;
		}
		if (y>1&&field3[x][y-1] == 1) {
			field3[x][y - 1] = 8;
			--y;
			return;
		}
		else if (y>1&&field3[x][y -1] == 0) {
			field3[x][y - 1] = 9;
			ch = false;
			return;
		}

	}
	while (o == 0) {
		x = rand(1, 9);
		y = rand(1, 9);
		if (field3[x][y] == 8|| field3[x][y] == 9) {
			--o;
			break;
		}
		if (field3[x][y] == 1) {
			field3[x][y] = 8;
			ch = true;

		}
		else if (field3[x][y] == 0) {
			field3[x][y] = 9;
			ch = false;
		}
		o++;
	}
	

}

void check(bool &bo) {
	int null = 0, null1 = 0;
	for (int i = 1; i < a; i++) {
		for (int k = 1; k < a; k++) {
			if (field[i][k] == 0) {
				++null;
			}
			
			if (field3[i][k] == 8) {
				++null1;
			}
			
			if (null == 81) {
				bo = false;
				cout << "Congratulations!You won!";
			}
			if (null1 == 20) {
				bo = false;
				cout << "unfortunately you lost=(";
			}
		}
	}
}
