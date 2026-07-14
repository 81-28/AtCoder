// https://atcoder.jp/contests/abc200/tasks/abc200_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n;
    cin >> n;
    vi cnt(200,0);
    int ans=0;
    while (n--) {
        int a;
        cin >> a;
        ans+=cnt[a%200]++;
    }
    print(ans);

    return 0;
}
