// https://atcoder.jp/contests/abc284/tasks/abc284_b

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans=0;
        while (n--) {
            int a;
            cin >> a;
            ans+=a&1;
        }
        print(ans);
    }

    return 0;
}
