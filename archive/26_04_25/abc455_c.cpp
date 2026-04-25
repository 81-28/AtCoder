// https://atcoder.jp/contests/abc455/tasks/abc455_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define rall(v) v.rbegin(),v.rend()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    map<int,int> m;
    rep(i,n) ++m[a[i]];
    vi b;
    for (auto[num,cnt]:m) {
        b.pb(num*cnt);
    }
    sort(rall(b));
    int l=b.size();
    int res=0;
    rep(i,k) {
        if (i>=l) break;
        res+=b[i];
    }
    print(sum(a)-res);

    return 0;
}
