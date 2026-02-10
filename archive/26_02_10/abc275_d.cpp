// https://atcoder.jp/contests/abc275/tasks/abc275_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

map<int,int> m={{0,1}};
int f(int n) {
    if (m[n]!=0) return m[n];
    return m[n]=f(n/2)+f(n/3);
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    print(f(n));

    return 0;
}
