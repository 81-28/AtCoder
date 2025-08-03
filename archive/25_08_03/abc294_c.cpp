// https://atcoder.jp/contests/abc294/tasks/abc294_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vvi a(2);
    a[0]=vi(n),a[1]=vi(m);
    cin >> a;
    v<tuple<int,int,int>> c;
    rep(i,n) c.pb({a[0][i],0,i});
    rep(i,m) c.pb({a[1][i],1,i});
    sort(all(c));
    rep(k,n+m) {
        auto[b,i,j]=c[k];
        a[i][j]=k+1;
    }
    print(a[0]);
    print(a[1]);

    return 0;
}