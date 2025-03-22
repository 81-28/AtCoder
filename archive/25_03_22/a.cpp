// https://atcoder.jp/contests/abc398/tasks/abc398_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    string ans="",add="";
    if (n%2) ans="=";
    else ans="==";
    rep(i,(n-1)/2) add+="-";
    print(add+ans+add);

    return 0;
}
