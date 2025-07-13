// https://atcoder.jp/contests/abc357/tasks/abc357_d

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
using mint=modint998244353;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int len = to_string(n).size();
    // (10^(len*n)-1)/(10^len-1);
    mint nume = mint(10).pow(len).pow(n)-1;
    mint deno = mint(10).pow(len)-1;
    print((n*nume/deno).val());

    return 0;
}
