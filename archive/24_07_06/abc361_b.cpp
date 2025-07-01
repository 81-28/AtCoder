// https://atcoder.jp/contests/abc361/tasks/abc361_b

#include <bits/stdc++.h>
using namespace std;

#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
}


int main() {
    vector<int> a(6),b(6);
    cin >> a >> b;
    YesNo(((a[0] < b[3] && a[3] > b[0]) || (a[0] > b[3] && a[3] < b[0])) && ((a[1] < b[4] && a[4] > b[1]) || (a[1] > b[4] && a[4] < b[1])) && ((a[2] < b[5] && a[5] > b[2]) || (a[2] > b[5] && a[5] < b[2])));

    return 0;
}
