// https://atcoder.jp/contests/abc485/tasks/abc485_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    // 末尾が3種を含む最大の位置
    int r=-1;
    vi cnt(3,0);
    for (int i=n-1; i>=0; --i) {
        ++cnt[s[i]-'A'];
        if (cnt[0]&&cnt[1]&&cnt[2]) {
            r=i;
            break;
        }
    }
    if (r==-1) {
        print(0);
        return 0;
    }

    // [0,l),[l,m) の文字数
    vi pre(3,0),mid(3,0);
    int m=0,ans=0;
    rep(l,r) {
        // 中央が3種を含むまで2つ目の区切りを伸ばす
        while (m<r && !(mid[0]&&mid[1]&&mid[2])) {
            ++mid[s[m]-'A'];
            ++m;
        }
        if (!(mid[0]&&mid[1]&&mid[2])) break;
        // 先頭も3種を含むなら加算
        if (pre[0]&&pre[1]&&pre[2]) ans+=r-m+1;
        ++pre[s[l]-'A'];
        --mid[s[l]-'A'];
    }
    print(ans);

    return 0;
}
