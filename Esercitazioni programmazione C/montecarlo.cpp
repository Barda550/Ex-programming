#include<stdio.h>

main()
{
	long a,c,m,N,i,seed,num=0,casuale[1000];
	printf("Inserire a ");
	scanf("%d",&a);
	printf("Inserire c ");
	scanf("%d",&c);
	printf("Inserire m ");
	scanf("%d",&m);
	printf("Inserire la quantita' di numeri da generare ");
	scanf("%d",&N);
	printf("Inserire il valore seed ");
	scanf("%d",&seed);
	casuale[0]=seed;
	printf("%d\n",seed);
	for(i=1;i<N;i++)
	{
		num=(a*casuale[i-1]+c);
		casuale[i]=num%m;
		printf("%d\n",casuale[i]);
	}
}

