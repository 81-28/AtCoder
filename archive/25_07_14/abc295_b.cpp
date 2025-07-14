// https://atcoder.jp/contests/abc295/tasks/abc295_b

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

    int r,c;
    cin >> r >> c;
    v<string> b(r);
    cin >> b;
    rep(i,r)rep(j,c) {
        if ('1'<=b[i][j]&&b[i][j]<='9') {
            int d=b[i][j]-'0';
            b[i][j]='.';
            rep(x,r)rep(y,c) {
                if (b[x][y]=='#' && abs(i-x)+abs(j-y)<=d) b[x][y]='.';
            }
        }
    }
    rep(i,r) print(b[i]);

    return 0;
}
