ll dfs(int u){
    vector<ll> h;
    subtree_sz[u] = 1;
    for(ll child : edge[u]){
        h.push_back(dfs(child));
        subtree_sz[u] += subtree_sz[child];
    }
    sort(h.begin(), h.end());
    ll ret = subtree_sz[u];
    for(ll v : h){
        ret = (ret * base + v) % MOD;
    }
    return ret;
}