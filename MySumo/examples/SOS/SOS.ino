#include <MySumo.h>

// Ajusta estos pines según tu conexión
int motorA1 = 4;
int motorA2 = 5;
int motorB1 = 0;
int motorB2 = 2;
int trigPin = 14;
int echoPin = 12;

MySumo robot(motorA1, motorA2, motorB1, motorB2, trigPin, echoPin);

void setup() {
  Serial.begin(9600);
  robot.init();
  Serial.println("Prueba de motores MiniSumo");

  // Motor A hacia adelante
  Serial.println("Motor A adelante");
  robot.setMotors(50, 0);
  delay(2000);

  // Motor A hacia atrás
  Serial.println("Motor A atrás");
  robot.setMotors(-50, 0);
  delay(2000);

  // Motor B hacia adelante
  Serial.println("Motor B adelante");
  robot.setMotors(0, 50);
  delay(2000);

  // Motor B hacia atrás
  Serial.println("Motor B atrás");
  robot.setMotors(0, -50);
  delay(2000);

  // Detener motores
  Serial.println("Motores detenidos");
  robot.setMotors(0, 0);
}

void loop() {
  float distancia = robot.read_distance();
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  delay(500);
}