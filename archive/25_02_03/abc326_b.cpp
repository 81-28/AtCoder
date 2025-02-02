// https://atcoder.jp/contests/abc326/tasks/abc326_b

#include<bits/stdc++.h>
using namespace std;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int a,b,c;
    for (int i=n; i<=919; i++) {
        a=i/100,b=i/10%10,c=i%10;
        if (a*b==c) {
            print(i);
            return 0;
        }
    }

    return 0;
}
