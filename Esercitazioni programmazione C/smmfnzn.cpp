#include<stdio.h>

float Somma(float a, float b);
float sommaind(float *a, float *b);

main()
{
	float a,b,somma,somma1=0.0;
	printf("Inserire un numero: ");
	scanf("%f",&a);
	printf("Inserire secondo numero: ");
	scanf("%f",&b);
	somma=Somma(a,b);
	printf("la somma vale: %f",somma);
	printf("\nora si calcoli la somma passando per indirizzo");
	somma1=sommaind(&a,&b);
	printf("\nla nuova somma vale: %f",somma1);
}

float Somma(float a, float b)
{
	float totale;
	totale=a+b;
	return totale;
}

float sommaind(float *a, float *b)
{
	float totale;
	totale=*a+*b;
	return totale;
}
