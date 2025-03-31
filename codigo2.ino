#include <AFMotor.h>

AF_DCMotor m1(1);
AF_DCMotor m2(2);
AF_DCMotor m3(3);
AF_DCMotor m4(4); //Declaracion de los 4 motores a utilizar
long mov;

void setup()
{
  Serial.begin(9600); //inicializacion para entrada y salidad de datos a 9600 bits por segundo
  m1.setSpeed(200);
  m2.setSpeed(200);
  m3.setSpeed(200);
  m4.setSpeed(200);
} 
void adel (){         //declaracion movimiento hacia adelante
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
}
void atras()          //declaracion de movimiento hacia atras
{
m1.run(BACKWARD);
m2.run(BACKWARD);
m3.run(BACKWARD);
m4.run(BACKWARD);
}
void der()          //declaracion de movimiento a la derecha
{
m1.run(FORWARD);
m2.run(FORWARD);
m3.run(BACKWARD);
m4.run(BACKWARD);
}
void izq()          //declaracion de movimiento a izquierda
{
m1.run(BACKWARD);
m2.run(BACKWARD);
m3.run(FORWARD);
m4.run(FORWARD);
}

void loop()     //en el lopp hasta momento indeterminado
{
  if (Serial.available() > 0) { // Checa si hay datos disponibles
    mov = Serial.parseInt(); // Leenúmero entero desde el monitor serial
    Serial.print("Movimiento seleccionado: ");
    Serial.println(mov);
  }
switch(mov){    //switch para mandar a llamar la funcionn
    case 1:
    Serial.println("El curiosity rover avanza hacia el frente");
    adel(); //manda a llamar bloque adel
    break;

    case 2:
    Serial.println("El curiosity rover retrocede ");
    atras();  //manda a llamar bloque atras
    break;

    case 3:
    Serial.println("El curiosity rover giraa la derecha");
    der(); //manda a llamar der
    break;

    case 4:
    Serial.println("El curiosity rover gira a la izquierda ");
    izq();    //manda a llamar izq
    break;

    default:
    Serial.println("Valor no reconocido");
    break;
}
}