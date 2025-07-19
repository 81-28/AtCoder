// https://atcoder.jp/contests/abc295/tasks/abc295_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    vi cnt(1<<10,0);
    int b=0;
    ++cnt[b];
    int ans=0;
    rep(i,n) {
        int a=s[i]-'0';
        b^=(1<<a);
        ans+=cnt[b]++;
    }
    print(ans);

    return 0;
}
