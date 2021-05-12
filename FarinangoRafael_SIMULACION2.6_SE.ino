/*
 *CAPITULO II:PUERTOS DIGITALES - DISPLAYS 
 *CODIGO 6:MANEJO DE DISPLAY 7 SEG MULTIPLEXADOS CON ANODO COMUN Y DECO 7447
 *OBJETIVO:SE REGISTRA LAS VECES QUE SE PRESIONA UN PULSADOR DE 0 A 30 
 *NOMBRE:RAFAEL FARINANGO
 */

const int A=11;
const int B=10;
const int C=9;
const int D=8;
const int btn=7;
const int dis1=12;//pin de activacion de las unidades
const int dis2=13;//pin de activacion de las decenas
int cont=0;
int unidades;
int decenas;
 
void setup() {
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(dis1,OUTPUT);
  pinMode(dis2,OUTPUT);
  pinMode(btn,INPUT);
}

void loop() {
  if(digitalRead(btn)==LOW){
    delay(300);
    if(cont<30)
      cont++;
    else
      cont=0;
    decenas=cont/10;//division modular, solo toma el entero
    unidades=cont-decenas*10;//solo toma las unidades
    }
    digitalWrite(dis1,HIGH);//para activar el display de unidades
    digitalWrite(dis2,LOW);//para desactivar el disp de decenas
    segmentos(decenas);
    delay(300);
    digitalWrite(dis1,LOW);
    digitalWrite(dis2,HIGH);
    segmentos(unidades);
    delay(300);
}

void segmentos(int i){
  switch(i){
          case 0:
            digitalWrite(A,LOW);
            digitalWrite(B,LOW);
            digitalWrite(C,LOW);
            digitalWrite(D,LOW);
          break;
          case 1:
            digitalWrite(A,HIGH);
            digitalWrite(B,LOW);
            digitalWrite(C,LOW);
            digitalWrite(D,LOW);
          break;
          case 2:
            digitalWrite(A,LOW);
            digitalWrite(B,HIGH);
            digitalWrite(C,LOW);
            digitalWrite(D,LOW);
          break;
          case 3:
            digitalWrite(A,HIGH);
            digitalWrite(B,HIGH);
            digitalWrite(C,LOW);
            digitalWrite(D,LOW);
          break;
          case 4:
            digitalWrite(A,LOW);
            digitalWrite(B,LOW);
            digitalWrite(C,HIGH);
            digitalWrite(D,LOW);
          break;
          case 5:
            digitalWrite(A,HIGH);
            digitalWrite(B,LOW);
            digitalWrite(C,HIGH);
            digitalWrite(D,LOW);
          break;
          case 6:
            digitalWrite(A,LOW);
            digitalWrite(B,HIGH);
            digitalWrite(C,HIGH);
            digitalWrite(D,LOW);
          break;
          case 7:
            digitalWrite(A,HIGH);
            digitalWrite(B,HIGH);
            digitalWrite(C,HIGH);
            digitalWrite(D,LOW);
          break;
          case 8:
            digitalWrite(A,LOW);
            digitalWrite(B,LOW);
            digitalWrite(C,LOW);
            digitalWrite(D,HIGH);
          break;
          case 9:
            digitalWrite(A,HIGH);
            digitalWrite(B,LOW);
            digitalWrite(C,LOW);
            digitalWrite(D,HIGH);
          break;   
          } 
}
