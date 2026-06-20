// https://atcoder.jp/contests/abc463/tasks/abc463_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    char x;
    cin >> n >> x;
    v<string> s(n);
    cin >> s;
    rep(i,n) {
        if (s[i][x-'A']=='o') {
            YesNo(1);
            return 0;
        }
    }
    YesNo(0);

    return 0;
}
