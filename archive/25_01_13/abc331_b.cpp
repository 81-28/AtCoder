// https://atcoder.jp/contests/abc331/tasks/abc331_b

#include<bits/stdc++.h>
using namespace std;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,s,m,l;
    cin >> n >> s >> m >> l;
    int ans = INT_MAX;
    for (int i=0; i*6<=n+6; i++) {
        for (int j=0; j*8<=n+8; j++) {
            for (int k=0; k*12<=n+12; k++) {
                if (i*6+j*8+k*12 >= n) {
                    ans = min(ans,s*i+m*j+l*k);
                    break;
                }
            }
        }
    }
    print(ans);

    return 0;
}
