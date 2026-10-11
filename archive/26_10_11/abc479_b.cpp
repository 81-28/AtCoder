// https://atcoder.jp/contests/abc479/tasks/abc479_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    int cnt=0,ans=0;
    for (char c:s) {
        if (c=='S') cnt=0;
        else ++cnt;
        chmax(ans,cnt);
    }
    print(ans);

    return 0;
}
