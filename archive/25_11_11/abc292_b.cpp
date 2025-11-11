// http://atcoder.jp/contests/abc292/tasks/abc292_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vi cnt(n,0);
    while(q--) {
        int m,x;
        cin >> m >> x;
        --x;
        if (m==3) YesNo(cnt[x]>1);
        else cnt[x]+=m;
    }

    return 0;
}