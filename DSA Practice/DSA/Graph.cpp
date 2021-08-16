#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
int arr[10000008];

class Graph
{
    int v;
    list<int> *l;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void AddEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printAdjList()
    {
        for (int i = 0; i < v; i++)
        {
            cout << "Vertex " << i << "-->";
            for (int nbr : l[i])
            {
                cout << nbr << ",";
            }
            cout << "\n";
        }
    }
};

class GRAPH
{ // Adj List
    unordered_map<string, list<pair<string, int>>> l;

public:
    void AddEdgelist(string x, string y, bool bdr, int wt)
    {
        l[x].push_back(make_pair(y, wt));
        if (bdr)
        {
            l[y].push_back(make_pair(x, wt));
        }
    }

    void printAdjList()
    {
        for (auto p : l)
        {
            string city = p.first;
            list<pair<string, int>> nbrs = p.second;
            cout << "City " << city << "-->";
            for (auto nbr : nbrs)
            {
                string dest = nbr.first;
                int dist = nbr.second;

                cout << "(" << dest << " " << dist << ") ,";
            }
            cout << "\n";
        }
    }
};

template <typename T>
class graph
{
    map<T, list<T>> l;

public:
    void AddEdgelist(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src)
    {
        map<T, bool> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T node = q.front();
            cout << node << " ";
            q.pop();

            for (auto nbr : l[node])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    // mark that nbr as visited
                    visited[nbr] = true;
                }
            }
        }
    }

    void dfs_helper(T src, map<T, bool> &visited)
    {
        cout << src << " ";
        visited[src]=true;
        // go to all nbr of that node that is not is not visited
        for (T nbr : l[src])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited);
            }
        }
    }

    void dfs(T src)
    {
        map<T, bool> visited;
        // mark all the nodes as not visited initially
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }
        // call the helper function
        dfs_helper(src,visited);
    }
};

int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    graph<int> g;
    g.AddEdgelist(0, 1);
    g.AddEdgelist(1, 2);
    g.AddEdgelist(2, 3);
    g.AddEdgelist(3, 4);
    g.AddEdgelist(4, 5);
    // g.bfs(0);
    g.bfs(1);

    // Graph g(4);
    // g.AddEdge(0, 1);
    // g.AddEdge(0, 2);
    // g.AddEdge(1, 2);
    // g.AddEdge(2, 3);
    // g.printAdjList();

    // GRAPH g;
    // g.AddEdgelist("A", "B", true, 20);
    // g.AddEdgelist("B", "D", true, 40);
    // g.AddEdgelist("A", "C", true, 10);
    // g.AddEdgelist("C", "D", true, 40);
    // g.AddEdgelist("A", "D", false, 50);
    // g.printAdjList();
    return 0;

    // int n;
    // cin >> n;
    // int graph[n][n];
    // graph[0][1]=true;
    // graph[0][2]=true;
    // graph[1][2]=true;
    // graph[2][3]=true;
    // graph[3][1]=true;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cin >> graph[i][j];
    //     }
    // }
    // cout << "IF THIS A DIRECTIONAL GRAPH"
    //      << "\n";
    // int edges = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (graph[i][j] > 0)
    //         {
    //             edges++;
    //             cout << i << "--->" << j << "  Weight  " << graph[i][j] << "\n";
    //         }
    //     }
    // }
    // cout << "No. of Edges in the graph  " << edges;
}
