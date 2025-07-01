// https://atcoder.jp/contests/abc387/tasks/abc387_a

#include<bits/stdc++.h>
using namespace std;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a,b;
    cin >> a >> b;
    print((a+b)*(a+b));

    return 0;
}
