// https://atcoder.jp/contests/abc328/tasks/abc328_b

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int ans = 0;
    int d;
    rep1(i,n) {
        cin >> d;
        if (i < 10) {
            if (i <= d) ans++;
            if (i*11 <= d) ans++;
        }
        if (i%11 == 0) {
            if (i/11 <= d) ans++;
            if (i <= d) ans++;
        }
    }
    print(ans);

    return 0;
}
