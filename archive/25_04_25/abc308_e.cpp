// https://atcoder.jp/contests/abc308/tasks/abc308_e

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using vvll=v<vll>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int mex(const int& a,const int& b,const int& c) {
    rep(i,3) if(a!=i&&b!=i&&c!=i) return i;
    return 3;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n;
    cin >> n;
    vll a(n);
    string s;
    cin >> a >> s;
    vvll m(n,vll(3,0)),x=m;
    vll e;
    rep(i,n) {
        if (s[i]=='M') m[i][a[i]]++;
        if (s[i]=='E') e.pb(i);
        if (s[i]=='X') x[i][a[i]]++;
    }
    for(int i=1;i<n;i++)rep(j,3) m[i][j]+=m[i-1][j];
    for(int i=n-2;i>=0;i--)rep(j,3) x[i][j]+=x[i+1][j];

    ll ans=0;
    for(int val:e)rep(i,3)rep(j,3) ans+=mex(i,a[val],j)*m[val][i]*x[val][j];
    print(ans);

    return 0;
}
