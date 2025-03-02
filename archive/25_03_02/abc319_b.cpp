// https://atcoder.jp/contests/abc319/tasks/abc319_b

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
    string s="";
    bool d;
    for (int i=0; i<=n; i++) {
        d=0;
        rep1(j,9) {
            if (i*j%n == 0) {
                s+=(j+'0');
                d=1;
                break;
            }
        }
        if (!d) s+='-';
    }
    print(s);

    return 0;
}
