// https://atcoder.jp/contests/abc433/tasks/abc433_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi a(n);
    cin >> a;
    // m[i][j]=右に追加する桁数がiの時、剰余がjとなる個数
    v<map<int,int>> mp(11);
    rep(i,n) {
        int aa=a[i];
        rep1(j,10) {
            aa*=10;
            aa%=m;
            ++mp[j][aa];
        }
    }
    int ans=0;
    rep(i,n) {
        int len=to_string(a[i]).size();
        int md=a[i]%m;
        int d=(m-md)%m;
        ans+=mp[len][d];
    }
    print(ans);

    return 0;
}
