// https://atcoder.jp/contests/abc418/tasks/abc418_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define f first
#define s second
// pair同士の引き算
template<typename F,typename S> pair<F,S> operator-(const pair<F,S>& a,const pair<F,S>& b){return{a.f-b.f,a.s-b.s};}
// pairの乗算代入 (定数)
template<typename F,typename S,typename T> pair<F,S>& operator*=(pair<F,S>& p,const T& a){p.f*=a;p.s*=a;return p;}
// pairの除算代入 (定数)
template<typename F,typename S,typename T> pair<F,S>& operator/=(pair<F,S>& p,const T& a){p.f/=a;p.s/=a;return p;}

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<pii> p(n);
    rep(i,n) cin >> p[i];
    map<pii,map<int,int>> m;
    for (int i=0; i<n-1; ++i) for (int j=i+1; j<n; ++j) {
        pii a=p[i],b=p[j];
        pii q=a-b,r=q;
        if (q.f<0) q*=-1;
        if (q.f==0) {
            q.f=-1;
            q={-1,1};
        } else if (q.s==0) {
            q={1,0};
        } else {
            int g=gcd(q.f,abs(q.s));
            q/=g;
        }
        ++m[q][abs(r.f)+abs(r.s)];
    }
    int ans=0;
    // 平行四辺形の個数
    int para=0;
    for (auto[q,mp]:m) {
        int sm=0;
        for (auto[r,cnt]:mp) {
            sm+=cnt;
            para+=cnt*(cnt-1)/2;
        }
        ans+=sm*(sm-1)/2;
    }
    print(ans-para/2);

    return 0;
}
