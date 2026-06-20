// https://atcoder.jp/contests/abc463/tasks/abc463_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define all(v) v.begin(),v.end()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    v<pii> p(n);
    for (auto&[r,l]:p) cin >> l >> r;
    sort(all(p));
    // [L,R)スコアの範囲
    int L=-1,R=INF;
    // スコアmid以上で、k枚選ぶことができるか判定
    while (L+1<R) {
        int mid=(L+R)/2;
        int gap=max(mid,1LL);
        int cnt=0;
        int lastR=-INF;
        for (auto[r,l]:p) {
            if (l-lastR >= gap) {
                ++cnt;
                lastR=r;
            }
        }
        if (cnt>=k) L=mid;
        else R=mid;
    }
    print(L);

    return 0;
}
