// https://atcoder.jp/contests/abc476/tasks/abc476_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,k,x,y;
    cin >> n >> m >> k >> x >> y;
    vi a(n),b(m);
    cin >> a >> b;
    sort(all(a)),sort(all(b));
    vi sma(n+1,0);
    rep(i,n) sma[i+1]=sma[i]+a[i];
    // p[i]:ドリンクを小さい順にi個買う場合に必要なkドル紙幣の枚数と、その時のおつり
    v<pii> p(m+1);
    p[0]={0,0};
    rep(i,m) {
        int r=(b[i]+k-1)/k;
        p[i+1].f=p[i].f+r;
        p[i+1].s=p[i].s+(k*r-b[i]);
    }
    int sm=x+y*k;
    int ans=0;
    rep(i,m+1) {
        // ドリンクをi個買う場合
        int rem=sm-p[i].f*k+p[i].s;
        if (rem<0 || p[i].f>y) break;
        auto it=upper_bound(all(sma),rem);
        int res=it-sma.begin()-1;
        chmax(ans,i+res);
    }
    print(ans);

    return 0;
}
