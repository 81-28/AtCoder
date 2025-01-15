// https://atcoder.jp/contests/abc331/tasks/abc331_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){for(int i=0;i<(int)v.size();i++)os<<(i?" ":"")<<v[i];return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename T>
auto sum(const vector<T>& v){return accumulate(v.begin(),v.end(),T{});}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n;
    cin >> n;
    vll a(n);
    cin >> a;
    vll b = a;
    sort(all(b));
    vll s(n+1,0);
    map<ll,ll> m;
    for(int i=0; i<n; i++) {
        s[i+1] = s[i]+b[i];
        m[b[i]] = s[i+1];
    }
    vll ans(n);
    ll ss = sum(a);
    rep(i,n) ans[i] = ss-m[a[i]];
    print(ans);

    return 0;
}