// https://atcoder.jp/contests/abc319/tasks/abc319_a

#include<bits/stdc++.h>
using namespace std;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    if(s=="tourist") print(3858);
    if(s=="ksun48") print(3679);
    if(s=="Benq") print(3658);
    if(s=="Um_nik") print(3648);
    if(s=="apiad") print(3638);
    if(s=="Stonefeang") print(3630);
    if(s=="ecnerwala") print(3613);
    if(s=="mnbvmar") print(3555);
    if(s=="newbiedmy") print(3516);
    if(s=="semiexp") print(3481);

    return 0;
}