// https://atcoder.jp/contests/abc342/tasks/abc342_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    string s;
    cin >> n >> s >> q;
    unordered_map<char,char> m;
    for(char i='a'; i<='z'; i++) m[i]=i;
    char c,d;
    rep(i,q) {
        cin >> c >> d;
        for(char i='a'; i<='z'; i++) {
            if(m[i]==c) m[i]=d;
        }
    }
    rep(i,n) s[i] = m[s[i]];
    print(s);

    return 0;
}
