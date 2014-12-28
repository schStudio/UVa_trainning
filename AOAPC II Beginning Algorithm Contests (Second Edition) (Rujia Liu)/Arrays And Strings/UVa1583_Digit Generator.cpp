#include <cstdio>
#include <cstring>
#include <ctype.h>

#define maxn 100005
int ans[maxn];

void solve()
{
   for( int m = 1; m < maxn; ++m ) {
      int x = m, y = m;
      while( x > 0 ) {
         y += x % 10;
         x /= 10;
      }
      if( ans[y]==0 || m<ans[y] )
         ans[y] = m;
   }

   int T, n;
   scanf( "%d", &T );
   while( T-- ) {
      scanf("%d",&n);
      printf("%d\n", ans[n]);
   }
}
int main()
{
   solve();
}
