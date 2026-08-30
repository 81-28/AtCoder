// https://atcoder.jp/contests/abc473/tasks/abc473_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int n, k;
vi a;
void dfs(int i,int sm) {
    if (i+1 == n) {
        int rem = k-sm;
        if (rem%n) return;
        a.back() = rem/n;
        print(a);
        return;
    }
    for (int j=0; sm+j*(i+1) <= k; ++j) {
        a[i]=j;
        dfs(i+1,sm+j*(i+1));
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> k;
    a=vi(n,0);
    dfs(0, 0);

    return 0;
}
