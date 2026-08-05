// https://atcoder.jp/contests/abc260/tasks/abc260_a

#include<bits/stdc++.h>
using namespace std;

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    map<char,int> m;
    for (char c:s) ++m[c];
    for (auto[c,cnt]:m) {
        if (cnt==1) {
            print(c);
            return 0;
        }
    }
    print(-1);

    return 0;
}
