struct Dinic {
	#define SZ(x) (int)(x.size())
	struct Edge {
		int v, f, re;
	};
	vector<vector<Edge>> E;
	vector<int> level;
	int n, s, t;
	Dinic(int nn, int ss, int tt) {
		n = nn; s = ss; t = tt;
		E.resize(n);
		level.resize(n);
	}
	void addEdge(int u, int v, int w) {
		E[u].push_back({v, w, SZ(E[v])});
		E[v].push_back({u, 0, SZ(E[u]) - 1});
	}
	bool bfs() {
		level.assign(n, 0);
		queue<int> q;
		q.push(s);
		level[s] = 1;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for(auto& it : E[u]) {
				int v = it.v;
				if(it.f > 0 && !level[v]) {
					level[v] = level[u] + 1;
					q.push(v);
				}
			}
		}
		return level[t];
	}
	int dfs(int u, int nf) {
		if(u == t) return nf;
		int ret = 0;
		for(auto& it : E[u]) {
			int v = it.v;
			if(it.f > 0 && level[v] == level[u] + 1) {
				int tem = dfs(v, min(nf, it.f));
				ret += tem; nf -= tem;
				it.f -= tem; E[v][it.re].f += tem;
				if(!nf) return ret;
			}
		}
		if(!ret) level[u] = 0;
		return ret;
	}
	int flow() {
		int ret = 0;
		while(bfs()) ret += dfs(s, 0x3f3f3f3f);
		return ret;
	}
};