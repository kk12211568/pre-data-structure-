#include <iostream>
#include <queue>
using namespace std;

struct Point
{
    int x, y;
};
int m, n;
int map[100][100];
int day[100][100] = { -1, };                // 0으로 하면 초기 익은 토마토랑 같은 취급됨
int d[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
queue<Point> q;

void tomato_bfs();
int max(int& x, int& y)
{
    if (x >= y) return x;
    else return  y;
}

int main()
{
    cin >> m >> n;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1)
            {
                q.push({ j,i }); day[i][j] = 0;
            }
        }
    }

    tomato_bfs();

    int result = 0;

    // *bfs 순환문이 언제 끝날지 모름! 그래서 날짜 맵을 따로 만들어야됨!*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result = max(day[i][j], result);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0 && day[i][j] == -1)
            {
                result = -1;
            }
            else continue;
        }
    }
    cout << result;
    return 0;
}

void tomato_bfs()
{
    bool visited[100][100] = { false, };
    while (!q.empty())
    {
        Point curr = q.front();
        visited[curr.y][curr.x] = true;

        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int nx = curr.x + d[i][0];
            int ny = curr.y + d[i][1];

            if (nx <0 || nx > m - 1 || ny <0 || ny > n - 1) continue;
            if (visited[ny][nx] == true) continue;
            if (map[ny][nx] == -1) continue;

            visited[ny][nx] = true;
            q.push({ nx,ny });

            //날짜 맵을 따로 만들어야됨.
            day[ny][nx] = day[curr.y][curr.x] + 1;
        }
    }
    
}