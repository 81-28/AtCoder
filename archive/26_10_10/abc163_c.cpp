// https://atcoder.jp/contests/abc163/tasks/abc163_c

#include<bits/stdc++.h>
using namespace std;

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
    vi c(n,0);
    while (--n) {
        int a;
        cin >> a;
        ++c[--a];
    }
    for (int val:c) print(val);

    return 0;
}
