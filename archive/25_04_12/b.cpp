// https://atcoder.jp/contests/abc401/tasks/abc401_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    bool ok=0;
    int ans=0;
    string s;
    rep(i,n) {
        cin >> s;
        if (s=="login") ok=1;
        if (s=="logout") ok=0;
        if (s=="private") {
            if (!ok) ans++;
        }
    }
    print(ans);

    return 0;
}
