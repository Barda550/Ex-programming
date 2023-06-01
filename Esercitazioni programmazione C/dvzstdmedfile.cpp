#include<stdio.h>
#include<math.h>
#include<stdlib.h>

main()
{
	int i,N;
	float S,M,M1=0,M2=0,std;
	float dat[100];
	FILE *fp;
	fp=fopen("dati.dat","r");
	fscanf(fp,"%d",&N);
	S=0.0;
	for(i=0;i<N;i++)
	{
		fscanf(fp,"%f",&dat[i]);
		S=S+dat[i];
	}
	M=S/N;
	for(int i=0;i<N;i++)
	{
		fscanf(fp,"%f",&dat[i]);
		M1=M1+dat[i];
		M2=M2+dat[i]*dat[i];
	}
	M1=M1/N;
	M2=M2/N;
	std=sqrt(M2-M1*M1);
	printf("la deviazione standard dei dati inseriti vale: %f",std);
	printf("\nla media dei dati vale: %f",M);
	fclose(fp);
}
