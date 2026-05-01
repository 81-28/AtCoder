// https://atcoder.jp/contests/abc246/tasks/abc246_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rall(v) v.rbegin(),v.rend()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k,x;
    cin >> n >> k >> x;
    vi a(n);
    cin >> a;
    int sm=sum(a);
    int mi=0;
    bool b=1;
    rep(i,n) {
        int l=(a[i]-1)/x;
        if (l>k) {
            mi+=x*k;
            b=0;
            break;
        } else {
            mi+=x*l;
            a[i]-=x*l;
            k-=l;
        }
    }
    if (b) {
        sort(rall(a));
        rep(i,min(n,k)) mi+=a[i];
    }
    print(sm-mi);

    return 0;
}
