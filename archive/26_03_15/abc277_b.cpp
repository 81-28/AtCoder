// https://atcoder.jp/contests/abc277/tasks/abc277_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    v<map<char,bool>> b={
        {{'H',1},{'D',1},{'C',1},{'S',1}},
        {{'A',1},{'2',1},{'3',1},{'4',1},{'5',1},{'6',1},{'7',1},{'8',1},{'9',1},{'T',1},{'J',1},{'Q',1},{'K',1}}
    };
    int n;
    cin >> n;
    map<string,bool> mp;
    while (n--) {
        string s;
        cin >> s;
        if(mp[s]) {
            YesNo(0);
            return 0;
        }
        mp[s]=1;
        if (!b[0][s[0]] || !b[1][s[1]]) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}
