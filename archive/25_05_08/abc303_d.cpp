// https://atcoder.jp/contests/abc303/tasks/abc303_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll=long long;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll x,y,z;
    string s;
    cin >> x >> y >> z >> s;
    ll n=s.size(),dp00,dp01,dp10,dp11;
    if (s[0]=='a') {
        dp01=x;
        dp11=z+y;
    } else {
        dp01=y;
        dp11=z+x;
    }
    for (int i=1; i<n; i++) {
        dp00=dp01;
        dp10=dp11;
        if (s[i]=='a') {
            dp01=min(dp00,dp10+z)+x;
            dp11=min(dp00+z,dp10)+y;
        } else {
            dp01=min(dp00,dp10+z)+y;
            dp11=min(dp00+z,dp10)+x;
        }
    }
    print(min(dp01,dp11));

    return 0;
}
