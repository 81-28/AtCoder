// https://atcoder.jp/contests/abc379/tasks/abc379_a

#include<bits/stdc++.h>
using namespace std;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int a = (n/100)%10;
    int b = (n/10)%10;
    int c = n%10;
    print(b*100+c*10+a,c*100+a*10+b);

    return 0;
}
