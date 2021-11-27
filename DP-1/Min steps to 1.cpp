#include <bits/stdc++.h>
using namespace std;
 
// function to calculate min steps
int countMinStepsToOne(int n, int *memo)
{
    // base case
    if (n == 1)
       return 0;
    if (memo[n] != -1)
       return memo[n];
 
    // store temp value for n as min( f(n-1),
    // f(n/2), f(n/3)) +1
    int res = countMinStepsToOne(n-1, memo);
 
    if (n%2 == 0)
        res = min(res, countMinStepsToOne(n/2, memo));
    if (n%3 == 0)
        res = min(res, countMinStepsToOne(n/3, memo));
 
    // store memo[n] and return
    memo[n] = 1 + res;
    return memo[n];
}
 
// This function mainly initializes memo[] and
// calls getMinSteps(n, memo)
int countMinStepsToOne(int n)
{
    int memo[n+1];
 
    // initialize memoized array
    for (int i=0; i<=n; i++)
        memo[i] = -1;
 
    return  countMinStepsToOne(n, memo);
}
 
// driver program
/*int main()
{
    int n = 10;
    cout << countMinStepsToOne(n);
    return 0;
}*/
