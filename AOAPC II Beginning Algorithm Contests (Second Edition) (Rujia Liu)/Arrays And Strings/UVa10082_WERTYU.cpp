#include <cstdio>

char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

void solve()
{
   int c, pos;
   while ( (c=getchar()) != EOF ) {
      for ( pos=1; s[pos]&&s[pos]!=c; ++pos);
      if ( s[pos] ) putchar( s[pos-1] );
      else putchar(c);
   }
}
int main()
{
   solve();
}
