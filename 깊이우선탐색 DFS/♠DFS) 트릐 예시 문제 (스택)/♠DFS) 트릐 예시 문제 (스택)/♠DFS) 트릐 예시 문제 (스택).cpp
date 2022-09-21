#include <iostream>
#include <stack>         // '큐'가 아닌 '스택'으로 하는 이유
using namespace std;     // '큐'로하면 같은 층위에 있는 노드가 동시에 다음과정을 함. (겹침)

#define Max_N 10
int N, E;
int tree[Max_N][Max_N];

void DFS(int);

int main()
{
    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u][v] = 1;
        tree[v][u] = 1;
    }

    DFS(0);

    return 0;
}

void DFS(int node)
{
    bool visited[Max_N] = { false, };

    stack<int> s;
    s.push(node);

    while (!s.empty())
    {
        int curr = s.top();
        s.pop();

        if (visited[curr] == true) continue;

        visited[curr] = true;
        cout << curr << " ";

        for (int next = 0; next < N; next++)
        {
            if (!visited[next] && tree[curr][next])
            {
                s.push(next);
            }
        }
    }

}