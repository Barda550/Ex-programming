#include<stdio.h>												/*devstandardcalcolo*/
#include<math.h>
#include<stdlib.h>												/*per poter usare la funzione radice quadrata*/

int DevStD(float *vettore, int dimensione, float &std)		/*funzione di calcolo, parametro 'std' passato per referenza*/
{
	float M1=0, M2=0;
	for(int i=0; i<dimensione; i++)
	{	
		M1=M1+vettore[i];
		M2=M2+vettore[i]*vettore[i];
	}	
	M1=M1/dimensione;
	M2=M2/dimensione;
	std=sqrt(M2-M1*M1);
	return std;										/*passo al main il valore di std dove sta la dev. standard*/
}

main()											/*calcolo deviazione standard di una serie di numeri*/
{
	int dimensione;
	float *vettore;
	float std;
	printf("Inserire la quantita' di numeri di cui si vuole la dev.standard \n");
	scanf("%d",&dimensione);
	vettore=(float*)malloc(sizeof(float)*dimensione);
	if(!vettore)
		return 0;									/*controllo l'inizializzazione del vettore*/
	for(int i=0;i<dimensione;i++)
	{	
		printf("Inserisci il dato attuale \n");
		scanf("%f",&vettore[i]);
	}
	DevStD(vettore,dimensione,std);								/*passo le variabili alla funzione*/
	printf("La deviazione standard dei dati inseriti vale: %f",std);
	free(vettore);											/*elimino il vettore*/
}
