#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int Range, int Weight[], int Price[], int S)
{
    int K[S+1][Range+1];

    for(int i=0; i<=S; i++)
    {
        for(int j=0; j<=Range; j++)
        {
            if(i == 0 || j == 0)
            {
                K[i][j] = 0;
            }

            else if(Weight[i-1] <= j)
            {
                K[i][j] = max(Price[i-1] + K[i-1][j-Weight[i-1]], K[i-1][j]);
            }


            else
            {
                K[i][j] = K[i-1][j];
            }

        }
    }

    return K[S][Range];
}

int main()
{
    int T,G,N,S=0,Sum=0,Price[1101],Weight[1101],Range;

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> T;

    while(T--)
    {
        Sum = 0,S = 0;
        cin >> N;
        for(int k=0; k<N; k++)
        {
            cin >> Price[k] >> Weight[k];
            S++;
        }

        cin >> G;

        for(int k=0; k<G; k++)
        {
            cin >> Range;
            Sum += knapSack(Range, Weight, Price, S);
        }

        cout << Sum << endl;

    }

    return 0;
}
