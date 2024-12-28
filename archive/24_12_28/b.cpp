// https://atcoder.jp/contests/abc386/tasks/abc386_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    int ans=0;
    rep(i,n) {
        if (s[i] != '0') {
            ans++;
        } else {
            if (i+1 < n && s[i+1]=='0') {
                i++;
            }
            ans++;
        }
    }
    print(ans);

    return 0;
}
