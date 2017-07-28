#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Super{
    int weight[1100];
    int price[1100];
};

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int T,N,G,MW[31],temp=0,X,count=0,flag=0,Price=0,sum=0,Total=0;
    Super Variable;
    cin >> T;

    while(T--)
    {
        count=0,Price=0,flag=0;
        cin >> N;
        for(int i=0; i<N; i++)
        {
            scanf("%d %d",&Variable.price[i],&Variable.weight[i]);
        }
        cin >> G;
        for(int i=0; i<G; i++)
        {
            scanf("%d",&MW[i]);
        }

        while(flag < G)
        {
            for(int i=0; i<N; i++)
            {
                if(MW[flag] >= Variable.weight[i])
                {
                    temp = MW[flag]; sum = 0;
                    temp -= Variable.weight[i];
                    sum += Variable.price[i];
                    cout << "Value of Sum in 1st stage: " << sum << endl << endl;
                    cout << "Weight of Temp in 1st stage: " << temp << endl << endl;

                    for(int j=0; /*i != j &&*/ j<N; j++)
                    {
                        if(i != j && temp >= Variable.weight[j])
                        {
                            temp -= Variable.weight[j];
                            sum += Variable.price[j];
                            cout << "Value of Sum in 2nd stage: " << sum << endl << endl;
                        }
                    }

                    if(count < sum)
                        count = sum;
                }
            }

            Price += count;
            count = 0;
            cout << "Price is " << Price << endl;

            flag++;
        }

        cout << Price << endl;
    }

    return 0;
}
