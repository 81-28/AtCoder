// https://atcoder.jp/contests/abc426/tasks/abc426_b

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    map<char,int> m;
    for (char c:s) ++m[c];
    for (auto[c,n]:m) {
        if (n==1) {
            print(c);
            return 0;
        }
    }

    return 0;
}
