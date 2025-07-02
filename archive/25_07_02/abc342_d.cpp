// https://atcoder.jp/contests/abc342/tasks/abc342_d

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
    rep(i,n) {
        for (int j=2; j*j<=a[i]; ++j) {
            if (a[i]%(j*j)==0) {
                a[i]/=j*j;
                --j;
            }
        }
        ++m[a[i]];
    }
    int ans=0;
    int z=0;
    for (auto [num,cnt]:m) {
        if (num==0) z+=cnt;
        ans+=cnt*(cnt-1)/2;
    }
    ans+=z*(n-z);
    print(ans);

    return 0;
}
