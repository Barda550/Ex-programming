#include<stdio.h>
#include<math.h>

float Media(float *x, int N);
float devstd(float *x, int N);
void integrale(float min, float deltax, float std, float ampc, float media, int dx, float *area);
void esponenziale(float min, float deltax, float ampc, float *area, int dx, float media);
float uniforme(float a, float b, float var);
void minimiquad(char *nomefile);

main()
{
	int dx,i=0,j=0,contatore,k=0,N,frequenza[1000],lun=20;
	float x[1000],intervalli[1000],max,min,ampc,media,std,deltax,base,expG,altezza,area[1000],chi2=0.0,chi2rid=0.0,relativa[1000],E[1000],sommaarea,d,sommaArea;
	char type,nomefile[lun+1],scelta[lun];
	printf("Inserire il nome del file (20 lettere al massimo): ");
	scanf("%s",nomefile);
	nomefile[lun]=0;
	scelta[lun]=0;
	FILE *fp=fopen(nomefile,"r");
	while(fscanf(fp,"%f",&x[i])!=EOF)
	{
		i++;
	}
	N=i;
	do
	{
		printf("Inserire \nR--> retta \nD--> distribuzione: ");
		scanf("%s",scelta);
	}
	while(scelta[0]!='R'and scelta[0]!='D');
	if(scelta[0]=='R')
		minimiquad(nomefile);
	else
		if(scelta[0]=='D')
		{
			max=x[0];
			min=x[0];
			for(k=0;k<i;k++)
			{
				if(max<x[k])
					max=x[k];
				if(min>x[k])
					min=x[k];
			}
			dx=(int)sqrt(i);
			ampc=(max-min)/dx;
			for(k=0;k<(dx+1);k++)
			{
				intervalli[k]=min+k*ampc;
    		}
			for(k=0;k<dx;k++)
			{
				contatore=0;
				for(j=0;j<i;j++)
				{
					if((x[j]>=intervalli[k])and(x[j]<intervalli[k+1]))
						contatore++;
				}
				if(k==dx-1)
					contatore++;
				frequenza[k]=contatore;
				printf("le frequenze per lo specifico intervallo %d sono: %d\n",k,frequenza[k]);
			}
			printf("Le classi di frequenza sono: %d\nil massimo vale: %f\nil minimo vale: %f\nl'ampiezza e': %f\n",dx,max,min,ampc);
			std=devstd(x,N);
			media=Media(x,N);
			printf("La deviazione standard dei dati vale: %f",std);
			printf("\nla media dei dati vale: %f",media);
			printf("\n");
			deltax=ampc/1000000.0;
			printf("Distribuzione utilizzata \nG-> gaussiana, \nE-> esponenziale, \nU-> uniforme: ");
			scanf("%s",&type);
			if(type=='E')
				{
					esponenziale(min,deltax,ampc,area,dx,media);
					for(j=0;j<dx;j++)
						printf("l'area della distribuzione esponenziale vale: %f\n",area[j]);
					for(j=0;j<dx;j++)
						{
							relativa[j]=((float)frequenza[j]/N);
							printf("Le frequenze normalizzate: %f\n",relativa[j]);
							E[j]=area[j]*N;
							chi2=chi2+(pow((frequenza[j]-E[j]),2))/E[j];
						}
					printf("Il chi2 vale: %f",chi2);
					chi2rid=chi2/(dx-3);
					printf("\nIl chi2rid vale: %f",chi2rid);	
				}
				else
					if(type=='G')
						{
							integrale(min,deltax,std,ampc,media,dx,area);
							printf("I valori attesi della gaussiana sono:\n ");
							for(j=0;j<dx;j++)
								printf("l'area della gaussiana vale: %f\n",area[j]);
							for(j=0;j<dx;j++)
								{
									relativa[j]=((float)frequenza[j])/N;
									printf("\nLa frequenza normalizzata: %f",relativa[j]);
									E[j]=area[j]*N;
									chi2=chi2+(pow(frequenza[j]-E[j],2))/E[j];
								}
							printf("\nIl chi2 vale: %f",chi2);
							chi2rid=chi2/(dx-3);
							printf("\nIl chi2rid vale: %f",chi2rid);
						}
						else
							if(type=='U')
								{
									for(j=0;j<dx;j++)
										{
											sommaarea=0.0;
											for(k=0;k<1000000;k++)
												{
													d=min+j*dx+(k+0.5)*deltax;
													sommaarea=sommaarea+(uniforme(min,max,d)*deltax);
												}			
											area[j]=sommaarea;
											sommaArea+=area[j];
											printf("Valore dell'area totale (distr. unif.) = %f\n",sommaArea);
										}
									for(j=0;j<dx;j++)
										printf("l'area della distribuzione uniforme vale: %f\n",area[j]);
									for(j=0;j<dx;j++)
										{
											relativa[j]=((float)frequenza[j])/N;
											printf("\nLa frequenza normalizzata: %f",relativa[j]);
											E[j]=area[j]*N;
											chi2=chi2+(pow(frequenza[j]-E[j],2))/E[j];
										}				
									printf("\nIl chi2 vale: %f",chi2);
									chi2rid=chi2/(dx-3);
									printf("\nIl chi2rid vale: %f",chi2rid);
								}
		}
}
	
