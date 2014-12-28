#include <cstdio>
#include <cstring>
#include <ctype.h>

const char* str = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[] = { "not a palindrome", "a regular palindrome",
                  "a mirrored string", "a mirrored palindrome" };

char rev( char c )
{
   if ( isalpha(c) ) return str[c-'A'];
   else return str[c-'0'+25];
}
void solve()
{
   char s[30];
   while ( scanf("%s",s) == 1 ) {
      int m = 1, p = 1;
      int len = strlen( s );
      for ( int i = 0; i < (len+1)/2; ++i ) {
         if ( s[i] != s[len-1-i] ) p = 0;
         if ( rev(s[i]) != s[len-1-i] ) m = 0;
      }
      printf( "%s -- is %s.\n\n", s, msg[m*2+p] );
   }
}
int main()
{
   solve();
}
