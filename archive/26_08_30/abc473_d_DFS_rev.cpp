// https://atcoder.jp/contests/abc473/tasks/abc473_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

vvi ans;
vi a;
void dfs(int r,int i) {
    if (i==1) {
        a[0]=r;
        ans.pb(a);
        return;
    }
    for (int j=0; j*i<=r; ++j) {
        a[i-1]=j;
        dfs(r-j*i,i-1);
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    a=vi(n,0);
    dfs(k,n);
    sort(all(ans));
    for (vi vec:ans) print(vec);

    return 0;
}
