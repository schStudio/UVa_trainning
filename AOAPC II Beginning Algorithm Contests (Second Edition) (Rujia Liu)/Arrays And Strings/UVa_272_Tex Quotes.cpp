#include <cstdio>

void solve()
{
   int c, q = 1;
   while ( (c=getchar()) != EOF ) {
      if ( c=='"' ) {
         printf( "%s", q ? "``" : "''" );
         q = !q;
      }
      else {
         printf( "%c", c );
      }
   }
}
int main()
{
   solve();
}
