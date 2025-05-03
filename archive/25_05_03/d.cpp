// https://atcoder.jp/contests/abc404/tasks/abc404_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
using ll=long long;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vll=v<ll>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vll c(n);
    cin >> c;
    int k,a;
    vvi g(n);
    rep(i,m) {
        cin >> k;
        rep(j,k) {
            cin >> a;
            g[a-1].pb(i);
        }
    }

    int mx=pow(3,n);
    ll ans=LLONG_MAX,s;
    vi u;
    int d,cnt;
    bool ok;
    for (int i=0; i<mx; i++) {
        s=0;
        u=vi(m,0);
        d=i;
        rep(j,n) {
            cnt=d%3;
            if (cnt) {
                s+=c[j]*cnt;
                for (int val:g[j]) u[val]+=cnt;
            }
            d/=3;
        }
        ok=1;
        for (int val:u) {
            if (val<2) {
                ok=0;
                break;
            }
        }
        if (ok) ans=min(ans,s);
    }
    print(ans);

    return 0;
}
