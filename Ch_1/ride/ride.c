/*
LANG: C
PROB: ride
*/

#include <stdio.h>
#include <stdlib.h>
void main(){
	FILE *fin  = fopen("ride.in", "r");
	FILE *fout = fopen("ride.out", "w");
	char a[2][8];
	fscanf(fin, "%s", a[0]);
	fscanf(fin, "%s", a[1]);
	int s[2], i, j;
	for(i=0; i<2; i++)
		for(s[i]=1, j=0; a[i][j]!=0; j++)
			s[i] = (s[i] * (a[i][j] - 'A' + 1)) % 47;
	if (s[0] == s[1]) fprintf (fout, "GO\n");
	else fprintf (fout, "STAY\n");
	exit(0);
}
