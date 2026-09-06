// https://atcoder.jp/contests/abc474/tasks/abc474_a

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int x;
    cin >> x;
    rep1(i,3) {
        if (i!=x) {
            print(i);
            return 0;
        }
    }

    return 0;
}
