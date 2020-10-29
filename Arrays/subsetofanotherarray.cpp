#include<bits/stdc++.h>
using namespace std;
bool arraySubset(int arr1[], int arr2[], int m, int n)
{
    unordered_set<int> s;
    for(int i = 0; i < m; i++)
    {
        s.insert(arr1[i]);
    }
    
    for(int i = 0; i < n; i++)
    {
        if(s.find(arr2[i]) == s.end())
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    int T;
    cin >> T;
    
    while(T--)
    {
        int m, n;
        cin >> m >> n;
        
        int arr1[m];
        for(int i = 0; i < m; i++)
        {
            cin >> arr1[i];
        }
        
        int arr2[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr2[i];
        }
        
        if(arraySubset(arr1, arr2, m, n) == true)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
        
        cout << endl;
    }
	return 0;
}