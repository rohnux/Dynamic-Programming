/*Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.

For example -
For N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}.So output should be 4. 
For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
*/

//C++ Program to implement Coin Change Problem

#include <bits/stdc++.h>
using namespace std;

long int coin_change (int coin[],int n,int sum)
{
    long  int dp[n+1][sum+1];
    if(sum==0)
        return 1;
    if(sum>0 && n==0)
        return 0;

    for(int i=0; i<=n; i++)
        dp[i][0]=1;
    for(int j=1; j<=sum; j++)
        dp[0][j]=0;


    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            if(j>=coin[i-1])
            {
                dp[i][j]=dp[i-1][j] + dp[i][j-coin[i-1]];
            }
            else
                dp[i][j]=dp[i-1][j];

        }
    }

    return dp[n][sum];

}

int main()
{
    int sum,n;
    cin>>sum>>n;
    int coin[n];
    for(int i=0; i<n; i++)
        cin>>coin[i];

    cout<<coin_change(coin,n,sum);


    return 0;
}

