// https://atcoder.jp/contests/abc263/tasks/abc263_b

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
    vi a(n+1,0);
    for (int i=2; i<=n; ++i) {
        int p;
        cin >> p;
        a[i]=a[p]+1;
    }
    print(a[n]);

    return 0;
}
