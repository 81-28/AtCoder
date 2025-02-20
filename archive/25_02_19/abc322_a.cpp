// https://atcoder.jp/contests/abc322/tasks/abc322_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    rep(i,n-2) {
        if (s.substr(i,3) == "ABC") {
            print(i+1);
            return 0;
        }
    }
    print(-1);

    return 0;
}
