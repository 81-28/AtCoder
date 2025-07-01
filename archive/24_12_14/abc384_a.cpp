// https://atcoder.jp/contests/abc384/tasks/abc384_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    char c1,c2;
    string s;
    cin >> n >> c1 >> c2 >> s;
    rep(i,n) {
        if (s[i] != c1) s[i] = c2;
    }
    print(s);

    return 0;
}
