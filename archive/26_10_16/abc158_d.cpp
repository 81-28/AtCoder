// https://atcoder.jp/contests/abc158/tasks/abc158_d

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s,h,t;
    int q;
    cin >> s >> q;
    bool b=0;
    while (q--) {
        int m,f;
        cin >> m;
        if (m&1) b^=1;
        else {
            char c;
            cin >> f >> c;
            if ((b+f)&1) h.pb(c);
            else t.pb(c);
        }
    }
    reverse(all(h));
    string ans=h+s+t;
    if (b) reverse(all(ans));
    print(ans);

    return 0;
}
