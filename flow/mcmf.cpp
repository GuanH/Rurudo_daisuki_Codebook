struct MCMF {
    #define SZ(x) (int)(x.size())
    struct Edge {
        int v, f, re, c;
    };
    vector<vector<Edge>> E;
    vector<int> dis, x, y;
    int n, s, t;
    MCMF(int nn, int ss, int tt) {
        n = nn; s = ss; t = tt;
        E.resize(n);
        x.resize(n);
        y.resize(n);
    }
    void addEdge(int u, int v, int w, int c) {
        E[u].push_back({v, w, SZ(E[v]), c});
        E[v].push_back({u, 0, SZ(E[u]) - 1, -c});
    }
    bool spfa() {
        dis.assign(n, 0x3f3f3f3f);
        x.assign(n, -1);
        y.assign(n, -1);
        vector<bool> inq(n, false);
        queue<int> q;
        q.push(s);
        inq[s] = true;
        dis[s] = 0;
        while(q.size()) {
            int u = q.front(); q.pop();
            inq[u] = false;
            for(int i = 0; i < E[u].size(); i++) {
                auto& it = E[u][i];
                int v = it.v;
                if(it.f > 0 && dis[v] > dis[u] + it.c) {
                    dis[v] = dis[u] + it.c;
                    x[v] = u;
                    y[v] = i;
                    if(!inq[v]) {
                        q.push(v);
                        inq[v] = true;
                    }
                }
            }
        }
        return x[t] != -1;
    }
    pii solve() {
        int mf = 0, mc = 0;
        while(spfa()) {
            int nf = 0x3f3f3f3f;
            for(int i = t; i != s; i = x[i]) {
                nf = min(nf, E[x[i]][y[i]].f);
            }
            for(int i = t; i != s; i = x[i]) {
                auto& it = E[x[i]][y[i]];
                it.f -= nf;
                E[it.v][it.re].f += nf;
            }
            mf += nf;
            mc += nf * dis[t];
        }
        return {mf, mc};
    }
};