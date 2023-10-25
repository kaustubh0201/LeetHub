//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N) {
        // code here
        
        A[N - 1] = -1;
        
        for (int i = N - 2; i >= 0; i--) {
            
            int end = i + A[i];
            
            if (end >= N)
                end = N - 1;
            
            for (int j = i + 1; j <= end; j++) {
                
                if (A[j] == -1) {
                    A[i] = -1;
                    break;
                }
            }
        }
        
        if (A[0] == -1)
            return 1;
            
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends