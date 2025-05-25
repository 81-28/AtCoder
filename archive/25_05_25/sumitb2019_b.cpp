// https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_b

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    double r=1.08;
    int a=n/r;
    if ((int)(a*r)==n) print(a);
    else if ((int)(++a*r)==n) print(a);
    else print(":(");

    return 0;
}
