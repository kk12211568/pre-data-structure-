#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ly, lx, k;
int d[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int sq[100][4];                         // 좌표 값
bool occupied[100][100] = { false, };   // 격자 값
bool visited[100][100] = { false, };    // DFS 확인 시

int area; int num_of_area = 0;
vector<int> ans;

void DFS(int, int);

int main()
{
    cin >> ly >> lx >> k;

    for (int i = 0; i < k; i++)
    {   
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        sq[i][0] = x1;
        sq[i][1] = y1;
        sq[i][2] = x2;
        sq[i][3] = y2;

    }

    for (int i = 0; i < k; i++)
    {
        for (int c = sq[i][1]; c < sq[i][3]; c++)
        {
            for (int r = sq[i][0]; r < sq[i][2]; r++)
            {   
                if (occupied[c][r] == false)
                {
                    occupied[c][r] = true;
                }
            }
        }
    }

    for (int c = 0; c < ly; c++)
    {
        for (int r = 0; r < lx; r++)
        {      
            if (occupied[c][r] == false && visited[c][r] == false)
            {
                area = 0;
                DFS(r, c);
                ans.push_back(area);
                num_of_area++;
            }
            else continue;

        }
    }

    sort(ans.begin(), ans.end());

    cout << num_of_area << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

void DFS(int r, int c)
{   
    visited[c][r] = true;

    area++;

    for (int i = 0; i < 4; i++)
    {
        int nr = r + d[i][0];
        int nc = c + d[i][1];

        if (nr < 0 || nr >= lx || nc < 0 || nc >= ly) continue;
        if (visited[nc][nr] == true) continue;
        if (occupied[nc][nr] == true) continue;

        DFS(nr, nc);
    }

}