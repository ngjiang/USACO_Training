/*
LANG: C
PROB: gift1
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);
	int np;
	scanf("%d",&np);
	char name[np][32];
	int balance[np];
	for(int i=0; i<np; i++) scanf("%s", name[i]), balance[i] = 0;
	for(int i_giver=0; i_giver<np; i_giver++){
		char name_of_giver[32];
		scanf("%s", name_of_giver);
		int i, total_gift, n_receivers;
		for (i=0; i<np && strcmp(name_of_giver, name[i]); i++);
		scanf("%d %d", &total_gift, &n_receivers);
		if (! n_receivers) continue; 
		balance[i] -= total_gift;
		balance[i] += total_gift % n_receivers;
		for (int j_receiver=0; j_receiver < n_receivers; j_receiver ++){
			int j;
			char name_of_receiver[32];
			scanf("%s", name_of_receiver);
			for (j=0; j<np && strcmp(name_of_receiver, name[j]); j++);
			balance[j] += total_gift / n_receivers;
		}
	}
	for (int i=0; i<np; i++)
		printf("%s %d\n", name[i], balance[i]);
	
	exit(0);
}
