// https://atcoder.jp/contests/abc299/tasks/abc299_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<class T>constexpr bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    int cmb=0;
    int ans=-1;
    rep(i,n) {
        if (s[i]=='o') ++cmb;
        else {
            chmax(ans,cmb);
            cmb=0;
        }
    }
    chmax(ans,cmb);
    if (ans<1 || ans==n) print(-1);
    else print(ans);

    return 0;
}
