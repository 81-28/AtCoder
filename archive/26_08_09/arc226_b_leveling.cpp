// https://atcoder.jp/contests/arc226/tasks/arc226_b

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
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        vi a(m);
        cin >> a;
        int ans=0;
        int cnt=0;
        // 水が同じ高さになるようなイメージ
        for (int i=m-1; i>=0; --i) {
            cnt=cnt*2+a[i];
            int need=(cnt+n-1)/n;
            chmax(ans,need*(1LL<<i));
        }
        print(ans);
    }

    return 0;
}
