// https://atcoder.jp/contests/abc480/tasks/abc480_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
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

    int n,k,t;
    cin >> n >> k >> t;
    vi a(n);
    cin >> a;
    sort(all(a));
    v<pii> p(1,{0,0});
    rep(i,n) {
        if (p.back().s >= a[i]) {
            chmax(p.back().s,a[i]+k);
            continue;
        }
        p.pb({a[i],a[i]+k});
    }
    p.pb({t,t});
    sort(all(p));
    int m=p.size();
    int ans=0;
    rep(i,m-1) {
        if (p[i].s>=t) break;
        int d=p[i+1].f-p[i].s;
        ans+=(d+k-1)/k;
    }
    print(ans);

    return 0;
}
