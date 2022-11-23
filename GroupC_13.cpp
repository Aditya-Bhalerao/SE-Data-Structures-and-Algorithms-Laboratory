// Represent a given graph using adjacency matrix/list to perform DFS and using adjacency
// list to perform BFS. Use the map of the area around the college as the graph. Identify the
// prominent land marks as nodes and perform DFS and BFS on that.


#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// add the edge in graph
void edge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

// function for bfs traversal
void bfs(int s, vector<int> adj[], bool visit[])
{
    queue<int> q; // queue in STL
    q.push(s);
    visit[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        q.pop();
        // loop for traverse
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (!visit[adj[u][i]])
            {
                q.push(adj[u][i]);
                visit[adj[u][i]] = true;
            }
        }
    }
}
// function for dfs traversal
void dfs(int s, vector<int> adj[], bool visit[])
{
    stack<int> stk; // stack in STL
    stk.push(s);
    visit[s] = true;
    while (!stk.empty())
    {
        int u = stk.top();
        cout << u << " ";
        stk.pop();
        // loop for traverse
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (!visit[adj[u][i]])
            {
                stk.push(adj[u][i]);
                visit[adj[u][i]] = true;
            }
        }
    }
}


// main function
int main()
{
    int j = 0, k = 0;
    int size = 0;
    int n;
    cout << "Enter the size of the graph: ";
    cin >> n;
    vector<int> adj[n]; // vector of array to store the graph
    bool visit[n];      // array to check visit or not of a node
    // initially all node are unvisited
    for (int i = 0; i < n; i++)
    {
        visit[i] = false;
    }

    cout << "Enter the size of input:";
    cin >> size;
    // input for edges
    int egs = 1;
    for (int i = 0; i < size; i++)
    {
        if (j < n && k < n)
        {
            cout << "Enter edges: " << egs << ": ";
            cin >> j >> k;
            edge(adj, j, k);
            egs++;
        }
        else
        {
            return -1;
        }
    }

    cout << "BFS traversal is: ";
    // call bfs funtion
    bfs(0, adj, visit); // 1 is a starting point
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        visit[i] = false;
    }

    cout << "DFS traversal is: ";
    // call dfs function
    dfs(0, adj, visit);
}
