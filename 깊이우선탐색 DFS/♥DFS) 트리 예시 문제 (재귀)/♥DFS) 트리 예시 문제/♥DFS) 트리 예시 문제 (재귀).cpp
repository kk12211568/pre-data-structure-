#include <iostream>
using namespace std;

#define Max_N 10
int N, E;           // N: 노드의 개수, E: 간선의 개수
int tree[Max_N][Max_N];
bool visited[Max_N] = { false, };

void DFS(int);

int main()
{
    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;          // 간선 직접 입력
        tree[u][v] = 1;
        tree[v][u] = 1;
    }

    DFS(0);

    return 0;
}

void DFS(int node)
{
    visited[node] = true;
    cout << node << " ";

    for (int next = 0; next < N; next++)
    {
        if (!visited[next] && tree[node][next])
        {
            DFS(next);
        }
    }
}