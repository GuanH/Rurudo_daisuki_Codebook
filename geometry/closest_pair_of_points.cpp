#include<bits/stdc++.h>
#define int long long
using namespace std;
using ld = long double;
const int mod = 1e9+7;
struct pt{
    int x,y;
    int id;
    ld dis(const pt& rhs){
        return sqrt((x-rhs.x)*(x-rhs.x)+(y-rhs.y)*(y-rhs.y));
    }
};
signed main(){
    int n;
    cin>>n;
    vector<pt> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].id=i;
    }
    ld ans = 1e19;
    sort(a.begin(),a.end(),[](const pt&a,const pt&b){
        if(a.x==b.y)return a.y<b.y;
        return a.x<b.x;
    });
    pt ans2;
    function<void(int,int)> dnq = [&](int l,int r){
        if(r-l<4){
            for(int i=l;i<=r;i++){
                for(int j=i+1;j<=r;j++){
                    ld temans = a[i].dis(a[j]);
                    if(temans<ans){
                        ans=temans;
                        ans2 = {a[i].id,a[j].id};
                    }
                }
            }
            sort(a.begin()+l,a.begin()+r+1,[](const pt&a,const pt&b){return a.y<b.y;});
            return;
        }
        int mid = (l+r)/2;
        int midx = a[mid].x;
        dnq(l,mid);dnq(mid+1,r);
        inplace_merge(a.begin()+l,a.begin()+mid+1,a.begin()+r+1,[](const pt&a,const pt&b){return a.y<b.y;});
        vector<int> c;c.reserve(r-l+1);
        for(int i=l;i<=r;i++){
            if(abs(a[i].x-midx)<ans){
                for(int j=c.size()-1;j>=0&&a[i].y-a[c[j]].y<ans;j--){
                    ld temans = a[i].dis(a[c[j]]);
                        if(temans<ans){
                            ans=temans;
                            ans2 = {a[i].id,a[c[j]].id};
                        }
                }
            }
            c.push_back(i);
        }

    };
    dnq(0,n-1);
    cout<<min(ans2.x,ans2.y)<<' '<<max(ans2.x,ans2.y)<<' '<<fixed<<setprecision(6)<<ans<<'\n';
}