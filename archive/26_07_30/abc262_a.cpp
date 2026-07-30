// https://atcoder.jp/contests/abc262/tasks/abc262_a

#include<bits/stdc++.h>
using namespace std;

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int y;
    cin >> y;
    for (;;y++){
        if (y%4==2) {
            print(y);
            return 0;
        }
    }

    return 0;
}
