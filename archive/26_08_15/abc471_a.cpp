// https://atcoder.jp/contests/abc471/tasks/abc471_a

#include<bits/stdc++.h>
using namespace std;

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a,b;
    cin >> a >> b;
    if (a+b==9) {
        print("Nine");
        return 0;
    }
    if (a-b==9) {
        print("Nine");
        return 0;
    }
    if (a*b==9) {
        print("Nine");
        return 0;
    }
    if (a==9*b) {
        print("Nine");
        return 0;
    }
    print("Nein");

    return 0;
}
