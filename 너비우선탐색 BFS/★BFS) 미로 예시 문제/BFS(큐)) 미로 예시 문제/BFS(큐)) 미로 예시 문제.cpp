#include <iostream>
#include <queue>
using namespace std;

#define Max_N 10
struct Point
{
    int x, y, dist;
};
int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int n, map[Max_N][Max_N];

int BFS(int, int, int, int);
int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];          // 0: 이동가능, 1: 이동 X
        }
    }

    int st_x, st_y, ds_x, ds_y;
    cin >> st_x >> st_y >> ds_x >> ds_y;
    
    cout << BFS(st_x, st_y, ds_x, ds_y);
}

int BFS(int st_x, int st_y, int ds_x, int ds_y)
{
    bool visited[Max_N][Max_N] = { false };
    queue<Point> my;
    visited[st_x][st_y] = true;
    my.push({ st_x,st_y,0 });
    
    while (!my.empty())
    {   
        Point curr = my.front();
        my.pop();
        if (curr.x == ds_x && curr.y == ds_y)
            return curr.dist;

        for (int i = 0; i < 4; i++)
        {
            int nx = curr.x + d[i][0];
            int ny = curr.y + d[i][1];

            if (nx <0 || nx > n - 1 || ny <0 || ny >n - 1) continue;
            if (visited[nx][ny] == true) continue;
            if (map[nx][ny] == 1) continue;

            visited[nx][ny] = true;
            my.push({ nx,ny,curr.dist + 1 });
        }
    }
    return -1;
}