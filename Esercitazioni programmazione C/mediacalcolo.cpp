#include<stdio.h>

main()									/* mediacalcolo */
{
	int i,N;
	float S,M;
	float dat[100];
	printf("Inserire quantita' dati \n");
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		printf("Inserire il dato attuale \n");
		scanf("%f",&dat[i]);
	}
	S=0.0;
	for(i=0;i<N;i++)
	{
		S=S+dat[i];
	}
	M=S/N;
	printf("la media dei dati vale: \n");
	printf("%f",M);
}
