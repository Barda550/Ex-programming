//progetto incrocio semaforo a 2 strade -Giacomo Bardasi Andrea Grieco- anno 2 corso di elettronica marzo giugno 2023

// link schema progetto: https://www.tinkercad.com/things/e3faqglVoS2-grand-blad-crift/editel?sharecode=loomBVXd5k5x81Hi4meS02QR3W81zJYo0OqXTRdL7ik

//dichiarazione variabili per la prima coppia di semafori
int LedRosso=A0;
int LedVerde=A2;
int LedGiallo=A1;
int cont=0;             //contatore per la prima coppia
int previousMillis;
int currentMillis=0;
int intRosso=6000;
int intVerde=4000;
int intGiallo=2000;

//dichiarazione variabili per la seconda coppia di semafori
int LedRosso2=A5;
int LedVerde2=A3;
int LedGiallo2=A4;
int cont2=0;          //contatore per la seconda coppia
int intRosso2=6000;
int intVerde2=4000;
int intGiallo2=2000;
int currentMillis2=0;
int previousMillis2;
char var;             //variabile per la scelta della modalità


void setup() {
//inizializzazione porte e output dei led
  Serial.begin(9600) ;
    while (!Serial) ;
  Serial.println("START") ;
  
  pinMode(LedRosso, OUTPUT);
  //Serial.println(LedRosso, HIGH);
  pinMode(LedGiallo, OUTPUT);
  //Serial.println(LedGiallo, HIGH);
  pinMode(LedVerde, OUTPUT);
  //Serial.println(LedVerde, HIGH);
  pinMode(LedRosso2, OUTPUT);
  pinMode(LedGiallo2, OUTPUT);
  pinMode(LedVerde2, OUTPUT);
}

void loop() {  
//accensione led modalità notte il giallo lampeggia a intermittenza di 1 secondo
var=Serial.read();
if(var=='n') {
  digitalWrite(LedVerde, LOW);
  digitalWrite(LedRosso, LOW);
  digitalWrite(LedRosso2, LOW);
  digitalWrite(LedVerde2, LOW);
  unsigned long t = millis();
  int b = 1 ;
  //ciclo scelta modalità
  do {
      if (millis() - t >= 1000) {
        digitalWrite(LedGiallo, b & 1);
        digitalWrite(LedGiallo2, b & 1);
        Serial.println("Notte: Giallo intermittente");
        b++;
        t = millis() ;
      }
    //Serial.println("Continuare modalita' notturna (n/g)");
    var = Serial.read();
    do {
      var = Serial.read() ;
    } while (var == 'n' || var == '\r') ;
  }
  while(var == 'n' || var == -1);
}

//modalità diurna con l'impego di una selezione semplice
else {
currentMillis=millis();

//prima coppia di semafori "coppia 1"
if(cont==0){
    digitalWrite(LedRosso, HIGH); 
    digitalWrite(LedGiallo, LOW);
    digitalWrite(LedVerde, LOW);
    cont+=1;
    previousMillis += intRosso;
    Serial.println("Coppia 1: Rosso");
    //Serial.println(cont);
    
  }
  else {
      if(cont == 1 && (previousMillis - currentMillis) == 0){
          digitalWrite(LedRosso, LOW);
          digitalWrite(LedVerde, HIGH);
          cont+=1;
          previousMillis += intVerde;
        Serial.println("Coppia 1: Rosso -> Verde");
      }
        else if(cont == 2 && previousMillis - currentMillis == 0){
          digitalWrite(LedVerde, LOW);
          digitalWrite(LedGiallo, HIGH);
          cont+=1;
          previousMillis += intGiallo;
          Serial.println("Coppia 1: Verde -> Giallo");
      }
        else if(cont == 3 && previousMillis - currentMillis == 0){ 
          digitalWrite(LedGiallo, LOW);
          digitalWrite(LedRosso, HIGH);
          cont = 1;
          previousMillis += intRosso;
          Serial.println("Coppia 1: Giallo -> Rosso");
      }
  }
  currentMillis2=millis();
  //seconda coppia di semafori "coppia 2"
if(cont2==0){
    
    digitalWrite(LedRosso2, LOW); 
    digitalWrite(LedGiallo2, LOW);
    digitalWrite(LedVerde2, HIGH);
    cont2+=1;
    previousMillis2 += intVerde2;
    Serial.println("Coppia 2: Verde");
    //Serial.println(cont2);
    
  }
  else {
      if(cont2 == 1 && (previousMillis2 - currentMillis2) == 0){
          digitalWrite(LedVerde2, LOW);
          digitalWrite(LedGiallo2, HIGH);
          cont2+=1;
          previousMillis2 += intGiallo2;
        Serial.println("Coppia 2: Verde -> Giallo");
      }
        else if(cont2 == 2 && previousMillis2 - currentMillis2 == 0){
          digitalWrite(LedGiallo2, LOW);
          digitalWrite(LedRosso2, HIGH);
          cont2+=1;
          previousMillis2 += intRosso2;
          Serial.println("Coppia 2: Giallo -> Rosso");

      }
        else if(cont2 == 3 && previousMillis2 - currentMillis2 == 0){ 
          digitalWrite(LedRosso2, LOW);
          digitalWrite(LedVerde2, HIGH);
          cont2 = 1;
          previousMillis2 += intVerde2;
          Serial.println("Coppia 2: ROsso -> Verde");
      }
  }
  }
}
