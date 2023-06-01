#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

main()
{
	long long N,i,contatore=0,var;
	float x,y,fx,pg,area;
	srand(time(NULL));
	printf("Inserire la quantita' di numeri da generare ");
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		var=rand();
		x=(float)var/(RAND_MAX);
		var=rand();
		y=(float)var/(RAND_MAX);
		fx=sqrt(1-x*x);
		if(y<=fx)
			contatore++;
	}
	area=(float)contatore/N;
	pg=4.0*area;
	printf("Il valore stimato di pigreco vale: %f",pg);
}
