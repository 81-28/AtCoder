// https://atcoder.jp/contests/abc382/tasks/abc382_b

#include<bits/stdc++.h>
using namespace std;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,d;
    string s;
    cin >> n >> d >> s;
    int j = 0;
    for(int i=n-1; n>=0; i--) {
        if (s[i] == '@') {
            s[i] = '.';
            j++;
        }
        if (j==d) {
            break;
        }
    }
    print(s);

    return 0;
}
