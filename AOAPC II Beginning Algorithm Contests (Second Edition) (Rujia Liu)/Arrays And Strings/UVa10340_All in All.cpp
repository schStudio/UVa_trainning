#include <stdio.h>
#include <algorithm>

using namespace std;

struct r{
	int w;
	int h;
} R[6];
int cmp( struct r a, struct r b )
{
	if( a.w != b.w )
		return a.w < b.w;
	return a.h < b.h;
}
bool isEqualA()
{
	if ( R[0].w == R[1].w && R[2].w == R[3].w )
		if ( R[0].w == R[2].w )
		return true;
	return false;
}
bool isEqualB()
{
	if ( R[0].h == R[1].h && R[4].w == R[5].w )
		if ( R[0].h == R[4].w )
		return true;
	return false;
}
bool isEqualC()
{
	if ( R[2].h == R[3].h && R[4].h == R[5].h )
		if ( R[2].h == R[4].h )
		return true;
	return false;
}
void solve()
{
	int i = 0;
	while( scanf("%d%d", &R[i%6].w, &R[i%6].h) != EOF) {	//针对一个case多行输入，EOF结束
		bool ans = false;
		if ( R[i%6].w > R[i%6].h ) {
         int t = R[i%6].w;
         R[i%6].w = R[i%6].h;
         R[i%6].h = t;
		}
		i++;
		if ( i % 6 == 0 ) {
			sort( R, R+6, cmp );
			if( isEqualA() && isEqualB() && isEqualC() )
				ans = true;
			else
				ans = false;
			printf( "%s\n", ans ? "POSSIBLE" : "IMPOSSIBLE" );
		}
	}

}
int main()
{
	//freopen( "in", "r", stdin );
	//freopen( "out", "w", stdout );
	solve();
	return 0;
}
