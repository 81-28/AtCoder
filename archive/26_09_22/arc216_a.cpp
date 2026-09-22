// https://atcoder.jp/contests/arc216/tasks/arc216_a

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}


void solve() {
    int n;
    string a,b;
    cin >> n >> a >> b;
    if (a[0]!=b[0]) {
        print(-1);
        return;
    }
    vi x(n-1),y(n-1);
    rep(k,n-1) {
        x[k]=a[k]^a[k+1]^(k&1);
        y[k]=b[k]^b[k+1]^(k&1);
    }
    int l=sum(x),r=sum(y);
    if (l!=r) {
        print(-1);
        return;
    }
    vi i,j;
    rep(k,n-1) {
        if (x[k]) i.pb(k);
        if (y[k]) j.pb(k);
    }
    int ans=0;
    rep(k,l) ans+=abs(i[k]-j[k]);
    print(ans);
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
