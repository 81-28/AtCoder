// https://atcoder.jp/contests/abc159/tasks/abc159_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n),c(n,0);
    int sm=0;
    for(int&b:a) {
        cin >> b;
        sm+=c[--b]++;
    }
    for(int b:a) print(sm-c[b]+1);

    return 0;
}
