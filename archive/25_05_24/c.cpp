// https://atcoder.jp/contests/abc407/tasks/abc407_c

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

int c(int a,int b) {
    return (a+10-b)%10;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    int ans=n+(s[n-1]-'0');
    for (int i=n-2; i>=0; --i) {
        ans+=c(s[i]-'0',s[i+1]-'0');
    }
    print(ans);

    return 0;
}
