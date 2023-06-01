#include<stdio.h>
#include<math.h>

main()
{
	float dtx[1000],dty[1000],sig[1000],sigy[1000],Sx=0.0,Sy=0.0,Sxy=0.0,Sx2=0.0,Syy=0.0,Sxx=0.0,S=0.0,D,A,B,S2,S3,errA,errB,R,SumX2=0.0,SumY2=0,SumTot=0.0,Mx,My,chi2=0.0;
	int i=0,j=0;
	FILE *fp;
	fp=fopen("mnmqdrt.dat","r");
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
