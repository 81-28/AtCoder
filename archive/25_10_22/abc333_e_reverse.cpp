// https://atcoder.jp/contests/abc333/tasks/abc333_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=(int)v.size()-1;i>=0;--i)os<<v[i]<<(i?" ":"");return os;}
template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<pii> p(n);
    rep(i,n) cin >> p[i];
    // 必要なポーションの数
    vi m(n,0);
    int k=0,sm=0;
    vi ans;
    // 1番近いところで貪欲に拾うのが最適
    for (int i=n-1; i>=0; --i) {
        auto[t,x]=p[i];
        --x;
        if (t==1) {
            if (m[x]) {
                ans.pb(1);
                --m[x];
                --sm;
            } else ans.pb(0);
        } else {
            ++m[x];
            ++sm;
            chmax(k,sm);
        }
    }
    if (sm) {
        print(-1);
        return 0;
    }
    print(k);
    print(ans);

    return 0;
}
