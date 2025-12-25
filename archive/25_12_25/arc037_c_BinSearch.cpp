// https://atcoder.jp/contests/arc037/tasks/arc037_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


vi a,b;
// m以下の数の個数
int cnt(int m) {
    int res=0;
    for(int ai:a) res+=upper_bound(all(b),m/ai)-b.begin();
    return res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    a=b=vi(n);
    cin >> a >> b;
    sort(all(a)),sort(all(b));
    // (l,r]:l以下の数がk個未満,r以下の数がk個以上
    int l=0,r=*a.rbegin()**b.rbegin();
    while (l+1<r) {
        int m=(l+r)/2;
        if (cnt(m)<k) l=m;
        else r=m;
    }
    print(r);

    return 0;
}
