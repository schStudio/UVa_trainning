#include <stdio.h>
#include <time.h>

void hanoi( int n, char a, char b, char c )
{
	if ( n == 1 ) {
		//printf( "%c -> %c\n", a, c );
		return;
	}
	hanoi( n-1, a, c, b );
	//printf( "%c -> %c\n", a, c );
	hanoi( n-1, b, a, c );
}
void solve()
{
	hanoi(33, 'a', 'b', 'c');
}
int main()
{
	//freopen( "out", "w", stdout );
	solve();
	printf( "time=%.2fs", (double)clock()/CLOCKS_PER_SEC );
	return 0;
}