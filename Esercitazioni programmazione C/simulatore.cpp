#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int lancio(int Nr,int colpo);

main()
{
	float classi=70,ch=15,g=3,a,x1,x2,m,q;	//lunghezza della classe,altezza salto e angolo
	int N,Nr=0,y1=3*ch+2*g,y2=2*ch+2*g,esten1,esten2,cella=1,colpo;
	char base;
	srand(time(NULL));
	printf("\n         Simulazione raggi cosmici        \n\n");
	do
	{
		printf("Inserire numero di raggi da simulare (maggiore di 100)");
		scanf("%d",&N);
	}
	while(N<=100);
	for(int i=0;i<N;i++)	//rilevamento dei raggi
	{
		colpo=0;
		do
		{
			a=-90+((float)rand()/RAND_MAX)*180;	//generazione angoli (seguendo la funzione cos^2(a))
		}
		while(((double)rand()/RAND_MAX)*1>pow(cos(a),2));
		if(a>0)			//pendenza della retta
			m=tan(90-a);  //Incidenza sul primo layer
		else
			m=tan(-90-a);
		x1=((float)rand()/RAND_MAX)*((classi+g)*27-g);
		q=y1-m*x1;		//calcolo intercetta
		for(int conta=0;conta<3;conta++)	//ripetizione del rilievo per 3 layer
		{
			esten1=0;
			esten2=70;
			base='X';
			x1=(y1-q)/m;		//punto di incidenza sulla coordinata y1
			x2=(y2-q)/m;		//punto di incidenza sulla coordinata y2
			if(colpo<2)
			{				//calcolo delle parti colpite dal raggio
				while(base=='X')
				{
					if(x1>esten1 && x1<esten2)
					{
						if(x2>esten2 && x2<esten2)
							base='B';
						else base='U';
					}
					else
						{
							if(x2>esten1 && x2<esten2)
								base='L';
							else
								if(cella!=27 && (x1>esten2+g))
									base='N';
						}
					cella++;
					esten1+=(classi+g);
					esten2=esten1+classi;	
				}
		}
		switch(base)
			{
				case 'B':
							colpo++;
							Nr=lancio(Nr,colpo);
							break;
				case 'U':
							if(sqrt(pow(x1-esten1,2)+pow(y1-(m*esten1+q),2))>0.10*(y2-y1))
							{
								colpo++;
								Nr=lancio(Nr,colpo);
								break;
							}
				case 'L':
							if(sqrt(pow(x2-esten2,2)+pow(y1-(m*esten2+q)-y2,2))>0.10*(y2-y1))
							{
								colpo++;
								Nr=lancio(Nr,colpo);
								break;
							}		
			}
		y1-=(ch+g);
		y2-=(ch+g);
		}
	}
	printf("\nIl numero di raggi rilevati vale: %d (%.2f%%)\n\n",Nr,((float)Nr/float(N))*100);
}
///////////////////////////////////////////////
//funzione per il calcolo dei punti colpiti
int lancio(int Nr,int colpo)
{
	if(colpo==2)
		if(rand()%101>10)
			Nr++;
	return Nr;
}
