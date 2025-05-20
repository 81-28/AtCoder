// https://atcoder.jp/contests/abc346/tasks/abc346_e

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using pll=pair<ll,ll>;

template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<' '<<p.second;return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll h,w,m;
    cin >> h >> w >> m;
    vll t(m),a(m),x(m);
    rep(i,m) cin >> t[i] >> a[i] >> x[i];
    v<bool> r(h,1),c(w,1);
    map<ll,ll> mp;
    mp[0]=h*w;
    for (int i=m-1; i>=0; --i) {
        --a[i];
        if (t[i]-1) {
            if (c[a[i]] && h) {
                mp[x[i]]+=h;
                mp[0]-=h;
                --w;
                c[a[i]]=0;
            }
        } else {
            if (r[a[i]] && w) {
                mp[x[i]]+=w;
                mp[0]-=w;
                --h;
                r[a[i]]=0;
            }
        }
    }
    print(mp.size()-(mp[0]==0));
    for (auto p:mp) {
        if (p.second!=0) print(p);
    }

    return 0;
}
