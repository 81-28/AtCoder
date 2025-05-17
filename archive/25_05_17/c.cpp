// https://atcoder.jp/contests/abc406/tasks/abc406_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define f first
#define s second
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using pll=pair<ll,ll>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n;
    cin >> n;
    vll p(n);
    cin >> p;
    v<pll> b;
    ll c=0;
    rep(i,n-2) {
        if (p[i]<p[i+1]&&p[i+1]>p[i+2]) {
            if (c) {
                b.pb({0,c});
                c=0;
            }
            b.pb({1,0});
            continue;
        }
        if (p[i]>p[i+1]&&p[i+1]<p[i+2]) {
            if (c) {
                b.pb({0,c});
                c=0;
            }
            b.pb({2,0});
            continue;
        }
        ++c;
    }
    if (c) b.pb({0,c});

    ll ans=0,add;
    n=b.size();
    rep(i,n-1) {
        if (b[i].f!=1) continue;
        add=1;
        if (b[i+1].f==2) {
            if (i && b[i-1].f==0) {
                add*=b[i-1].s+1;
            }
            if (i+2<n && b[i+2].f==0) {
                add*=b[i+2].s+1;
            }
            ans+=add;
        } else if (i+2<n && b[i+2].f==2) {
            if (i && b[i-1].f==0) {
                add*=b[i-1].s+1;
            }
            if (i+3<n && b[i+3].f==0) {
                add*=b[i+3].s+1;
            }
            ans+=add;
        }
    }
    print(ans);

    return 0;
}
