#include <iostream>
#include <string.h>
using namespace std;

int N;
char map[100][100];
int d[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
bool visited[100][100] = { false, };

void DFS(int,int,char);

int main()
{
    int normal_area = 0; int weakness_area = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> map[i];
    }


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == false) 
            {
                DFS(j, i, map[i][j]);
                normal_area++;
            }
        }
    }

    //적록색약
    memset(visited, false, sizeof(visited)); // string.h 의 초기화 함수

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 'R') map[i][j] = 'G';
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == false)
            {
                DFS(j, i, map[i][j]);
                weakness_area++;
            }
        }
    }
    cout << normal_area << " " << weakness_area;

    return 0;
}

void DFS(int x,int y, char color)
{   
    visited[y][x] = true;
    
    for (int i = 0; i < 4; i++)
    {
        int nx = x + d[i][0];
        int ny = y + d[i][1];

        if (nx<0 || nx > N - 1 || ny<0 || ny> N - 1) continue;
        if (visited[ny][nx] == true) continue;
        if (map[ny][nx] != color) continue;
        
        
        DFS(nx, ny, color);
    }

}
