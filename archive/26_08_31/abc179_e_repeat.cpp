// https://atcoder.jp/contests/abc179/tasks/abc179_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define pb push_back

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,x,m;
    cin >> n >> x >> m;
    map<int,int> idx;
    vi a={0,x},sm=a;
    idx[x]=1;
    for (int i=2; i<=n; ++i) {
        a.pb(a[i-1]*a[i-1]%m);
        sm.pb(sm[i-1]+a[i]);
        if (!idx[a[i]]) {
            idx[a[i]]=i;
            continue;
        }
        int l=i-idx[a[i]];
        int r=n-idx[a[i]];
        print((sm[i]-sm[idx[a[i]]])*(r/l) + sm[r%l+idx[a[i]]]);
        return 0;
    }
    print(sm[n]);

    return 0;
}
