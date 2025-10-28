// https://atcoder.jp/contests/abc323/tasks/abc323_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    map<int,int> m;
    // サイズは、奇数iに対して(i*2^j)のように表せるので、共通のiについてまとめ、後にまとめて操作する
    while (n--) {
        int s,c;
        cin >> s >> c;
        while (!(s&1)) {
            s>>=1,c<<=1;
        }
        m[s]+=c;
    }
    int ans=0;
    for (auto[s,c]:m) {
        // popcount
        while (c) {
            ans+=c&1;
            c>>=1;
        }
    }
    print(ans);

    return 0;
}
