class SegmentTree{
private:
    vector<ll>seg;
    vector<ll>lazy
public:
    SegmentTree(ll n){
        seg.resize(4*n+1);
        lazy.resize(4*n+1,0);
    }
    void build(ll ind,ll low,ll high,vector<ll>&arr){
        if(low==high){
            seg[ind]=arr[low];
            return;
        }
        ll mid=(low+high)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }
    ll query(ll ind,ll low,ll high,ll l,ll r){
        if(high<l || r<low)
            return 1e9;
        if(low>=l && high<=r)
            return seg[ind];
        ll mid=(low+high)/2;
        ll left=query(2*ind+1,low,mid,l,r);
        ll right=query(2*ind+2,mid+1,high,l,r);
        return min(left,right);
    }
    void updateRange(ll ind,ll low,ll high,ll l,ll r,ll val){
        seg[ind]=lazy[ind];
        if(low!=high){
            lazy[2*ind+1]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }
        lazy[ind]=0;
        
        if(high<l || r<low){
            return ;
        }
        else if(low>=l && high<=r){
            seg[ind]+=val;
            if(low!=high){
                lazy[2*ind+1]+=val;
                lazy[2*ind+2]+=val;
            }
            return ;
        }
        int mid=low+(high-low)/2;
        updateRange(2*ind+1,low,mid,l,r,val);
        updateRange(2*ind+2,mid+1,high,l,r,val);
        
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }
};
