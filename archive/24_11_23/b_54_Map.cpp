// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ea

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll=long long;
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,a;
    cin >> n;
    ll ans = 0;
    unordered_map<int,ll> m;
    rep(i,n) {
        cin >> a;
        ans += m[a]++;
    }
    print(ans);

    return 0;
}
