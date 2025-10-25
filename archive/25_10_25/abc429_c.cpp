// https://atcoder.jp/contests/abc429/tasks/abc429_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    map<int,int> m;
    rep(i,n) ++m[a[i]];
    int ans=0;
    for (auto[num,cnt]:m) {
        int ot=n-cnt;
        if (cnt<2) continue;
        ans+=cnt*(cnt-1)/2*ot;
    }
    print(ans);

    return 0;
}
