#include <iostream>
#include <queue>
using namespace std;

#define MAX_N 50
struct Point
{
    int x, y, time;
    bool Water;
};
int d[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int n, m;
char map[MAX_N][MAX_N];
bool ans = false;
queue<Point> myqueue;

void BFS();

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> map[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == '*') myqueue.push({ j,i,0,true });
            if (map[i][j] == 'S') myqueue.push({ j,i,0,false });
        }
    }

    BFS();

    if (ans == false) cout << "KAKTUS";
    return 0;
}


void BFS()
{   

    bool visited[MAX_N][MAX_N] = { false };
    bool f_visited[MAX_N][MAX_N] = { false };

    while (!myqueue.empty())                    // 두 객체를 동시에 실행 -> 함수 따로하면 안됨! (하나 다 하고, 다른거 함)
    {
        Point curr = myqueue.front();
        myqueue.pop();

        if (curr.Water == true)
        {
            f_visited[curr.y][curr.x] = true;

            for (int i = 0; i < 4; i++)
            {
                int nx = curr.x + d[i][0];
                int ny = curr.y + d[i][1];

                if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1) continue;
                if (f_visited[ny][nx] == true) continue;
                if (map[ny][nx] == 'X' || map[ny][nx] == 'D') continue;

                f_visited[ny][nx] = true;
                map[ny][nx] = '*';
                myqueue.push({ nx, ny, 0, true });
            }
        }

        if(curr.Water == false)
        {
            if (map[curr.y][curr.x] == 'D')
            {
                cout << curr.time;
                ans = true;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = curr.x + d[i][0];
                int ny = curr.y + d[i][1];

                if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1) continue;
                if (visited[ny][nx] == true) continue;
                if (map[ny][nx] == '*' || map[ny][nx] == 'X') continue;

                visited[ny][nx] = true;
                myqueue.push({ nx, ny, curr.time + 1,false });
            }
        }
    }
}
