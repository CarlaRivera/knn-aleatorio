
#include"datos_entrenamiento.h"
#include"datos_test.h"

int sw[3]={7,6,5}; //pines de entrada
int col=0;
int row=0;
float dist;
float dm1=100;
float dm2=200;
float dm3=300;


void setup() {
  
Serial.begin(9600); //inicializar el puerto serial

}

void loop() {
 //para activar los métodos según las combinaciones
 
if(digitalRead(sw[0])==LOW && digitalRead(sw[1])==LOW && digitalRead(sw[2])==HIGH)
 knn1();
if(digitalRead(sw[0])==LOW && digitalRead(sw[1])==HIGH && digitalRead(sw[2])==LOW)
 knn3();

}

void knn1(){ //método para calcular knn con k=1
    for(;row<120;row++){ //contador de filas for lento
     //calculo de distancia
         dist=sqrt(pow((matriz[row][0]-prueba[15][0]),2) +  
                   pow((matriz[row][1]-prueba[15][1]),2) +
                   pow((matriz[row][2]-prueba[15][2]),2) +
                   pow((matriz[row][3]-prueba[15][3]),2));
                        
                   if(dist<dm1)  // comparo el dato siguiente con el actual
                   {
                    dm1=dist; //guardo el valor actual
                   Serial.println(matriz[row][4]); //imprimo dato de etiqueta
                   }
  }

}

void knn3(){ //método para calcular knn con k=3
float d1;       
float d2;     
float d3;      
float dist_menor=100;    
float dist_menor1=200;  
float dist_menor2=150;  
float r1;        
float r2;     
float r3;     
int i;
int row=0;

  for(;row<120;row++) //contador de filas for lento
  {
    //calcula distancias
          d1= sqrt(pow((matriz[row][0]-prueba[row][0]),2) +  
                   pow((matriz[row][1]-prueba[row][1]),2) +
                   pow((matriz[row][2]-prueba[row][2]),2) +
                   pow((matriz[row][3]-prueba[row][3]),2));
         if(d1<dist_menor) //Comparando el dato siguiente con el actual
         {  
        dist_menor=d1;   //guardo el valor actual
        r1=matriz[row][4];   //intercambio posicion de datos
        r1=r1;    
        }
                   
          d2=sqrt(pow((matriz[row][0]-prueba[row][0]),2) +  
                   pow((matriz[row][1]-prueba[row][1]),2) +
                   pow((matriz[row][2]-prueba[row][2]),2) +
                   pow((matriz[row][3]-prueba[row][3]),2));
        if(d2<dist_menor1&&d2>dist_menor)
        {  
        dist_menor1=d2;  
        r2=matriz[row][4]; 
        r2=r2;  
        }
          d3=sqrt(pow((matriz[row][0]-prueba[row][0]),2) +  
                   pow((matriz[row][1]-prueba[row][1]),2) +
                   pow((matriz[row][2]-prueba[row][2]),2) +
                   pow((matriz[row][3]-prueba[row][3]),2));
   
        if(d3<dist_menor2&&d3>dist_menor1)
        { 
        d3=d3; 
        r3=matriz[row][4]; 
        r3=r3;     
        }
   
    }
       Serial.print("Grupo: ");
 Serial.println(r1);
 Serial.println(dist_menor);
 delay(1000);
 Serial.print("Grupo: ");
 Serial.println(r2);
 Serial.println(dist_menor1);
 delay(1000);
 Serial.print("Grupo: ");
 Serial.println(r3);
 Serial.println(dist_menor2);
delay(1000);
 
}

void knn5(){
  
  
  
  }
