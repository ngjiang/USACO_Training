/*
ID: ngjiang1
LANG: C
TASK: friday
*/

/*
This program answer how many days on each day...
*/

#include <stdio.h>
#include <stdlib.h>

int number_of_days(int month, int year)
{
	if(month == 2)
		if(year % 400)
			if(year % 100)
				if(year % 4) 
					return 28;
				else return 29;
			else return 28;
		else return 29;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else return 31;
}


int main()
{
	int N, i, j, k, first_day, day13, days[7];
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);
	scanf("%d", &N);
	for (i=0; i<7; i++) days[i] = 0;
	first_day = 1;
	day13 = (first_day + 12) % 7;
	for (i=0; i<N; i++) for (k=0; k<12; k++)
	{
		int length = number_of_days(k+1, i+1900);
		days[day13] ++;
		day13 = (day13 + length) % 7;
	}
	for (i=0; i<6; i++)
		printf ("%d ", days[(i+6)%7]);
	printf ("%d\n", days[(i+6)%7]);
	return 0;
}
