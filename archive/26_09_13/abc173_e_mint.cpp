// https://atcoder.jp/contests/abc173/tasks/abc173_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using mint=modint1000000007;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    bool b=1;
    // {絶対値,負か}
    v<pair<int,bool>> aa(n);
    rep(i,n) {
        if (a[i]>=0) {
            b=0;
            aa[i]={a[i],0};
        } else {
            aa[i]={-a[i],1};
        }
    }
    sort(all(aa));
    // 全部マイナスかつ、kが奇数の場合、絶対値が小さいもの
    if (b && k&1) {
        mint ans=1;
        rep(i,k) ans*=aa[i].first;
        print((-ans).val());
        return 0;
    }
    // そうでない場合、絶対値の大きい順に採用
    // 負になる場合、正負を切り替える
    mint ans=1;
    b=0;
    vvi p(2),m(2);
    rep(i,k) {
        auto[num,bl]=aa[n-1-i];
        ans*=num;
        b^=bl;
        if (bl) m[0].pb(num);
        else p[0].pb(num);
    }
    for (int i=k; i<n; ++i) {
        auto[num,bl]=aa[n-1-i];
        if (bl) m[1].pb(num);
        else p[1].pb(num);
    }
    if (!b || ans==0) {
        print(ans.val());
        return 0;
    }
    sort(all(p[0])),sort(all(m[0]));
    bool changed=false;
    bool can_pos = p[1].size() && m[0].size();
    bool can_neg = m[1].size() && p[0].size();
    if (can_pos && (!can_neg || p[1][0]*p[0][0]>m[1][0]*m[0][0])) {
        ans*=p[1][0];
        ans/=m[0][0];
        changed=true;
    } else if (m[1].size() && p[0].size()) {
        ans*=m[1][0];
        ans/=p[0][0];
        changed=true;
    }
    print((changed ? ans : -ans).val());

    return 0;
}
