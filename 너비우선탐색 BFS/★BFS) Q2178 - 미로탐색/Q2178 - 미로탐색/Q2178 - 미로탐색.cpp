#include <iostream>
#include <queue>
using namespace std;

#define MAX_N 101
struct Point
{
    int x, y, dist;
};
int d[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int n, m;
char map[MAX_N][MAX_N];      // 1: 이동가능 , 0: 이동불가
                             // char 배열이여야 한줄 입력 가능!!

int BFS(int, int);

int main()
{
    cin >> n >> m;           // n: 세로 (x) , m: 가로(y)  ---> 콘솔 좌표 헷갈린다!! 주의!!
    for (int i = 0; i < n; i++)
    {
        cin >> map[i];
    }

    cout << BFS(0, 0);

    return 0;
}

int BFS(int x, int y)
{
    // <<<< "너비 우선 탐색 (BFS)" 알고리즘 >>>>

    bool visited[MAX_N][MAX_N] = { false };
    queue<Point> myqueue;
    visited[x][y] = true;
    myqueue.push({ x,y,0 });

    while (!myqueue.empty())
    {
        Point curr = myqueue.front(); //이동시킬 위치 새롭게 선언

        myqueue.pop(); //기존 위치 제거

        if (curr.x == n - 1 && curr.y == m - 1)
        {
            return curr.dist + 1;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = curr.x + d[i][0];
            int ny = curr.y + d[i][1];

            if (nx < 0 || nx > n -1 || ny < 0 || ny > m-1) continue;

            if (visited[nx][ny] == true) continue;

            if (map[nx][ny] != '1') continue;

            visited[nx][ny] = true;
            myqueue.push({ nx, ny, curr.dist + 1 });
        }
    }
    return -1;
}