#include <iostream>
#include <cstdio>
using namespace std;

struct Item{
  int weight;
  int price;
};

int main(){

  int T;
  while( scanf("%d", &T) != EOF ){
    for( int testcase = 0 ; testcase < T ; ++testcase ){
      int N;
      scanf("%d", &N);

      Item items[1005];
      for( int i = 0 ; i < N ; ++i ){
        scanf("%d%d", &items[i].price, &items[i].weight);
      }

      int G;
      scanf("%d", &G);

      int MW;
      int maxValue = 0;
      for( int i = 0 ; i < G ; ++i ){
        scanf("%d", &MW);

        int dp[35] = {0};
        for( int j = 0 ; j < N ; ++j ){
          for( int k = MW ; k >= 0 ; --k ){
            if( k >= items[j].weight ){
              dp[k] = max(dp[k], dp[k-items[j].weight]+items[j].price);
            }
          }
        }

        maxValue += dp[MW];
      }

      printf("%d\n", maxValue);
    }
  }
  return 0;
}
