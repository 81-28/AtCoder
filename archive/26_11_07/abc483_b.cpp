// https://atcoder.jp/contests/abc483/tasks/abc483_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vi a(n);
    rep(i,n) a[i]=i+1;
    while (q--) {
        int k;
        cin >> k;
        vi b=a;
        rep(i,k) b[i]=-a[k-1-i];
        a=b;
    }
    for (int val:a) print(val);

    return 0;
}
