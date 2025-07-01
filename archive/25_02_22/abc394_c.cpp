// https://atcoder.jp/contests/abc394/tasks/abc394_c

#include<bits/stdc++.h>
using namespace std;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    for (int i=n-1; i>0; i--) {
        if (s[i-1]=='W' && s[i]=='A') {
            s[i-1] = 'A';
            s[i] = 'C';
        }
    }
    print(s);

    return 0;
}
