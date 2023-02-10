#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    vector<pair<string, string>> E;
    
    set<string> S;
    map<string, int> id;
    for (int i = 1; i <= n; i++) {
        string u, v; char op;
        cin >> u >> op >> v;
        S.insert(u); S.insert(v);
        if (op == '<') swap(u, v);
        E.push_back({u, v});
    }
    
    {
        n = S.size();
        vector<string> N(S.begin(), S.end());
        for (int i = 0; i < n; i++)
            id[N[i]] = i;
    }
    
    vector<vector<int>> adj(n);
    for (auto &e: E) 
        adj[id[e.first]].push_back(id[e.second]);
    
    vector<int> visited(n, 0);
    function<void(int)> dfs = [&](int u){
        visited[u] = 1;
        for (auto &v: adj[u]) {
            if (visited[v] == 1) {
                cout << "impossible";
                exit(0);
            }
            else if (visited[v] == 0) dfs(v);
        }
        visited[u] = 2;
    };
    
    for (int i = 0; i < n; i++)
        if (visited[i] == 0) dfs(i);
    
    cout << "possible";
    return 0;
}
