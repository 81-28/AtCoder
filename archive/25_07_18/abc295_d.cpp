// https://atcoder.jp/contests/abc295/tasks/abc295_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define f first
#define s second

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string t;
    cin >> t;
    int n=t.size();
    // v<bool>(10)[i]:数iの個数が奇数かどうか
    // m:それの個数
    map<v<bool>,int> m;
    v<bool> b(10,0);
    ++m[b];
    rep(i,n) {
        int a=t[i]-'0';
        // b[a]^=1;
        b[a]=!b[a];
        ++m[b];
    }
    int ans=0;
    for (auto p:m) ans+=p.s*(p.s-1)/2;
    print(ans);

    return 0;
}
