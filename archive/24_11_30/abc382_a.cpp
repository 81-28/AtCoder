// https://atcoder.jp/contests/abc382/tasks/abc382_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,d;
    string s;
    cin >> n >> d >> s;
    int cnt = 0;
    rep(i,n) if (s[i] == '@') cnt++;
    print(n-cnt+d);

    return 0;
}
