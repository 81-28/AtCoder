// https://atcoder.jp/contests/abc407/tasks/abc407_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a,b;
    cin >> a >> b;
    int c=a/b*b,d=c+b;
    if (a-c < d-a) print(c/b);
    else print(d/b);

    return 0;
}
