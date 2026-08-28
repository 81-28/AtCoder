// https://atcoder.jp/contests/abc181/tasks/abc181_e

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max();
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi h(n),w(m);
    cin >> h >> w;
    sort(all(h)),sort(all(w));
    int nn=n/2;
    vi l(nn+1,0),r=l;
    rep(i,nn) {
        l[i+1]=abs(h[i*2+1]-h[i*2]);
        l[i+1]+=l[i];
        r[i+1]=abs(h[n-1-(i*2+1)]-h[n-1-i*2]);
        r[i+1]+=r[i];
    }
    int ans=INF;
    for (int val:w) {
        auto it=lower_bound(all(h),val);
        int i=it-h.begin();
        if (i&1) --it;
        int res=l[i/2]+r[nn-i/2]+abs(*it-val);
        chmin(ans,res);
    }
    print(ans);

    return 0;
}
