// https://atcoder.jp/contests/arc225/tasks/arc225_a

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n;
    cin >> n;
    vvi x(n,vi(n));
    cin >> x;
    map<int,int> m={{1,3},{2,1},{3,4},{4,2}};
    vvi y(n,vi(n));
    rep(i,n)rep(j,n) y[i][j]=m[x[i][j]];
    rep(i,n) print(y[i]);

    return 0;
}
