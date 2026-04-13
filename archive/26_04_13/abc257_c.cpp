// https://atcoder.jp/contests/abc257/tasks/abc257_c

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max()/2;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string st;
    cin >> n >> st;
    vi w(n);
    cin >> w;
    v<pair<int,bool>> p(n);
    int sm=0;
    rep(i,n) {
        p[i]={w[i],st[i]-'0'};
        sm+=p[i].s;
    }
    p.pb({0,0});
    p.pb({INF,1});
    sort(all(p));
    int ans=0;
    rep(i,n+1) {
        if (p[i].f!=p[i+1].f) chmax(ans,sm);
        if (p[i+1].s) --sm;
        else ++sm;
    }
    print(ans);

    return 0;
}
