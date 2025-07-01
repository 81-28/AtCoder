// https://atcoder.jp/contests/abc348/tasks/abc348_b

// Ctrl + Shift + B       => Build
// Terminal << "./a.out"  => Run

#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
// using mint = modint1000000007;
int dist2(int xA,int yA,int xB,int yB){
    return pow(xA-xB,2)+pow(yA-yB,2);
}

int main() {
    int n;
    cin >> n;
    int x[n],y[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        cin >> y[i];
    }
    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            if (i!=j)
            {
                if (dist2(x[ans],y[ans],x[i],y[i]) < dist2(x[i],y[i],x[j],y[j]))
                {
                    ans = j;
                }
                
            }
        }
        cout << ans+1 << endl;
    }
    
    


    return 0;
}
