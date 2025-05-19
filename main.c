#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<string.h>

int game(void);
int map9(void);
int map12(void);
void cleaner9(int a, int b);
void cleaner12(int a, int b);

int win = 0, loss = 0;
int bomb9 = 10, flag9 = 10, bomb12 = 20, flag12 = 20;
int map19[9][9];
char map29[9][9];
char map39[9][9] = { '0' };
int map112[12][12];
char map212[12][12];
char map312[12][12] = { '0' };
char name[20];

int main() {
	char n1;
	printf("\033[0;32mWelcom to Minesweeper game\nPleas enter your name :\n");
	gets_s(name);
	system("cls");
	printf("\033[0;32mName : %s\nwin : %d\nloss : %d\n", name, win, loss);
	while (3 > 1) {
		printf("\033[0;32mPleas select an option :\n1 : Change Name\n2 : Play\n");
		scanf("%c", &n1);
		system("cls");
		if (n1 == '1') {
			printf("\033[0;32mPleas enter new Name :\n");
			gets_s(name);
			gets_s(name);
			system("cls");
			printf("\033[0;32mName : %s\nwin : %d\nloss : %d\n", name, win, loss);
		}
		else if (n1 == '2') {
			game();
		}
		else {
			printf("\033[0;31mincorrect input!!\n");
		}
	}
	printf("\033[0;32mName : %s\nwin : %d\nloss : %d\n", name, win, loss);
	game();
	return 0;
}
int game(void) {
	while (2 > 1) {
		char n2;
		printf("\033[0;32mpleas select an option :\n1 : esy(9*9/bomb:10)\n2 : mediom(12*12/bomb:20)\n3 : Menu\n");
		scanf("%c", &n2);
		scanf("%c", &n2);
		system("cls");
		if (n2 == '1') {
			map9();
		}
		else if (n2 == '2') {
			map12();
		}
		else if (n2 == '3') {
			char n1;
			printf("\033[0;32mName : %s\nwin : %d\nloss : %d\n", name, win, loss);
			while (3 > 1) {
				printf("\033[0;32mPleas select an option :\n1 : Change Name\n2 : Play\n");
				scanf("%c", &n1);
				scanf("%c", &n1);
				system("cls");
				if (n1 == '1') {
					printf("\033[0;32mPleas enter new Name :\n");
					gets_s(name);
					gets_s(name);
					system("cls");
				}
				else if (n1 == '2') {
					game();
				}
				else {
					printf("\033[0;31mincorrect input!!\n");
				}
			}
		}
		else {
			printf("\033[0;31mincorrect input!!\n");
		}
	}
	return 0;
}
int map9(void) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			map19[i][j] = 0;
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			map39[i][j] = '_';
		}
	}
	srand(time(NULL));
	int i = 0;
	int j = 0;
	int c = 0;
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0;
	while (2 > 1) {
		while (c < 10) {
			i = (rand() % 9);
			j = (rand() % 9);
			if (map19[i][j] != 1) {
				c++;
				map19[i][j] = 1;
				switch (j) {
				case 0:
					c1++;
					break;
				case 1:
					c2++;
					break;
				case 2:
					c3++;
					break;
				case 3:
					c4++;
					break;
				case 4:
					c5++;
					break;
				case 5:
					c6++;
					break;
				case 6:
					c7++;
					break;
				case 7:
					c8++;
					break;
				case 8:
					c9++;
					break;
				}
			}
		}
		if (c1 <= 3 || c2 <= 3 || c3 <= 3 || c4 <= 3 || c5 <= 3 || c6 <= 3 || c7 <= 3 || c8 <= 3 || c9 <= 3) {
			break;
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int d1 = 0, d2 = 0;
			if (map19[i][j] == 1)
				map29[i][j] = 'B';
			else {
				if (i != 0 && j != 0) {
					if (map19[i - 1][j - 1] == 1)
						d2++;
					if (map19[i - 1][j] == 1)
						d2++;
					if (map19[i - 1][j + 1] == 1)
						d2++;
					if (map19[i][j + 1] == 1)
						d2++;
					if (map19[i + 1][j + 1] == 1)
						d2++;
					if (map19[i + 1][j] == 1)
						d2++;
					if (map19[i + 1][j - 1] == 1)
						d2++;
					if (map19[i][j - 1] == 1)
						d2++;
					map29[i][j] = '0' + d2;
				}
				else if (i == 0 && j != 0 && j != 8) {
					if (map19[i][j + 1] == 1)
						d2++;
					if (map19[i + 1][j + 1] == 1)
						d2++;
					if (map19[i + 1][j] == 1)
						d2++;
					if (map19[i + 1][j - 1] == 1)
						d2++;
					if (map19[i][j - 1] == 1)
						d2++;
					map29[i][j] = '0' + d2;
				}
				else if (i == 0 && j == 0) {
					if (map19[i][j + 1] == 1)
						d2++;
					if (map19[i + 1][j + 1] == 1)
						d2++;
					if (map19[i + 1][j] == 1)
						d2++;
					map29[i][j] = '0' + d2;
				}
				else if (i != 0 && i != 8 && j == 0) {
					if (map19[i - 1][j] == 1)
						d2++;
					if (map19[i - 1][j + 1] == 1)
						d2++;
					if (map19[i][j + 1] == 1)
						d2++;
					if (map19[i + 1][j + 1] == 1)
						d2++;
					if (map19[i + 1][j] == 1)
						d2++;
					map29[i][j] = '0' + d2;
				}
				else if (i == 8 && j == 0) {
					if (map19[i - 1][j] == 1)
						d2++;
					if (map19[i - 1][j + 1] == 1)
						d2++;
					if (map19[i][j + 1] == 1)
						d2++;
					map29[i][j] = '0' + d2;
				}
				else if (i == 8 && j != 0 && j != 8) {
					if (map19[i - 1][j - 1] == 1)
						d2++;
					if (map19[i - 1][j] == 1)
						d2++;
					if (map19[i - 1][j + 1] == 1)
						d2++;
					if (map19[i][j + 1] == 1)
						d2++;
					if (map19[i][j - 1] == 1)
						d2++;
					map29[i][j] = '0' + d2;
				}
				else if (i == 8 && j == 8) {
					if (map19[i - 1][j - 1] == 1)
						d2++;
					if (map19[i - 1][j] == 1)
						d2++;
					if (map19[i][j - 1] == 1)
						d2++;
					map29[i][j] = '0' + d2;
				}
				else if (i != 0 && i != 8 && j == 8) {
					if (map19[i - 1][j - 1] == 1)
						d2++;
					if (map19[i - 1][j] == 1)
						d2++;
					if (map19[i + 1][j] == 1)
						d2++;
					if (map19[i + 1][j - 1] == 1)
						d2++;
					if (map19[i][j - 1] == 1)
						d2++;
					map29[i][j] = '0' + d2;
				}
				else if (i == 0 && j == 8) {
					if (map19[i + 1][j] == 1)
						d2++;
					if (map19[i + 1][j - 1] == 1)
						d2++;
					if (map19[i][j - 1] == 1)
						d2++;
					map29[i][j] = '0' + d2;
				}
			}
		}
	}
	int b = 1;
	printf("\033[0;34m      1      2      3      4      5      6      7      8      9\n\n\n");
	for (int i = 0; i < 9; i++) {
		printf("\033[0;34m%d    ", b);
		b++;
		for (int j = 0; j < 9; j++) {
			printf("\033[0;36m|%c|    ", map39[i][j]);
		}
		printf("\n\n\n");
	}
	int x;
	int y;
	char side;
	while (2 > 1) {
		printf("\033[0;32mPleas enter your point :\n");
	ser: {
		scanf("%d\n%d\n", &x, &y);
		scanf("%c", &side);
		if (side == 'R' && flag9 == 0) {
			goto der;
		}
		else if (map39[x - 1][y - 1] == 'F') {
			goto der;
		}
		}
	if (x > 9 || x < 1 || y > 9 || y < 1 || (side != 'L' && side != 'R') || map39[x][y] == 'F') {
	der: {
		printf("\033[0;31mincorrect input!!\n");
		printf("\033[0;32mPleas enter correct point :\n");
		goto ser;
		}
	}
	system("cls");
	if (map29[x - 1][y - 1] == 'B' && side == 'L') {
		int b = 1;
		printf("\033[0;34m      1      2      3      4      5      6      7      8      9\n\n\n");
		for (int i = 0; i < 9; i++) {
			printf("\033[0;34m%d    ", b);
			b++;
			for (int j = 0; j < 9; j++) {
				if (map29[i][j] == 'B') {
					map39[i][j] = map29[i][j];
					printf("|\U0001F4A3|   ");
				}
				else if (map29[i][j] == 'F') {
					printf("|\U0001F6A9|   ");
				}
				else
					printf("\033[0;36m|%c|    ", map39[i][j]);
			}
			printf("\n\n\n");
		}
		printf("\033[0;35mUnfortunately you lost\n");
		loss++;
		return 0;
	}
	else if (map29[x - 1][y - 1] == '0' && side == 'L') {
		cleaner9(x, y);
		int b = 1;
		printf("\033[0;34m      1      2      3      4      5      6      7      8      9\n\n\n");
		for (int i = 0; i < 9; i++) {
			printf("\033[0;34m%d    ", b);
			b++;
			for (int j = 0; j < 9; j++) {
				if (map39[i][j] == 'B') {
					printf("|\U0001F4A3|   ");
				}
				else if (map39[i][j] == 'F') {
					printf("|\U0001F6A9|   ");
				}
				else
					printf("\033[0;36m|%c|    ", map39[i][j]);
			}
			printf("\n\n\n");
		}
	}
	else if (map29[x - 1][y - 1] == 'B' && side == 'R') {
		int b = 1;
		printf("\033[0;34m      1      2      3      4      5      6      7      8      9\n\n\n");
		for (int i = 0; i < 9; i++) {
			printf("\033[0;34m%d    ", b);
			b++;
			for (int j = 0; j < 9; j++) {
				if (i == x - 1 && j == y - 1)
					map39[i][j] = 'F';
				if (map39[i][j] == 'B') {
					printf("|\U0001F4A3|   ");
				}
				else if (map39[i][j] == 'F') {
					printf("|\U0001F6A9|   ");
				}
				else
					printf("\033[0;36m|%c|    ", map39[i][j]);
			}
			printf("\n\n\n");
		}
		bomb9--;
		flag9--;
		if (bomb9 == 0) {
			printf("\033[0;33myou won\n");
			win++;
			return 0;
		}
	}
	else if (map29[x - 1][y - 1] == '0' && side == 'R') {
		int b = 1;
		printf("\034[0;32m      1      2      3      4      5      6      7      8      9\n\n\n");
		for (int i = 0; i < 9; i++) {
			printf("\033[0;34m%d    ", b);
			b++;
			for (int j = 0; j < 9; j++) {
				if (i == x - 1 && j == y - 1)
					map39[i][j] = 'F';
				if (map39[i][j] == 'B') {
					printf("|\U0001F4A3|   ");
				}
				else if (map39[i][j] == 'F') {
					printf("|\U0001F6A9|   ");
				}
				else
					printf("\033[0;36m|%c|    ", map39[i][j]);
			}
			printf("\n\n\n");
		}
		flag9--;
	}
	else if (map29[x - 1][y - 1] != 'B' && map29[x - 1][y - 1] != '0' && side == 'L') {
		int b = 1;
		printf("\033[0;34m      1      2      3      4      5      6      7      8      9\n\n\n");
		for (int i = 0; i < 9; i++) {
			printf("\033[0;34m%d    ", b);
			b++;
			for (int j = 0; j < 9; j++) {
				if (x - 1 == i && y - 1 == j)
					map39[i][j] = map29[i][j];
				if (map39[i][j] == 'B') {
					printf("|\U0001F4A3|   ");
				}
				else if (map39[i][j] == 'F') {
					printf("|\U0001F6A9|   ");
				}
				else
					printf("\033[0;36m|%c|    ", map39[i][j]);
			}
			printf("\n\n\n");
		}
	}
	else if (map29[x - 1][y - 1] != 'B' && map29[x - 1][y - 1] != '0' && side == 'R') {
		int b = 1;
		printf("\033[0;34m      1      2      3      4      5      6      7      8      9\n\n\n");
		for (int i = 0; i < 9; i++) {
			printf("\033[0;34m%d    ", b);
			b++;
			for (int j = 0; j < 9; j++) {
				if (x - 1 == i && y - 1 == j)
					map39[i][j] = 'F';
				if (map39[i][j] == 'B') {
					printf("|\U0001F4A3|   ");
				}
				else if (map39[i][j] == 'F') {
					printf("|\U0001F6A9|   ");
				}
				else
					printf("\033[0;36m|%c|    ", map39[i][j]);
			}
			printf("\n\n\n");
		}
		flag9--;
	}
	}
	return 0;
}
int map12(void) {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			map112[i][j] = 0;
		}
	}
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			map312[i][j] = '_';
		}
	}
	srand(time(NULL));
	int i = 0;
	int j = 0;
	int c = 0;
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0, c10 = 0, c11 = 0, c12 = 0;
	while (2 > 1) {
		while (c < 20) {
			i = (rand() % 12);
			j = (rand() % 12);
			if (map112[i][j] != 1) {
				c++;
				map112[i][j] = 1;
				switch (j) {
				case 0:
					c1++;
					break;
				case 1:
					c2++;
					break;
				case 2:
					c3++;
					break;
				case 3:
					c4++;
					break;
				case 4:
					c5++;
					break;
				case 5:
					c6++;
					break;
				case 6:
					c7++;
					break;
				case 7:
					c8++;
					break;
				case 8:
					c9++;
					break;
				case 9:
					c10++;
					break;
				case 10:
					c11++;
					break;
				case 11:
					c12++;
					break;
				}
			}
		}
		if (c1 <= 3 || c2 <= 3 || c3 <= 3 || c4 <= 3 || c5 <= 3 || c6 <= 3 || c7 <= 3 || c8 <= 3 || c9 <= 3 || c10 <= 3 || c11 <= 3 || c12 <= 3) {
			break;
		}
	}
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			int d1 = 0, d2 = 0;
			if (map112[i][j] == 1)
				map212[i][j] = 'B';
			else {
				if (i != 0 && j != 0) {
					if (map112[i - 1][j - 1] == 1)
						d2++;
					if (map112[i - 1][j] == 1)
						d2++;
					if (map112[i - 1][j + 1] == 1)
						d2++;
					if (map112[i][j + 1] == 1)
						d2++;
					if (map112[i + 1][j + 1] == 1)
						d2++;
					if (map112[i + 1][j] == 1)
						d2++;
					if (map112[i + 1][j - 1] == 1)
						d2++;
					if (map112[i][j - 1] == 1)
						d2++;
					map212[i][j] = '0' + d2;
				}
				else if (i == 0 && j != 0 && j != 11) {
					if (map112[i][j + 1] == 1)
						d2++;
					if (map112[i + 1][j + 1] == 1)
						d2++;
					if (map112[i + 1][j] == 1)
						d2++;
					if (map112[i + 1][j - 1] == 1)
						d2++;
					if (map112[i][j - 1] == 1)
						d2++;
					map212[i][j] = '0' + d2;
				}
				else if (i == 0 && j == 0) {
					if (map112[i][j + 1] == 1)
						d2++;
					if (map112[i + 1][j + 1] == 1)
						d2++;
					if (map112[i + 1][j] == 1)
						d2++;
					map212[i][j] = '0' + d2;
				}
				else if (i != 0 && i != 11 && j == 0) {
					if (map112[i - 1][j] == 1)
						d2++;
					if (map112[i - 1][j + 1] == 1)
						d2++;
					if (map112[i][j + 1] == 1)
						d2++;
					if (map112[i + 1][j + 1] == 1)
						d2++;
					if (map112[i + 1][j] == 1)
						d2++;
					map212[i][j] = '0' + d2;
				}
				else if (i == 11 && j == 0) {
					if (map112[i - 1][j] == 1)
						d2++;
					if (map112[i - 1][j + 1] == 1)
						d2++;
					if (map112[i][j + 1] == 1)
						d2++;
					map212[i][j] = '0' + d2;
				}
				else if (i == 11 && j != 0 && j != 8) {
					if (map112[i - 1][j - 1] == 1)
						d2++;
					if (map112[i - 1][j] == 1)
						d2++;
					if (map112[i - 1][j + 1] == 1)
						d2++;
					if (map112[i][j + 1] == 1)
						d2++;
					if (map112[i][j - 1] == 1)
						d2++;
					map212[i][j] = '0' + d2;
				}
				else if (i == 11 && j == 11) {
					if (map112[i - 1][j - 1] == 1)
						d2++;
					if (map112[i - 1][j] == 1)
						d2++;
					if (map112[i][j - 1] == 1)
						d2++;
					map212[i][j] = '0' + d2;
				}
				else if (i != 0 && i != 11 && j == 11) {
					if (map112[i - 1][j - 1] == 1)
						d2++;
					if (map112[i - 1][j] == 1)
						d2++;
					if (map112[i + 1][j] == 1)
						d2++;
					if (map112[i + 1][j - 1] == 1)
						d2++;
					if (map112[i][j - 1] == 1)
						d2++;
					map212[i][j] = '0' + d2;
				}
				else if (i == 0 && j == 11) {
					if (map112[i + 1][j] == 1)
						d2++;
					if (map112[i + 1][j - 1] == 1)
						d2++;
					if (map112[i][j - 1] == 1)
						d2++;
					map212[i][j] = '0' + d2;
				}
			}
		}
	}
	int b = 1;
	printf("\033[0;34m      1      2      3      4      5      6      7      8      9     10     11     12\n\n\n");
	for (int i = 0; i < 12; i++) {
		if (b >= 10) {
			printf("\033[0;34m%d   ", b);
		}
		else {
			printf("\033[0;34m%d    ", b);
		}
		b++;
		for (int j = 0; j < 12; j++) {
			printf("\033[0;36m|%c|    ", map312[i][j]);
		}
		printf("\n\n\n");
	}
	int x;
	int y;
	char side;
	while (2 > 1) {
		printf("\033[0;32mPleas enter your point :\n");
	ser: {
		scanf("%d\n%d\n", &x, &y);
		scanf("%c", &side);
		if (side == 'R' && flag9 == 0) {
			goto der;
		}
		else if (map312[x - 1][y - 1] == 'F') {
			goto der;
		}
		}
	if (x > 12 || x < 1 || y > 12 || y < 1 || (side != 'L' && side != 'R') || map312[x][y] == 'F') {
	der: {
		printf("\033[0;31mincorrect input!!\n");
		printf("\033[0;32mPleas enter correct point :\n");
		goto ser;
		}
	}
	system("cls");
	if (map212[x - 1][y - 1] == 'B' && side == 'L') {
		int b = 1;
		printf("\033[0;34m      1      2      3      4      5      6      7      8      9     10     11     12\n\n\n");
		for (int i = 0; i < 12; i++) {
			if (b >= 10) {
				printf("\033[0;34m%d   ", b);
			}
			else {
				printf("\033[0;34m%d    ", b);
			}
			b++;
			for (int j = 0; j < 12; j++) {
				if (map212[i][j] == 'B') {
					map312[i][j] = map212[i][j];
					printf("|\U0001F4A3|   ");
				}
				else if (map212[i][j] == 'F') {
					printf("|\U0001F6A9|   ");
				}
				else
					printf("\033[0;36m|%c|    ", map312[i][j]);
			}
			printf("\n\n\n");
		}
		printf("\033[0;35mUnfortunately you lost\n");
		loss++;
		return 0;
	}
	else if (map212[x - 1][y - 1] == '0' && side == 'L') {
		cleaner12(x, y);
		int b = 1;
		printf("\033[0;34m      1      2      3      4      5      6      7      8      9     10     11     12\n\n\n");
		for (int i = 0; i < 12; i++) {
			if (b >= 10) {
				printf("\033[0;34m%d   ", b);
			}
			else {
				printf("\033[0;34m%d    ", b);
			}
			b++;
			for (int j = 0; j < 12; j++) {
				if (map312[i][j] == 'B') {
					printf("|\U0001F4A3|   ");
				}
				else if (map312[i][j] == 'F') {
					printf("|\U0001F6A9|   ");
				}
				else
					printf("\033[0;36m|%c|    ", map312[i][j]);
			}
			printf("\n\n\n");
		}
	}
	else if (map212[x - 1][y - 1] == 'B' && side == 'R') {
		int b = 1;
		printf("\033[0;34m      1      2      3      4      5      6      7      8      9     10     11     12\n\n\n");
		for (int i = 0; i < 12; i++) {
			if (b >= 10) {
				printf("\033[0;34m%d   ", b);
			}
			else {
				printf("\033[0;34m%d    ", b);
			}
			b++;
			for (int j = 0; j < 12; j++) {
				if (i == x - 1 && j == y - 1)
					map312[i][j] = 'F';
				if (map312[i][j] == 'B') {
					printf("|\U0001F4A3|   ");
				}
				else if (map312[i][j] == 'F') {
					printf("|\U0001F6A9|   ");
				}
				else
					printf("\033[0;36m|%c|    ", map312[i][j]);
			}
			printf("\n\n\n");
		}
		bomb12--;
		flag12--;
		if (bomb12 == 0) {
			printf("\033[0;33myou won\n");
			win++;
			return 0;
		}
	}
	else if (map212[x - 1][y - 1] == '0' && side == 'R') {
		int b = 1;
		printf("\034[0;32m      1      2      3      4      5      6      7      8      9     10     11     12\n\n\n");
		for (int i = 0; i < 12; i++) {
			if (b >= 10) {
				printf("\033[0;34m%d   ", b);
			}
			else {
				printf("\033[0;34m%d    ", b);
			}
			b++;
			for (int j = 0; j < 12; j++) {
				if (i == x - 1 && j == y - 1)
					map312[i][j] = 'F';
				if (map312[i][j] == 'B') {
					printf("|\U0001F4A3|   ");
				}
				else if (map312[i][j] == 'F') {
					printf("|\U0001F6A9|   ");
				}
				else
					printf("\033[0;36m|%c|    ", map312[i][j]);
			}
			printf("\n\n\n");
		}
		flag12--;
	}
	else if (map212[x - 1][y - 1] != 'B' && map212[x - 1][y - 1] != '0' && side == 'L') {
		int b = 1;
		printf("\033[0;34m      1      2      3      4      5      6      7      8      9     10     11     12\n\n\n");
		for (int i = 0; i < 12; i++) {
			if (b >= 10) {
				printf("\033[0;34m%d   ", b);
			}
			else {
				printf("\033[0;34m%d    ", b);
			}
			b++;
			for (int j = 0; j < 12; j++) {
				if (x - 1 == i && y - 1 == j)
					map312[i][j] = map212[i][j];
				if (map312[i][j] == 'B') {
					printf("|\U0001F4A3|   ");
				}
				else if (map312[i][j] == 'F') {
					printf("|\U0001F6A9|   ");
				}
				else
					printf("\033[0;36m|%c|    ", map312[i][j]);
			}
			printf("\n\n\n");
		}
	}
	else if (map212[x - 1][y - 1] != 'B' && map212[x - 1][y - 1] != '0' && side == 'R') {
		int b = 1;
		printf("\033[0;34m      1      2      3      4      5      6      7      8      9     10     11     12\n\n\n");
		for (int i = 0; i < 12; i++) {
			if (b >= 10) {
				printf("\033[0;34m%d   ", b);
			}
			else {
				printf("\033[0;34m%d    ", b);
			}
			b++;
			for (int j = 0; j < 12; j++) {
				if (x - 1 == i && y - 1 == j)
					map312[i][j] = 'F';
				if (map312[i][j] == 'B') {
					printf("|\U0001F4A3|   ");
				}
				else if (map312[i][j] == 'F') {
					printf("|\U0001F6A9|   ");
				}
				else
					printf("\033[0;36m|%c|    ", map312[i][j]);
			}
			printf("\n\n\n");
		}
		flag12--;
	}
	}
	return 0;
}void cleaner9(int a, int b) {
	int x1;
	int y1;
	if (a < 1 || a>9 || b < 1 || b>9) {
		return;
	}
	for (int k = -1; k < 2; k++) {
		x1 = (a - 1) + k;
		for (int w = -1; w < 2; w++) {
			y1 = (b - 1) + w;
			if (y1 < 0 || y1>8 || x1 < 0 || x1 > 8) {
				continue;
			}
			if (x1 == (a - 1) && y1 == (b - 1) || map29[x1][y1] != '0') {
				map39[x1][y1] = map29[x1][y1];
			}
			else {
				if (map39[x1][y1] == map29[x1][y1]) {
				}
				else {
					cleaner9(x1 + 1, y1 + 1);
				}
			}
		}
	}
}
void cleaner12(int a, int b) {
	int x1;
	int y1;
	if (a < 1 || a>12 || b < 1 || b>12) {
		return;
	}
	for (int k = -1; k < 2; k++) {
		x1 = (a - 1) + k;
		for (int w = -1; w < 2; w++) {
			y1 = (b - 1) + w;
			if (y1 < 0 || y1>11 || x1 < 0 || x1 > 11) {
				continue;
			}
			if (x1 == (a - 1) && y1 == (b - 1) || map212[x1][y1] != '0') {
				map312[x1][y1] = map212[x1][y1];
			}
			else {
				if (map312[x1][y1] == map212[x1][y1]) {
				}
				else {
					cleaner12(x1 + 1, y1 + 1);
				}
			}
		}
	}
}