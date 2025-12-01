// https://atcoder.jp/contests/abc300/tasks/abc300_f

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,k;
    string s;
    cin >> n >> m >> k >> s;
    // 'x'の位置
    vi idx;
    rep(i,n) {
        if (s[i]=='x') idx.pb(i);
    }
    int x=idx.size();
    // 1周分で分割
    int quo=k/x;
    int rem=m-quo;
    // 調整インデックスは高々2周分で良い
    // 2周分に満たない場合のために、左右の端を追加
    int r=min(rem,2LL);
    vi jdx(1,-1);
    rep(i,r)rep(j,x) jdx.pb(i*n+idx[j]);
    jdx.pb(r*n);
    int l=jdx.size();

    // 確定部分
    int ans=quo*n;
    // 1周に満たないはみ出た部分から、連続したk要素を削除することを考える
    k%=x;
    int add=0;
    rep(i,x+1) {
        int j=i+k+1;
        if (j>=l) break;
        chmax(add,jdx[j]-jdx[i]-1);
    }
    print(ans+add);

    return 0;
}
