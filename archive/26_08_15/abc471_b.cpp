// https://atcoder.jp/contests/abc471/tasks/abc471_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    map<string,int> m;
    int ans=0;
    while (n--) {
        string s;
        cin >> s;
        for (char& c:s) {
            if (islower(c)) c+='A'-'a';
        }
        chmax(ans,++m[s]);
    }
    print(ans);

    return 0;
}
