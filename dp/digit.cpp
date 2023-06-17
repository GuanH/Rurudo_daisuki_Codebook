ll dp[MXN_BIT][PRE_NUM][LIMIT][F0];
ll dfs(int i,int pre, bool lim, bool f0, const string& str){
    if(v[i][pre][f0][lim])  return dp[i][pre][f0][lim];
    v[i][pre][f0][lim] = true;
    
    if(i == str.size())
        return dp[i][pre][f0][lim] = 1;
    
    ll ret = 0, h = lim ? str[i] : '9';
    
    for(int j='0'; j<=h; j++){
        if(abs(j-pre)>=2 || f0){
            ret += dfs(i+1, j, j==h && lim, f0 && j=='0', str);
    }}
    return dp[i][pre][f0][lim] = ret;
}