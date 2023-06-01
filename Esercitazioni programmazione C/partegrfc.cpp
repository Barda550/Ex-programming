#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

main()
{
	long long N,i,contatore=0,var;
	float x,y,fx,area,media,std,espG,t,max,min,fmax,areaR,areaG,contan;
	srand(time(NULL));
	printf("Inserire la quantita' di numeri da generare ");
	scanf("%d",&N);
	printf("Inserire valore media: ");
	scanf("%f",&media);
	printf("Inserire valore dev. standard: ");
	scanf("%f",&std);
	printf("Inserire valore di discostamento: ");
	scanf("%f",&t);
	min=media;
	max=media+t*std;
	fmax=(1.0/(std*sqrt(2*M_PI)));
	for(i=0;i<N;i++)
	{
		var=rand();
		x=(float)var/(RAND_MAX);
		x=x*(max-min)+min;
		espG=(pow(x-media,2))/(2*pow(std,2));
		fx=(1.0/(std*sqrt(2*M_PI)))*exp(-espG);
		var=rand();
		y=(float)var/(RAND_MAX);
		y=y*fmax;
		if(y<=fx)
			contatore++;
	}
	contan=(float)contatore/N;
	areaR=fmax*(max-min);
	areaG=areaR*contan;
	printf("la sezione della gaussiana vale: %f",areaG);
}
