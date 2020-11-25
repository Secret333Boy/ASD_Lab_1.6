#include <stdio.h>
#include <windows.h>
#include <unistd.h>

int main () {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	void gotoxy(int x, int y){
		COORD pos = {x, y};
		SetConsoleCursorPosition(hout, pos);
	}

	for (int i = 0; i <= 40; i++){
		for (int j = 24; j >= 0; j--){
			gotoxy(40 - i, i % 2 == 0 ? j : 24 - j);
			printf("*");
			usleep(500);

			gotoxy(41 + i, i % 2 == 0 ? 24 - j : j);
			printf("*");
			usleep(500);
		}
	}

	return 0;
}