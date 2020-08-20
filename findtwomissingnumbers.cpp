// Blog Link :- https://www.geeksforgeeks.org/find-two-missing-numbers-set-1-an-interesting-linear-time-solution/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int totalxor=arr[0];
    for(int i=1;i<n;i++){
        totalxor^=arr[i];
    }
    for(int i=1;i<=n+2;i++){
        totalxor^=i;
    }
    int setbitno=(totalxor)&~(totalxor-1);
    
    int x=0,y=0;
    for(int i=0;i<n;i++){
        if(arr[i]&setbitno){
            x^=arr[i];
        }
    }
    for(int i=1;i<=n+2;i++){
        if(i&setbitno){
            x^=i;
        }
    }
    y=x^totalxor;
    cout<<x<<" "<<y;
    
    return 0;
}