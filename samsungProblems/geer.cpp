#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int map[4][8];
int geer_turn[4] = { 0, };
void checkgeers(int geer, int dir)
{
	if (geer == -1 || geer == 4) {
		return;
	}
	geer_turn[geer] = dir;
	switch (geer)
	{
	case 0:
		if (!geer_turn[1] &&(map[0][2] != map[1][6])) {
			checkgeers(1, dir*(-1));
		}
		break;
	case 1:
		if (!geer_turn[0] && (map[1][6] != map[0][2])) {
			checkgeers(0, dir*(-1));
		}
		if (!geer_turn[2] && (map[1][2] != map[2][6])) {
			checkgeers(2, dir*(-1));
		}
		break;
	case 2:
		if (!geer_turn[1] && (map[2][6] != map[1][2])) {
			checkgeers(1, dir*(-1));
		}
		if (!geer_turn[3] && (map[2][2] != map[3][6])) {
			checkgeers(3, dir*(-1));
		}
		break;
	case 3:
		if (!geer_turn[2] && (map[2][2] != map[3][6])) {
			checkgeers(2, dir*(-1));
		}
		break;
	}
}
int getscore()
{
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (map[i][0]) {
			cnt += pow(2, i);
		}		
	}
	return cnt;
}
void clockwise(int arr[])
{
	int buf[8];
	for (int i = 0; i < 7; i++) {
		buf[i + 1] = arr[i];
	}
	buf[0] = arr[7];
	for (int i = 0; i < 8; i++) {
		arr[i] = buf[i];
	}
}
void countclockwise(int arr[])
{
	int buf[8];
	for (int i = 7; i > 0; i--) {
		buf[i - 1] = arr[i];
	}
	buf[7] = arr[0];
	for (int i = 0; i < 8; i++) {
		arr[i] = buf[i];
	}
}
int main()
{
	int k;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int geer, dir;
		scanf("%d %d", &geer, &dir);

		//회전해야 하는 기어들과 방향을 확인
		checkgeers(geer-1,dir);
		//회전
		for (int i = 0; i < 4; i++) {
			if (geer_turn[i] == 1) {
				clockwise(map[i]);
			}
			else if (geer_turn[i] == -1) {
				countclockwise(map[i]);
			}
		}
		for (int i = 0; i < 4; i++) {
			geer_turn[i] = 0;
		}
	}
	printf("%d", getscore());
	return 0;
}