float Media(float *x, int N)
{
	float M=0.0,S=0.0;
	int i=0;
	for(i=0;i<N;i++)
	{
		S=S+x[i];
	}
	M=S/N;
	return M;
}

float devstd(float *x,int N)
{
	float std=0.0,M1=0.0,M2=0.0;
	int i=0;
	for(i=0;i<N;i++)
	{
		M1=M1+x[i];
		M2=M2+x[i]*x[i];
	}
	M1=M1/N;
	M2=M2/N;
	std=sqrt(M2-M1*M1);
	return std;
}

void integrale(float min, float deltax, float std, float ampc, float media, int dx, float *area)
{
	double base,expG,altezza;
	int j=0,k=0;
	for(j=0;j<dx;j++)
	{
		area[j]=0.0;
		for(k=0;k<1000000;k++)
		{
			base=min+j*ampc+((float)k+0.5)*deltax;
			expG=(pow(base-media,2))/(2*pow(std,2));
			altezza=(1.0/(std*sqrt(2*(M_PI))))*exp(-expG);
			area[j]=area[j]+deltax*altezza;	
		}
	}
}

void esponenziale(float min, float deltax, float ampc, float *area, int dx, float media)
{
	float a,base,altezza;
	int j=0,k=0;
	a=1.0/media;
	for(j=0;j<dx;j++)
	{
		area[j]=0.0;
		for(k=0;k<1000000;k++)
		{
			base=min+j*ampc+((float)k+0.5)*deltax;
			if(base>=0)
				altezza=a*exp(-a*base);
			else
				altezza=0.0;
			area[j]=area[j]+deltax*altezza;
		}
	}
}

float uniforme(float a, float b, float var)
{
	float v;
	if(var<a && var>b)
		v=0.0;
	else
		v=1.0/(b-a);
	return v;
}

void minimiquad(char *nomefile)
{
	float dtx[1000],dty[1000],sig[1000],sigy[1000],Sx=0.0,Sy=0.0,Sxy=0.0,Sx2=0.0,Syy=0.0,Sxx=0.0,S=0.0,D,A,B,S2,S3,errA,errB,R,SumX2=0.0,SumY2=0,SumTot=0.0,Mx,My,chi2=0.0;
	int i=0,j=0;
	FILE *fp;
	fp=fopen(nomefile,"r");
	while(fscanf(fp,"%f %f %f %f",&dtx[i],&dty[i],&sig[i],&sigy[i])!=EOF)
	{
		printf("x = %f, y = %f, sigma 'X' = %f sigma 'Y' = %f\n",dtx[i],dty[i],sig[i],sigy[i]);
		S3=sigy[i]*sigy[i];
		S2=sig[i]*sig[i];
		Sxx=Sxx+dtx[i];
		Syy=Syy+dty[i];
		Sx=Sx+dtx[i]/S2;
		Sy=Sy+dty[i]/S2;
		Sxy=Sxy+(dtx[i]*dty[i])/S2;
		Sx2=Sx2+pow(dtx[i],2)/S2;
		S=S+(1.0/S2);
		i++;
	}
	Mx=Sxx/i;
	My=Syy/i;
	D=(S*Sx2)-(Sx*Sx);
	A=((Sx2*Sy)-(Sx*Sxy))/D;
	B=((S*Sxy)-(Sx*Sy))/D;
	errA=sqrt((Sx2/D));
	errB=sqrt(S/D);
	for(j=0;j<i;j++)
	{
		SumTot=SumTot+(dtx[j]-Mx)*(dty[j]-My);
		SumX2=SumX2+pow(dtx[j]-Mx,2);
		SumY2=SumY2+pow(dty[j]-My,2);
	}
	R=SumTot/(sqrt(SumX2*SumY2));
	chi2=(pow((Syy-Sxx),2)/S3);
	printf("\n");
	printf("A = %f B = %f\nerrA = %f errB = %f\nR = %f chi2 = %f",A,B,errA,errB,R,chi2);
	if(R<=0.4)
		printf("\nil valore rappresentato e' ottimale");
	else printf("\nil valore rappresentato e' pessimo");
}
