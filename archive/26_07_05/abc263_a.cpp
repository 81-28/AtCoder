// https://atcoder.jp/contests/abc263/tasks/abc263_a

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    vi a(5);
    cin >> a;
    map<int,int> m;
    rep(i,5) ++m[a[i]];
    map<int,int> cnt;
    for (auto[b,c]:m) ++cnt[c];
    YesNo(cnt.size()==2 && cnt[2]==1 && cnt[3]==1);

    return 0;
}
