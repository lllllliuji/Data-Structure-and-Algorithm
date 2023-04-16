class Graph {
   public:
    int n;
    vector<vector<pair<int, int>>> g;
    Graph(int _n, vector<vector<int>>& edges) {
        n = _n;
        g.resize(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1], c = e[2];
            g[a].push_back({b, c});
        }
    }

    void addEdge(vector<int> edge) {
        int a = edge[0], b = edge[1], c = edge[2];
        g[a].push_back({b, c});
    }

    int shortestPath(int node1, int node2) {
        vector<int> dis(n, 0x3f3f3f3f);
        dis[node1] = 0;
        using E = pair<int, int>;
        priority_queue<E, vector<E>, greater<>> q;
        q.push({0, node1});
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            int du = t.first, u = t.second;
            if (dis[u] < du) continue;
            for (auto& e : g[u]) {
                int v = e.first, dv = e.second + du;
                if (dv < dis[v]) {
                    dis[v] = dv;
                    q.push({dv, v});
                }
            }
        }
        return dis[node2] == 0x3f3f3f3f ? -1 : dis[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */