// https://atcoder.jp/contests/abc354/tasks/abc354_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define f first
#define s second
using ll=long long;
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<pair<ll,pair<ll,int>>> p(n);
    rep(i,n) {
        cin >> p[i].f >> p[i].s.f;
        p[i].s.s=i+1;
    }
    vi ans;
    ll mi=LLONG_MAX;
    sort(rall(p));
    for(auto pp:p) {
        if (pp.s.f<mi) {
            ans.pb(pp.s.s);
            mi=pp.s.f;
        }
    }
    sort(all(ans));
    print(ans.size());
    print(ans);

    return 0;
}