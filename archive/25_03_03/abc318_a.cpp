// https://atcoder.jp/contests/abc318/tasks/abc318_a

#include<bits/stdc++.h>
using namespace std;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,p;
    cin >> n >> m >> p;
    n-=m;
    if (n < 0) print(0);
    else print(n/p+1);

    return 0;
}
