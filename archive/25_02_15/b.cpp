// https://atcoder.jp/contests/abc393/tasks/abc393_b

#include<bits/stdc++.h>
using namespace std;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    int ans=0;
    for (int i=0; i<=n-3; i++) {
        for (int j=i+1; j<=n-2; j++) {
            for (int k=j+1; k<=n-1; k++) {
                if (j-i==k-j && s[i]=='A' && s[j]=='B' && s[k]=='C') ans++;
            }
        }
    }
    print(ans);

    return 0;
}
