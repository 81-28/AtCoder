// https://atcoder.jp/contests/arc168/tasks/arc168_a

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    // < : +(n-1) , > : -1 のイメージ
    int cnt=0,ans=0;
    for (char c:s) {
        if (c=='<') cnt=0;
        else ans+=++cnt;
    }
    print(ans);

    return 0;
}
