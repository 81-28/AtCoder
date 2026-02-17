// https://atcoder.jp/contests/abc281/tasks/abc281_b

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    if (n!=8) {
        YesNo(0);
        return 0;
    }
    if (s[0]<'A'||'Z'<s[0]) {
        YesNo(0);
        return 0;
    }
    if (s[n-1]<'A'||'Z'<s[n-1]) {
        YesNo(0);
        return 0;
    }
    if (s[1]<'1'||'9'<s[1]) {
        YesNo(0);
        return 0;
    }
    for (int i=2; i<n-1; ++i) {
        if (s[i]<'0'||'9'<s[i]) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}