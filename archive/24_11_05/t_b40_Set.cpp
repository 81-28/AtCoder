// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_dm

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    multiset<int> s;
    int ans = 0;
    int a;
    rep(i,n) {
        cin >> a;
        a%=100;
        ans += s.count(100-a)+s.count(-a);
        s.insert(a);
    }
    print(ans);

    return 0;
}
