// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_fc

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll=long long;
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    n--;
    ll ans = 4444444444;
    ll ten = 1;
    for(; 0<n; n/=2) {
        if(n%2)ans+=3*ten;
        ten*=10;
    }
    print(ans);

    return 0;
}
