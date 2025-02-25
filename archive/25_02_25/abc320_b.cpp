// https://atcoder.jp/contests/abc320/tasks/abc320_b

#include<bits/stdc++.h>
using namespace std;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

bool isPal(const string& s) {
    int l=0,r=s.size()-1;
    for(; l<r; l++,r--) {
        if(s[l]!=s[r]) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    for (int i=n; i>1; i--) {
        for (int j=0; j<n-i+1; j++) {
            if (isPal(s.substr(j,i))) {
                print(i);
                return 0;
            }
        }
    }
    print(1);

    return 0;
}
