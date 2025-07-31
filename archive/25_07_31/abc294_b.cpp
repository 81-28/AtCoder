// https://atcoder.jp/contests/abc294/tasks/abc294_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    vvi a(h,vi(w));
    cin >> a;
    v<string> s(h,string(w,'.'));
    rep(i,h)rep(j,w) {
        if (a[i][j]) s[i][j]='A'+(a[i][j]-1);
    }
    rep(i,h) print(s[i]);

    return 0;
}