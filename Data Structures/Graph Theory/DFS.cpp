#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
//DFS at every cell of a grid
ll edges, nodes;
int dir_row[] = {0, 1, 0, -1};
int dir_col[] = {1, 0, -1, 0};

bool vis[51][51];
void dfs(const vector<vector<char>> &grid, int x, int y, char c)
{
    nodes++;
    vis[x][y] = 1;
    for (int i{}; i < 4; i++)
    {
        int Nx = x + dir_row[i];
        int Ny = y + dir_col[i];
        if (Nx >= 0 && Nx < grid.size() && Ny >= 0 && Ny < grid[0].size() && grid[Nx][Ny] == c)
        {
            edges++;
            if (!vis[Nx][Ny])
                dfs(grid, Nx, Ny, grid[Nx][Ny]);
        }
    }
}
*/
/////////////////////////////////////////////////////////////
/*
// Determines the entryNode of the cyclic component
bitset<200006> vis;
ll entryNode = -1;
bool dfs(const vector<vector<ll>> &adj, ll node, ll prev)
{
    vis[node] = 1;
    for (int i{}; i < adj[node].size(); i++)
    {
        if (adj[node][i] != prev && vis[adj[node][i]])
        {
            entryNode = adj[node][i];
            return true;
        }
        else if (adj[node][i] != prev && !vis[adj[node][i]])
            if (dfs(adj, adj[node][i], node))
                return true;
    }
    return false;
}
// Calculates shortest path to enter a cyclic component
ll dfsCalc(const vector<vector<ll>> &adj, ll node)
{
    vis[node] = 1;
    ll minDist = 200005;
    for (int i{}; i < adj[node].size(); i++)
    {
        if (adj[node][i] == entryNode)
            return 1;
        if (!vis[adj[node][i]])
        {
            ll dist = dfsCalc(adj, adj[node][i]) + 1;
            minDist = min(minDist, dist);
        }
    }
    return minDist;
}
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
}