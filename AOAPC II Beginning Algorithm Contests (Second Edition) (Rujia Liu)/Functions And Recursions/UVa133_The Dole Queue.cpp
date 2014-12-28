#include <stdio.h>

int a[30];
int n, k, m;

int go( int p, int d, int t)	//顺时针和逆时针走动的实现思路是一致的
{								//这里使用d作为“步长”就可以不加区分了
	while( t-- ) {
		do {
			p = (p+d+n+1) % (n+1);	//注意d=-1的时候可能会出现负数
		}while( a[p] == 0 );
	}
	return p;
}
void init( int *a, int n )
{
	for( int i = 1; i <= n; ++i )
		a[i] = i;
}
void solve()
{
	while( scanf( "%d%d%d", &n, &k, &m ) == 3 && n && k && m ) {
		init(a, n);
		int left = n;
		int p1, p2;
		p1 = n, p2 = 1;
		while( left ) {
			p1 = go( p1, 1, k );
			p2 = go( p2, -1, m );
			printf("%3d", a[p1] );
			a[p1] = 0;
			left--;
			if( p1 != p2 ) {
				printf( "%3d", a[p2] );
				a[p2] = 0;
				left--;
			}
			if( left ) printf( "," );	//巧妙的用了while(t--)中的t的变化
		}
		printf( "\n" );
	}
}
int main()
{
	//freopen( "in", "r", stdin );
	//freopen( "out", "w", stdout );
	solve();
	return 0;
}