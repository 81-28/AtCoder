// https://atcoder.jp/contests/abc397/tasks/abc397_b

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
    int ans=0;
    char l='i';
    int c=0;
    rep(i,n) {
        l=s[i];
        if (c%2) {
            if (l!='o') {
                ans++;
                c--;
            }
        } else {
            if (l!='i') {
                ans++;
                c--;
            }
        }
        c++;
    }
    if(l=='i')ans++;
    print(ans);

    return 0;
}
