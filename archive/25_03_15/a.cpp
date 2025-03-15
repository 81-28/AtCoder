// https://atcoder.jp/contests/abc397/tasks/abc397_a

#include<bits/stdc++.h>
using namespace std;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    double x;
    cin >> x;
    if (x >= 38.0) print(1);
    else if (x >= 37.5) print(2);
    else print(3);

    return 0;
}
