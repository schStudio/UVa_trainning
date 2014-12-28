#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

char s[55][1005];
struct grid{
	char s;
	int ct;
};
//全局是不能执行语句的
int cmp( grid a, grid b)
{
	if( a.ct > b.ct )
		return a.ct > b.ct;		//排序中返回的是a>b则表示降序，a<b则为升序
	return a.s < b.s;
}
void setGrid()
{
   atcg[0].s = 'A';atcg[0].ct = 0;
   atcg[1].s = 'C';atcg[1].ct = 0;
   atcg[2].s = 'G';atcg[2].ct = 0;
   atcg[3].s = 'T';atcg[3].ct = 0;
}
void solve()
{
	int m, n;
	char ans[1005];
	int res = 0;
	int ct = 0;
	scanf( "%d%d", &m, &n );
	for( int i = 0; i < m; ++i ) {
		scanf( "%s", &s[i] );
	}
	for( int j = 0; j < n; ++j ) {
		for( int i = 0; i < m; ++i ) {
			switch( s[i][j] ) {
				case 'A': atcg[0].ct++;break;
				case 'C': atcg[1].ct++;break;
				case 'G': atcg[2].ct++;break;
				case 'T': atcg[3].ct++;break;
			}
		}
		sort( atcg, atcg+4, cmp );
		ans[ct++] = atcg[0].s;
		res += atcg[1].ct + atcg[2].ct + atcg[3].ct;
		setGrid();
	}
	ans[ct] = '\0';
	printf( "%s\n%d\n", ans, res );
}
int main()
{
	freopen( "in", "r", stdin );
	freopen( "out", "w", stdout );
	setGrid();
	int T;
	scanf( "%d", &T );
	while( T-- ) {
		solve();
	}
	return 0;
}
