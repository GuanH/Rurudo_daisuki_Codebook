struct Seg{
    vector<int> seg,tag;
    #define cl (i<<1)+1
    #define cr (i<<1)+2
    void push(int i,int l,int r){
        if(tag[i]!=0){
            seg[i]+=tag[i]; // update by tag
            if(l!=r){
                tag[cl]+=tag[i]; // push
                tag[cr]+=tag[i]; // push
            }
            tag[i]=0;
        }
    }
    void pull(int i,int l,int r){
        int mid=(l+r)>>1;
        push(cl,l,mid);push(cr,mid+1,r);
        seg[i]=max(seg[cl],seg[cr]); // pull
    }
    void build(int i,int l,int r,vector<int>&arr){
        if(l==r){
            seg[i]=arr[l]; // set value
            return;
        }
        int mid=(l+r)>>1;
        build(cl,l,mid,arr);
        build(cr,mid+1,r,arr);
        pull(i,l,r);
    }
    Seg(vector<int>& arr){
        seg.resize(arr.size()*4);
        tag.resize(arr.size()*4);
        build(0,0,arr.size()-1,arr);
    }
    void update(int i,int l,int r,int nl,int nr,int x){
        push(i,l,r);
        if(nl<=l&&r<=nr){
            tag[i]+=x;
            return;
        }
        int mid=(l+r)>>1;
        if(nl<=mid) update(cl,l,mid,nl,nr,x);
        if(nr>mid) update(cr,mid+1,r,nl,nr,x);
        pull(i,l,r);
    }
    int query(int i,int l,int r,int nl,int nr){
        push(i,l,r);
        if(nl<=l&&r<=nr){
            return seg[i];
        }
        int mid=(l+r)>>1;
        int ans=0;
        if(nl<=mid) ans=max(ans,query(cl,l,mid,nl,nr));
        if(nr>mid) ans=max(ans,query(cr,mid+1,r,nl,nr));
        return ans;
    }
};
