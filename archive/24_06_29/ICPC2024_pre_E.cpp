// ICPC_pre_e

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> ans;
    int index = 0;
    while(true){
        int n,m;
        cin >> n >> m;
        if (n+m == 0)
        {
            break;
        } else {
            ans.push_back(INT_MAX);
            vector<int> a;
            for (int i = 0; i < n; i++)
            {
                int nowA;
                cin >> nowA;
                a.push_back(nowA);
            }
            
            for (int i = 0; i < n-1; i++)
            {
                int c = 0;
                int sum = 1;
                for (int j = 0; j < n; j++)
                {
                    int nowA;
                    if (j == i)
                    {
                        nowA = a[j+1];
                    } else if (j == i+1) {
                        nowA = a[j-1];
                    } else {
                        nowA = a[j];
                    }

                    c += nowA;
                    if (c > m)
                    {
                        c = nowA;
                        sum++;
                    }
                }
                
                ans[index] = min(sum,ans[index]);
            }
            
        }
        index++;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}