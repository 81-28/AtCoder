// https://atcoder.jp/contests/abc467/tasks/abc467_b

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n;
    cin >> n;
    int ans=0;
    while (n--) {
        int a,b;
        string s;
        cin >> a >> b >> s;
        if (s=="keep") ans+=b-a;
    }
    print(ans);

    return 0;
}
