struct Seg{
    struct Node{
        int v;
        Node* l,*r;
    };
    vector<Node*> version;
    Node* build(int l,int r){
        Node* node=new Node;
        if(l==r){
           node->v=l;
           return node;
        }
        int mid=(l+r)/2;
        node->l=build(l,mid);
        node->r=build(mid+1,r);
        return node;
    }
    int query(Node* cur,int l,int r,int x){
        if(l==r){
            return cur->v;
        }
        int mid=(l+r)/2;
        if(x<=mid) return query(cur->l,l,mid,x);
        else return query(cur->r,mid+1,r,x);
    }
    Node* update(Node* cur,int l,int r,int x,int y){
        Node* node=new Node;
        if(l==r){
           node->v=y;
           return node;
        }
        int mid=(l+r)/2;
        if(x<=mid){
            node->l=update(cur->l,l,mid,x,y);
            node->r=cur->r;
        }
        else{
            node->l=cur->l;
            node->r=update(cur->r,mid+1,r,x,y);
        }
        return node;
    }
};
