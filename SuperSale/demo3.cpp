#include <bits/stdc++.h>
using namespace std;
int main()
{
    int wt[1005],val[1005],W[1005],V[1005][120],w,i,g,t,j,n,k,m;
    cin>>t;
    for(j=1;j<=t;j++)
    {
        cin>>n;
        int sum=0;
        for(i=1;i<=n;i++)
        {
            cin>>val[i]>>wt[i];
        }
        cin>>g;
        for(k=1;k<=g;k++)
        {
            cin>>W[k];
        }
        for(w=0;w<n;w++)
        {
            V[0][w]=0;
        }
        for(m=0;m<n;m++)
        {
            V[m][0]=0;
        }
        for(k=1;k<=g;k++)
        {
            for(m=1;m<=n;m++)
            {
                for(w=1;w<=W[k];w++)
                {
                    if(wt[m]>w)
                    {
                        V[m][w]=V[m-1][w];
                    }
                    else
                    {
                        V[m][w]=max(V[m-1][w],val[m]+V[m-1][w-wt[m]]);
                    }
                }
            }
            sum=sum+V[n][W[k]];
        }
        cout<<sum<<endl;

    }
    return 0;
}
