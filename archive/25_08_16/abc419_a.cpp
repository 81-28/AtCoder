// https://atcoder.jp/contests/abc419/tasks/abc419_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    if (s=="red") {
        print("SSS");
        return 0;
    }
    if (s=="blue") {
        print("FFF");
        return 0;
    }
    if (s=="green") {
        print("MMM");
        return 0;
    }
    print("Unknown");

    return 0;
}
