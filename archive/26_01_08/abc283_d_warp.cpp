// https://atcoder.jp/contests/abc283/tasks/abc283_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    vi cnt(26,0);
    // 対応する'('の位置
    vi idx(n);
    rep(i,n) {
        if (s[i]=='(') continue;
        if (s[i]==')') {
            for (int j=i-1;; --j) {
                if (s[j]==')') {
                    j=idx[j];
                    continue;
                }
                if (s[j]=='(') {
                    idx[i]=j;
                    break;
                }
                --cnt[s[j]-'a'];
            }
        } else {
            if (cnt[s[i]-'a']++) {
                YesNo(0);
                return 0;
            }
        }
    }
    YesNo(1);

    return 0;
}
