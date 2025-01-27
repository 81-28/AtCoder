// https://atcoder.jp/contests/abc328/tasks/abc328_d

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
    int n=s.size();
    int i=0;
    string t="";
    rep(j,n) {
        t += s[j];
        if(i>=2 && t[i]=='C' && t[i-1]=='B' && t[i-2]=='A') {
            rep(k,3) t.pop_back();
            i-=3;
        }
        i++;
    }
    print(t);

    return 0;
}