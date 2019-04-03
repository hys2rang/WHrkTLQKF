#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 510;
enum DIR
{
	UP, DOWN, RIGHT, LEFT
};
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };//위,아래,오,왼
int downcycle[4][2] = { {1,0},{1,1},{1,2},{0,3} }; //아래
int upcycle[4][2] = { {-1,0},{-1,1},{-1,2},{0,3} }; //위
int leftcycle[4][2] = { {0,-1},{1,-1},{2,-1},{3,0} }; //왼
int rightcycle[4][2] = { {0,1},{1,1},{2,1},{3,0} };//오
int ans = -MAX * MAX;
int N, M;
int map[MAX][MAX] = { 0, };
int square(int x, int y);
int three_hor(int x, int y);
int three_ver(int x, int y);
int two1(int x, int y);
int two2(int x, int y);
int two3(int x, int y);
int two4(int x, int y);
int main()
{
	cin >> N >> M;

	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			map[i][j] = -1;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}	

	for (int i = 1; i <= N;i++) {
		for (int j = 1; j <= M; j++) {
			//정사각형 탐색
			ans = max(ans, square(i, j));
			ans = max(ans, three_hor(i, j));
			ans = max(ans, three_ver(i, j));
			ans = max(ans, two1(i, j));
			ans = max(ans, two2(i, j));
			ans = max(ans, two3(i, j));
			ans = max(ans, two4(i, j));
		}
	}

	cout << ans;
	return 0;
}
int square(int x, int y)
{
	int sum = map[x][y];
	int xx = x + dir[RIGHT][0];
	int yy = y + dir[RIGHT][1];
	sum += map[xx][yy];
	xx = x + dir[DOWN][0];
	yy = y + dir[DOWN][1];
	sum += map[xx][yy];
	xx += dir[RIGHT][0];
	yy += dir[RIGHT][1];
	sum += map[xx][yy];

	return sum;
}
int three_hor(int x, int y)
{
	int sum = map[x][y];
	int xx = x;
	int yy = y;
	for (int i = 0; i < 2; i++) {
		xx += dir[RIGHT][0];
		yy += dir[RIGHT][1];
		if (xx <= N && yy <= M) {
			sum += map[xx][yy];
		}
		else {
			return 0;
		}		
	}
	int buf = sum;
	for (int i = 0; i < 4; i++) {
		xx = x + upcycle[i][0];
		yy = y + upcycle[i][1];
		if (xx <= N && yy <= M) {
			buf = max(buf, sum + map[xx][yy]);
		}
	}
	for (int i = 0; i < 4; i++) {
		xx = x + downcycle[i][0];
		yy = y + downcycle[i][1];
		if (xx <= N && yy <= M) {
			buf = max(buf, sum + map[xx][yy]);
		}
	}
	return buf;
}
int three_ver(int x, int y)
{
	int sum = map[x][y];
	int xx = x;
	int yy = y;
	for (int i = 0; i < 2; i++) {
		xx += dir[DOWN][0];
		yy += dir[DOWN][1];
		if (xx <= N && yy <= M) {
			sum += map[xx][yy];
		}
		else {
			return 0;
		}
	}
	int buf = sum;
	for (int i = 0; i < 4; i++) {
		xx = x + leftcycle[i][0];
		yy = y + leftcycle[i][1];
		if (xx <= N && yy <= M) {
			buf = max(buf, sum + map[xx][yy]);
		}
	}
	for (int i = 0; i < 4; i++) {
		xx = x + rightcycle[i][0];
		yy = y + rightcycle[i][1];
		if (xx <= N && yy <= M) {
			buf = max(buf, sum + map[xx][yy]);
		}
	}
	return buf;
}
int two1(int x, int y)
{
	int sum = map[x][y];
	int xx = x + dir[DOWN][0];
	int yy = y + dir[DOWN][1];
	if (xx <= N && yy <= M) {
		sum += map[xx][yy];
	}
	else {
		return 0;
	}
	xx += dir[RIGHT][0];
	yy += dir[RIGHT][1];
	if (xx <= N && yy <= M) {
		sum += map[xx][yy];
	}
	else {
		return 0;
	}
	xx += dir[DOWN][0];
	yy += dir[DOWN][1];
	if (xx <= N && yy <= M) {
		sum += map[xx][yy];
	}
	else {
		return 0;
	}
	return sum;
}
int two2(int x, int y)
{
	int sum = map[x][y];
	int xx = x + dir[DOWN][0];
	int yy = y + dir[DOWN][1];
	if (xx <= N && yy <= M) {
		sum += map[xx][yy];
	}
	else {
		return 0;
	}
	xx += dir[LEFT][0];
	yy += dir[LEFT][1];
	if (xx <= N && yy <= M) {
		sum += map[xx][yy];
	}
	else {
		return 0;
	}
	xx += dir[DOWN][0];
	yy += dir[DOWN][1];
	if (xx <= N && yy <= M) {
		sum += map[xx][yy];
	}
	else {
		return 0;
	}
	return sum;
}
int two3(int x, int y)
{
	int sum = map[x][y];
	int xx = x + dir[LEFT][0];
	int yy = y + dir[LEFT][1];
	if (xx <= N && yy <= M) {
		sum += map[xx][yy];
	}
	else {
		return 0;
	}
	xx += dir[DOWN][0];
	yy += dir[DOWN][1];
	if (xx <= N && yy <= M) {
		sum += map[xx][yy];
	}
	else {
		return 0;
	}
	xx += dir[LEFT][0];
	yy += dir[LEFT][1];
	if (xx <= N && yy <= M) {
		sum += map[xx][yy];
	}
	else {
		return 0;
	}
	return sum;
}
int two4(int x, int y)
{
	int sum = map[x][y];
	int xx = x + dir[RIGHT][0];
	int yy = y + dir[RIGHT][1];
	if (xx <= N && yy <= M) {
		sum += map[xx][yy];
	}
	else {
		return 0;
	}
	xx += dir[DOWN][0];
	yy += dir[DOWN][1];
	if (xx <= N && yy <= M) {
		sum += map[xx][yy];
	}
	else {
		return 0;
	}
	xx += dir[RIGHT][0];
	yy += dir[RIGHT][1];
	if (xx <= N && yy <= M) {
		sum += map[xx][yy];
	}
	else {
		return 0;
	}
	return sum;
}
