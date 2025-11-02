// https://atcoder.jp/contests/abc430/tasks/abc430_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,a,b;
    string s;
    cin >> n >> a >> b >> s;
    vi aa(1,-1),bb=aa;
    int ans=0;
    // 右端i
    rep(i,n) {
        // 左端の範囲を求める
        if (s[i]=='a') aa.pb(i);
        else bb.pb(i);
        int as=aa.size(),bs=bb.size();
        int ai=max(as-a,0LL),bi=max(bs-b,0LL);
        ans+=max(aa[ai]-bb[bi],0LL);
    }
    print(ans);

    return 0;
}
