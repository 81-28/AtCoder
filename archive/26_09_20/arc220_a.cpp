// https://atcoder.jp/contests/arc220/tasks/arc220_a

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


vvi a={
    {2,2,2,3,3,6},
    {1},
    {2,2,3,3,3,3,6,6}
};
void solve() {
    int n;
    cin >> n;
    if (n==2 || n==3 || n==5) {
        YesNo(0);
        return;
    }
    YesNo(1);
    // Aを、4つの2Aに置き換えてもok
    multiset<int> res(all(a[n%3]));
    while (res.size()<n) {
        int h=*res.begin();
        res.erase(res.begin());
        rep(i,4) res.insert(h*2);
    }
    for (auto it=res.begin(); it!=res.end(); ++it)
        cout<<*it<<' ';
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
