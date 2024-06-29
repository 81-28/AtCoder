// ICPC_pre_b

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    string l = "";
    string r = "";
    for (int i = 0; i < n; i++)
    {
        string a;
        char c;
        cin >> a >> c;
        if (a == "INSERT")
        {
            l += c;
        } else if(a == "LEFT") {
            if (l.length() > 0)
            {
                r = l[l.length()-1] + r;
                l.resize(l.length()-1);
            }
            
        }
        else if (a == "RIGHT")
        {
            if (r.length() > 0)
            {
                l += r[0];
                int rLen = r.length();
                string newR;
                for (int j = 1; j < rLen; j++)
                {
                    newR[j-1] = r[j];
                }
                r = newR;
            }
            
        }
        
    }
    cout << l+r << endl;
    
    return 0;
}