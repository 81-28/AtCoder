// https://atcoder.jp/contests/abc447/tasks/abc447_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    vi cnt(2,0);
    int ans=0;
    for (char c:s) {
        if (c=='A') {
            ++cnt[0];
        }
        if (c=='B') {
            if (cnt[0]==0) continue;
            --cnt[0];
            ++cnt[1];
        }
        if (c=='C') {
            if (cnt[1]==0) continue;
            --cnt[1];
            ++ans;
        }
    }
    print(ans);

    return 0;
}
