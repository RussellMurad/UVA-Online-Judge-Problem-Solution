#include <bits/stdc++.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
using namespace std;

int main ()
{
    int testCase;
    scanf ("%d", &testCase);

    while ( testCase-- ) {
        int objects;
        int values [1000 + 5];
        int weight [1000 + 5];

        scanf ("%d", &objects);

        for ( int i = 0; i < objects; i++ )
            scanf ("%d %d", &values [i], &weight [i]);

        int dp [30 + 5];
        memset (dp, 0, sizeof (dp));


        for ( int j = 0; j < objects; j++ ) {
            for ( int i = 32; i >= 0; i-- ) {
                if ( weight [j] <= i && dp [i] < dp [i - weight [j]] + values [j] )
                    dp [i] = dp [i - weight [j]] + values [j];
            }
        }

        int g;
        scanf ("%d", &g);

        int maxPrice = 0;

        while ( g-- ) {
            int volume;
            scanf ("%d", &volume);
            maxPrice += dp [volume];
        }

        printf ("%d\n", maxPrice);
    }

    return 0;
}
