// https://atcoder.jp/contests/abc269/tasks/abc269_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n=10;
    v<string> s(n);
    cin >> s;
    int a=0,b,c,d;
    rep(i,n)rep(j,n) {
        if (s[i][j]=='.') continue;
        if (a==0) a=i+1,c=j+1;
        b=i+1,d=j+1;
    }
    print(a,b);
    print(c,d);

    return 0;
}
