#include <cstdio>
const int MAX_N = 4;
bool used[MAX_N];
int perm[MAX_N];

void print()
{
   for ( int i = 0; i < MAX_N; ++i )
      printf( "%d ", perm[i] );
   printf("\n");

}
void permutation(int pos, int n)
{
   if ( pos == n ) {
      print();
      return;
   }
   for ( int i = 0; i < n; ++i ) {
      if ( !used[i] ) {
         perm[pos] = i+1;
         used[i] = true;
         permutation(pos+1, n);
         used[i] = false;
      }
   }
}
int main()
{
   permutation( 0, MAX_N );
}
