// https://atcoder.jp/contests/joi2023ho/tasks/joi2023ho_a

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    map<int,vi> mp;
    vi a(n);
    cin >> a;
    rep(i,n) mp[a[i]].pb(i);
    // 前から順に確定していき、確定した色は、その色の最大値まで繋がる
    rep(i,n) {
        int tail=*mp[a[i]].rbegin();
        for (int j=i+1; j<=tail; ++j) a[j]=a[i];
        i=tail;
    }
    rep(i,n) print(a[i]);

    return 0;
}
