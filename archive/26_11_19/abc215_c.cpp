// https://atcoder.jp/contests/abc215/tasks/abc215_c

#include<bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    int k;
    cin >> s >> k;
    sort(all(s));
    int i=0;
    do {
        if (++i==k) {
            print(s);
            return 0;
        }
    } while (next_permutation(all(s)));

    return 0;
}
