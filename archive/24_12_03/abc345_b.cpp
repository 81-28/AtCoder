// https://atcoder.jp/contests/abc345/tasks/abc345_b

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using ld=long double;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ld x;
    cin >> x;
    if(x<0) print((ll)(x/10));
    else print((ll)(x/10+0.99));

    return 0;
}
