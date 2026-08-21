// https://atcoder.jp/contests/abc261/tasks/abc261_e

#include<bits/stdc++.h>
using namespace std;

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,c;
    cin >> n >> c;
    int b[2]={0,(1<<30)-1};
    while (n--) {
        int t,a;
        cin >> t >> a;
        if (t==1) b[0]&=a,b[1]&=a;
        if (t==2) b[0]|=a,b[1]|=a;
        if (t==3) b[0]^=a,b[1]^=a;
        c=(c&b[1])|(~c&b[0]);
        print(c);
    }

    return 0;
}
