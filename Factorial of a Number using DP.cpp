//C++ Program to Find Factorial of a Number using Dynamic Programming

#include <iostream>
using namespace std;

long long int factorialDP(int n)
{
    long long int a[n+1]; // factorials array

        a[0]=1;
        for(int i=1; i<=n; i++)
        {
            a[i] = i * a[i-1];
        }

        return a[n];
    }

int main()
{ int t,n;
cout<<"----------------------------Factorial of a Number-----------------------------";
cout<<"\nEnter the test cases : ";
cin>>t;
    while(t--)
  {   cout<<"\nEnter integer to compute factorial : ";
      cin>>n;
      long long int ans =factorialDP(n);
      cout<<"Factorial of "<<n<<" is :";
      cout<<ans<<"\n";
}
    return 0;
}
