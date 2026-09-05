// https://atcoder.jp/contests/arc229/tasks/arc229_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}
template<typename T>
T min(const v<T>& v){return *min_element(v.begin(),v.end());}


void solve() {
    int k;
    cin >> k;
    vi a(k+1);
    cin >> a;
    int mi=min(a);
    int d=sum(a)-(k+1)*mi;
    bool b=(mi%k==0&&d<k);
    print(b?"Bob":"Alice");
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
