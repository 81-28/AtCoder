// https://atcoder.jp/contests/abc386/tasks/abc386_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename... Args>
istream &operator>>(istream &is,tuple<Args...> &t){apply([&is](auto&... args){((is>>args),...);},t);return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<tuple<int,int,char>> t(m);
    rep(i,m) cin >> t[i];
    sort(all(t));
    int mi=n+1;
    for (auto[x,y,c]:t) {
        if (c=='W') chmin(mi,y);
        else {
            if (y>=mi) {
                YesNo(0);
                return 0;
            }
        }
    }
    YesNo(1);

    return 0;
}
