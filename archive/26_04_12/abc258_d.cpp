// https://atcoder.jp/contests/abc258/tasks/abc258_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,x;
    cin >> n >> x;
    int t=0;
    int ans=INF;
    rep1(i,n) {
        if (i>x) break;
        int a,b;
        cin >> a >> b;
        // 初めてクリアするのにかかる時間
        t+=a+b;
        // 初めてクリアした後、そのステージのみを遊び続けた場合の時間
        chmin(ans,t+b*(x-i));
    }
    print(ans);

    return 0;
}
