// https://atcoder.jp/contests/abc430/tasks/abc430_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi x(n);
    cin >> x;
    // 位置の集合
    set<int> st;
    // d[i]:位置iの人の最短距離
    map<int,int> d;
    st.insert(0);
    st.insert(x[0]);
    d[0]=x[0];
    d[x[0]]=x[0];

    int ans=x[0]*2;
    print(ans);

    rep1(i,n-1) {
        int y=x[i];
        int dist=INT_MAX;
        auto itr=st.lower_bound(y);
        if (itr!=st.end()) {
            int r=*itr;
            chmin(dist,r-y);
            int tmp=d[r];
            if (chmin(d[r],r-y)) ans+=r-y-tmp;
        }
        auto itl=st.upper_bound(y);
        if (itl!=st.begin()) {
            --itl;
            int l=*itl;
            chmin(dist,y-l);
            int tmp=d[l];
            if (chmin(d[l],y-l)) ans+=y-l-tmp;
        }
        ans+=dist;
        print(ans);

        st.insert(y);
        d[y]=dist;
    }

    return 0;
}
