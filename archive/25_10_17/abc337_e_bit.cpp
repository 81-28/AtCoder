// https://atcoder.jp/contests/abc337/tasks/abc337_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

int int_log2(int n) {
    int i=-1;
    for(;n>0;n>>=1)++i;
    return i;
}

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int m=int_log2(n);
    if (n!=(1<<m)) ++m;
    vvi a(m);
    rep(i,n) {
        for (int j=i,k=0; j; j>>=1,++k) {
            if (j&1) a[k].pb(i+1);
        }
    }
    print(m);
    rep(i,m) print(a[i].size(),a[i]);
    string s;
    cin >> s;
    int ans=0;
    rep(i,m) {
        if (s[i]=='1') ans+=1<<i;
    }
    print(ans+1);

    return 0;
}
