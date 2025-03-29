// https://atcoder.jp/contests/abc399/tasks/abc399_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s,t;
    cin >> n >> s >> t;
    int ans=0;
    rep(i,n) {
        if (s[i]!=t[i]) ans++;
    }
    print(ans);

    return 0;
}
