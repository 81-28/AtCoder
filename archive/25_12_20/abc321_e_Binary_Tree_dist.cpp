// https://atcoder.jp/contests/abc321/tasks/abc321_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

int int_log2(int n) {
    int i=-1;
    for(;n>0;n>>=1)++i;
    return i;
}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


// 木の最大深さ
int siz;
// xの子で、xとの距離がkであり、n以下である個数
int cnt(int n,int x,int k) {
    // xの深さ
    int d=int_log2(x);
    if (k<0 || siz-d<k) return 0;
    int l=x<<k,r=(x+1)<<k;
    chmin(r,n+1);
    return max(r-l,0LL);
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,x,k;
        cin >> n >> x >> k;
        siz=int_log2(n);
        int ans=cnt(n,x,k);
        int last=x;
        for (int i=x/2; i; i/=2) {
            if (--k<0) break;
            ans+=cnt(n,i,k)-cnt(n,last,k-1);
            last=i;
        }
        print(ans);
    }

    return 0;
}
