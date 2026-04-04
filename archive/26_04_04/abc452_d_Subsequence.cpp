// https://atcoder.jp/contests/abc452/tasks/abc452_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s,t;
    cin >> s >> t;
    int n=s.size(),m=t.size();
    // a[i]:char('a'+i)の位置
    vvi a(26);
    rep(i,m) a[t[i]-'a'].pb(i+1);
    // p[i]:t[i]の文字がsの何文字目となる可能性があるか(その前の文字が存在する必要はあり)
    vvi p(m+1);
    p[0]={0};
    rep(i,n) {
        for (int val:a[s[i]-'a']) {
            if (p[val-1].size()==0) continue;
            p[val].pb(i+1);
        }
    }
    // tの1文字目の位置を基準に、そこから始まって、含んでしまう最短位置を求める
    // つまり、含まない最長を求める
    int ans=0;
    int b=0;
    int lll=0;
    map<int,int> res;
    for (int val:p[1]) {
        int l=val;
        for (int i=2; i<=m; ++i) {
            auto it=upper_bound(all(p[i]),l);
            if (it==p[i].end()) {
                l=n+1;
                break;
            }
            l=*it;
        }
        int add=(l-b)*(l-b-1)/2;
        // 重複加算を除く
        int sub=(lll-b)*(lll-b-1)/2;
        if (res.find(l)==res.end()) {
            res[l]=add-sub;
            ans+=add-sub;
            lll=l;
        }
        b=val;
    }
    int add=(n-b)*(n-b+1)/2;
    int sub=(lll-b)*(lll-b-1)/2;
    ans+=add-sub;
    print(ans);

    return 0;
}
