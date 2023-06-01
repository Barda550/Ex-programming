#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

main()
{
	int N,i=0;
	float max,min,var,x,y,std=1.320714,media=11.037340,expG,ytrue,fmax,fx,a=0.0,b;
	FILE *fp;
	fp=fopen("attrito.dat","w");
	srand(time(NULL));
	printf("Inserire la quantita' di numeri da generare ");
	scanf("%d",&N);
	max=media+2.5*std;
	min=media-2.5*std;
	fmax=(1.0/(std*sqrt(2*M_PI)));
	while(i<=N)
	{
		var=rand();
		x=(float)var/RAND_MAX;
		x=x*(max-min)+min;
		expG=(pow(x-media,2))/(2*pow(std,2));
		ytrue=(1.0/(std*sqrt(2*M_PI)))*exp(-expG);
		var=rand();
		y=(float)var/RAND_MAX;
		y=y*fmax;
		if(y<=ytrue)
		{
			printf("%d: %f\n",i,x);
			i++;
			fprintf(fp,"%f\n",x);
		}
	}
	/*printf("Inserire valore massimo ");
	scanf("%f",&b);
	srand(time(NULL));
	while(i<N)
	{
		x=(rand()%RAND_MAX);
		x=(b-a)*rand()/(RAND_MAX)+a;
		fx=(1.0/(media))*exp(-(1.0/media))*x;
		y=((RAND_MAX)*rand()%RAND_MAX);
		if(y<=fx)
		{
			fprintf(fp,"%f \n",x);
			printf("%f \n",x);
			i++;
		}
	}*/
}
