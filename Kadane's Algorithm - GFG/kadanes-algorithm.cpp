//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        
        ll max_till_now = 0;
        ll max_num = LLONG_MIN;
        
        for (int i = 0; i < n; i++) {
            
            max_till_now += arr[i];
            
            if (max_till_now > max_num) {
                max_num = max_till_now;
            }
            
            if (max_till_now < 0) {
                max_till_now = 0;
            }
            
        }
        
        return max_num;
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends