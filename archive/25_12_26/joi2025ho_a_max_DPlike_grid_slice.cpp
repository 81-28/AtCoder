// https://atcoder.jp/contests/joi2025ho/tasks/joi2025ho_a

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n),b=a;
    cin >> a >> b;
    map<int,int> cnt;
    ++cnt[a[0]],++cnt[a[1]],++cnt[b[1]];
    // 広義単調増加にする
    for (int i=2; i<n; ++i) {
        ++cnt[a[i]];
        chmax(a[i],a[i-1]);
        ++cnt[b[i]];
        chmax(b[i],b[i-1]);
    }
    // 後ろ側から最大値を採用していく
    int h=n-1,w=n-1;
    while (h&&w) {
        if (a[h]>b[w]) cnt[a[h--]]+=w;
        else cnt[b[w--]]+=h;
    }
    int col=0,ans=0;
    for (auto[c,num]:cnt) {
        if (chmax(ans,num)) col=c;
        else if (ans==num) chmax(col,c);
    }
    print(col,ans);

    return 0;
}
