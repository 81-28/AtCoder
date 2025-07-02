// https://atcoder.jp/contests/abc353/tasks/abc353_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    sort(all(a));
    int ans=sum(a)*(n-1);
    int mod=1e8,cnt=0;
    int j=n-1;
    rep(i,n-1) {
        while (i<j && a[i]+a[j]>=mod) --j;
        cnt+=(n-1-max(i,j));
    }
    ans-=mod*cnt;
    print(ans);

    return 0;
}
