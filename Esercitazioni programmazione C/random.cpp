#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main()
{
	/*int N,i,casuale[1000];
	srand(time(NULL));
	printf("Inserire la quantita' di numeri da generare ");
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		casuale[i]=rand()%RAND_MAX;
		printf("%d\n",casuale[i]);
	}*/
	/*int N,i,casuale[1000],max;
	srand(time(NULL));
	printf("Inserire la quantita' di numeri da generare ");
	scanf("%d",&N);
	printf("Inserire il massimo valore possibile ");
	scanf("%d",&max);
	for(i=0;i<N;i++)
	{
		casuale[i]=rand()%max;
		printf("%d\n",casuale[i]);
	}*/
	/*int N,i;
	double casuale[1000];
	srand(time(NULL));
	printf("Inserire la quantita' di numeri da generare ");
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		casuale[i]=rand()/(2.0*RAND_MAX);
		printf("%f\n",casuale[i]);
	}*/
	/*int N,i;
	float max,casuale[1000];
	srand(time(NULL));
	printf("Inserire la quantita' di numeri da generare ");
	scanf("%d",&N);
	printf("Inserire il massimo valore possibile ");
	scanf("%f",&max);
	for(i=0;i<N;i++)
	{
		casuale[i]=(((float)rand()/(float)(RAND_MAX))*max);
		printf("%f\n",casuale[i]);
	}*/
	int N,i;
	float max,min,casuale[1000];
	srand(time(NULL));
	printf("Inserire la quantita' di numeri da generare ");
	scanf("%d",&N);
	printf("Inserire il massimo valore possibile ");
	scanf("%f",&max);
	printf("Inserire il minimo valore di partenza ");
	scanf("%f",&min);
	for(i=0;i<N;i++)
	{
		casuale[i]=((max-min)*((float)rand()/(float)(RAND_MAX)))+min;
		printf("%f\n",casuale[i]);
	}
}
