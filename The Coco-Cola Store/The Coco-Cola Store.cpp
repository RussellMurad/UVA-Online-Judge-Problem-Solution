#include <bits/stdc++.h>
using namespace std;
int Empty=0,Full=0,Result=0;

int bottle(int n)
{
    if(n > 2)
    {
        Empty = n/3;
        Result += Empty;
        Full = n%3;
        n = Empty+Full;
        bottle(n);
    }

    else if(n == 2)
    {
        Result++;
        return Result;
    }

    else
        return Result;

}

int main()
{
    int N;

    while(scanf("%d",&N) != EOF)
    {
        if(N == 0)
            break;
        Result = 0;
        printf("%d\n",bottle(N));
    }

    return 0;
}
