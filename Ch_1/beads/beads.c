/*
PROB: beads
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>

char bead[512];
int n;

int backward[512], forward[512];

int main(){
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);
	scanf("%d", &n);
	scanf("%s", bead);
	// Count backward
	// Count continuous w's
	backward[0] = (bead[0] == 'w') ? 1:0;
	for (int i=1; i < n<<1; i++)
	{
		if (bead[i%n] == 'w') backward[i%n] = backward[(i+n-1)%n] +1;
		else backward[i%n] = 0;
		if (backward[i%n] > n) backward[i%n] = n;
	}
	// Count different colors other than w (with w's)
	for (int i=1; i < n<<1; i++) if (bead[i%n] != 'w')
	{
		if (bead[i%n] == bead[(i-1+n)%n]) 
			backward[i%n] = backward[(i-1+n)%n] + 1;
		else if (bead[(i-1+n)%n] == 'w')
		{
			if (bead[i%n] == bead[(i-backward[(i-1+n)%n]-1+n)%n])
				backward[i%n] = backward[(i-backward[(i-1+n)%n]-1+n)%n] + backward[(i-1+n)%n] + 1;
			else backward[i%n] = backward[(i-1+n)%n] + 1;
		}
		else backward[i%n] = 1;
	}
	// Renew the counts ending by w's
	for (int i=0; i<n; i++) if (bead[i%n] == 'w')
	{
		backward[i%n] += backward[(i-backward[i]+n)%n];
	}
	// Count forward
	// Count continuous w's
	forward[0] = (bead[0] == 'w') ? 1:0;
	for (int i=1; i < n<<1; i++)
	{
		if (bead[(-i+n+n)%n] == 'w') forward[(-i+n+n)%n] = forward[(-i+n+n+1)%n] +1;
		else forward[(n+n-i)%n] = 0;
		if (forward[(n+n-i)%n] > n) forward[(n+n-i)%n] = n;
	}
	// Count different colors other than w (with w's)
	for (int i=1; i < n<<1; i++) if (bead[(-i+n+n)%n] != 'w')
	{
		if (bead[(n+n-i)%n] == bead[(-i+1+n+n)%n]) 
			forward[(n+n-i)%n] = forward[(-i+1+n+n)%n] + 1;
		else if (bead[(-i+1+n+n)%n] == 'w')
		{
			if (bead[(n+n-i)%n] == bead[(-i+forward[(-i+1+n+n)%n]+1+n+n)%n])
				forward[(n+n-i)%n] = forward[(-i+forward[(-i+1+n+n)%n]+1+n+n)%n] + forward[(-i+1+n+n)%n] + 1;
			else forward[(n+n-i)%n] = forward[(-i+1+n+n)%n] + 1;
		}
		else forward[(n+n-i)%n] = 1;
	}
	// Renew the counts ending by w's
	for (int i=0; i<n; i++) if (bead[(n-i)%n] == 'w')
	{
		forward[(n-i)%n] += forward[(-i+forward[(n-i)%n]+n)%n];
	}

	
	// Test line
	/*
	for (int i=0; i<n; i++) printf("%d ", backward[i]);
	printf("\n");

	for (int i=0; i<n; i++) printf("%d ", forward[i]);
	printf("\n");
	*/
	int ans = 0;
	for (int i=0; i<n; i++) if (forward[(i+1)%n] + backward[i] > ans)
		ans = forward[(i+1)%n] + backward[i];
	if (ans > n) ans = n;
	printf("%d\n", ans);
	return 0;
}
