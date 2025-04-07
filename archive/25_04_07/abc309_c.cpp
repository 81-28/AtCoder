// https://atcoder.jp/contests/abc309/tasks/abc309_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
using ll=long long;
template<typename T>
using v=vector<T>;
using pll=pair<ll,ll>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,k;
    cin >> n >> k;
    v<pll> p(n);
    ll s=0;
    rep(i,n) {
        cin >> p[i];
        s+=p[i].second;
    }
    sort(all(p));
    if (s<=k) {
        print(1);
        return 0;
    }
    rep(i,n) {
        s-=p[i].second;
        if (s<=k) {
            print(p[i].first+1);
            return 0;
        }
    }

    return 0;
}
