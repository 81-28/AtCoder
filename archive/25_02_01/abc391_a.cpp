// https://atcoder.jp/contests/abc391/tasks/abc391_a

#include<bits/stdc++.h>
using namespace std;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string d;
    cin >> d;
    if (d=="N") print("S");
    if (d=="S") print("N");
    if (d=="E") print("W");
    if (d=="W") print("E");
    if (d=="NE") print("SW");
    if (d=="SW") print("NE");
    if (d=="SE") print("NW");
    if (d=="NW") print("SE");

    return 0;
}
