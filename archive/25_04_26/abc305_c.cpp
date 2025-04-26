// https://atcoder.jp/contests/abc305/tasks/abc305_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> s(h);
    cin >> s;
    int a=h,b=0,c=w,d=0;
    rep(i,h)rep(j,w) {
        if (s[i][j]=='#') {
            a=min(a,i);
            b=max(b,i);
            c=min(c,j);
            d=max(d,j);
        }
    }
    for(int i=a;i<=b;i++)for(int j=c;j<=d;j++) {
        if (s[i][j]=='.') {
            print(i+1,j+1);
            return 0;
        }
    }

    return 0;
}
