#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

#define MAX 52
using namespace std;

int n, m;
int initmap[MAX][MAX];
int dirs[9][2] = { {0,0},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1} };//y,x순
bool cloundMap[MAX][MAX] = { false };
vector<pair<int, int>> movings;
vector<pair<int, int>> clouds;//구름 좌표들
queue<pair<int, int>> rained;

void MovingClouds(pair<int, int> move) //방향이랑 거리
{
	int cloundsize = clouds.size();
	for (int i = 0; i < cloundsize; i++)
	{
		clouds[i].first += dirs[move.first][0] * move.second;
		clouds[i].second += dirs[move.first][1] * move.second;

		if (clouds[i].first <= 0)
		{
			//clouds[i].first
			while(clouds[i].first<=0)
				clouds[i].first += n;
		}

		if (clouds[i].first > n)
		{
			while(clouds[i].first>n)
				clouds[i].first -= n;
		}

		if (clouds[i].second <= 0)
		{
			while(clouds[i].second <= 0)
				clouds[i].second += n;

		}

		if (clouds[i].second > n)
		{
			while(clouds[i].second > n)
				clouds[i].second -=n;
		}
	}
}
void Rain()
{
	int cloundsize = clouds.size();
	for (int i = 0; i < cloundsize; i++)
	{
		if (initmap[clouds[i].first][clouds[i].second] == -1)
			continue;

		initmap[clouds[i].first][clouds[i].second]++;
		rained.push(clouds[i]);
		cloundMap[clouds[i].first][clouds[i].second] = true;
	}
}
void CopyWaterBug()
{
	while (rained.size() > 0)
	{
		pair<int, int> raininfo = rained.front();
		rained.pop();
		int cnt = 0;
		for (int i = 2 ; i <= 8; i += 2)
		{
			auto val = initmap[raininfo.first+dirs[i][0]][raininfo.second+dirs[i][1]];
			if (val != -1 && val > 0)
				cnt++;
		}
		initmap[raininfo.first][raininfo.second] += cnt;
	}
}
void CreateClouds()
{
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			if (!cloundMap[y][x] && initmap[y][x] >= 2)
			{
				initmap[y][x] -= 2;
				clouds.push_back(pair<int, int>(y, x));
			}

			cloundMap[y][x] = false;
		}
	}
}
void Bibaragi(pair<int, int> moving)
{
	MovingClouds(moving);
	Rain();
	clouds.clear();
	CopyWaterBug();
	CreateClouds();
}
int main()
{
	auto file = freopen("test.txt", "r", stdin);

	for (int y = 0; y < MAX; y++)
	{
		for (int x = 0; x < MAX; x++)
		{
			initmap[y][x] = -1;
		}
	}

	cin >> n >> m;

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			cin >> initmap[y][x];
		}
	}

	movings.resize(m);
	for (int i = 0; i < m; i++)
	{
		cin >> movings[i].first >> movings[i].second;
	}

	//create cloudmap
	clouds.push_back(pair<int, int>(n - 1, 1));
	clouds.push_back(pair<int, int>(n - 1, 2));
	clouds.push_back(pair<int, int>(n, 1));
	clouds.push_back(pair<int, int>(n, 2));

	for (int i = 0; i < m; i++)
	{
		Bibaragi(movings[i]);
	}

	int res = 0;

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			res += initmap[y][x];
		}
	}

	cout << res;
	return 0;
}
