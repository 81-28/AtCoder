// https://atcoder.jp/contests/abc339/tasks/abc339_a

#include<bits/stdc++.h>
using namespace std;
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    string t = "";
    for (int i=n-1; i>=0; i--) {
        if (s[i]!='.') t=s[i]+t;
        else break;
    }
    print(t);

    return 0;
}
