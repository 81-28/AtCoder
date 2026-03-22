// https://atcoder.jp/contests/abc275/tasks/abc275_b

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using mint=modint998244353;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vi a(3),b(3);
    cin >> a >> b;
    mint aa=1,bb=1;
    rep(i,3) {
        aa*=a[i];
        bb*=b[i];
    }
    print((aa-bb).val());

    return 0;
}
