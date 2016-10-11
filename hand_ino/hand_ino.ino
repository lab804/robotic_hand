// importando as bibliotecas necessarias
#include <Arduino.h>
#include <Servo.h>

void movimentaDedo(Servo &servo);
int fechaMao();

// defino as constantes dos dedoss
const int dedo1 = 5;
const int dedo2 = 6;
const int dedo3 = 9;
const int dedo4 = 10;
const int dedo5 = 11;

// entrada do dado pela serial e a posicao
int input;
int pos = 0;

// Definindo cada servo motor
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

// Inicializacao da placa
void setup()
{
  // Definindo o baundrate anexando os servos e enviando a posicao 0
  Serial.begin(9600);
  servo1.attach(dedo1);
  servo1.write(0);
  servo2.attach(dedo2);
  servo2.write(0);
  servo3.attach(dedo3);
  servo3.write(0);
  servo4.attach(dedo4);
  servo4.write(0);
  servo5.attach(dedo5);
  servo5.write(0);

  // aguarda 100 milseg
  delay(100);
}

void loop()
{

  // se o porta serial estiver disponivel
  if (Serial.available()>0)
  {
    // armazendo o dado vindo pela serial
    int input = Serial.read();
    Serial.println(input);
    // condicionado, caso o dado seja a letra movimenta-se o dedo
    // caso nao seja nenhuma dessas opcoes executo a funcao fechaMao
    switch (input)
    {
      case 'q':
        Serial.println(input);
        movimentaDedo(servo1);
        break;
      case 'w':
        Serial.println(input);
        movimentaDedo(servo2);
        break;
      case 'e':
        Serial.println(input);
        movimentaDedo(servo3);
        break;
      case 'r':
        Serial.println(input);
        movimentaDedo(servo4);
        break;
      case 't':
        Serial.println(input);
        movimentaDedo(servo5);
        break;
      default:
        Serial.println(input);
        fechaMao();
        break;
    }

    Serial.println();
  }
}


// metodo que movimenta o dedo indo da posicao 0 ate 180 graus
void movimentaDedo(Servo &servo)
{
  // abertura do dedo
  for (pos = 0; pos <= 180; pos++)
  {
  servo.write(pos);
  delay(3);
  }
  // fechamento do dedo
  for (pos = 180; pos >= 0; pos--)
  {

  servo.write(pos);
    delay(3);
  }
}

// metodo que abre e fecha a mao
int fechaMao()
{

  for (pos = 0; pos <= 180; pos++)
  {
    servo1.write(pos);
    servo2.write(pos);
    servo3.write(pos);
    servo4.write(pos);
    servo5.write(pos);

    delay(5);
  }
  for (pos = 180; pos >= 0; pos--)
  {
    servo1.write(pos);
    servo2.write(pos);
    servo3.write(pos);
    servo4.write(pos);
    servo5.write(pos);
    delay(5);
  }
  return 1;
}
