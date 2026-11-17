// https://atcoder.jp/contests/arc164/tasks/arc164_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int sm=0,cnt=0,mn=INF;
    while (n--) {
        int a,b;
        cin >> a >> b;
        sm+=max(a,b);
        cnt+=(a>b);
        chmin(mn,abs(a-b));
    }
    if (cnt&1) sm-=mn;
    print(sm);

    return 0;
}
