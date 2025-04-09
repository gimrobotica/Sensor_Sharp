#include "SharpSensor.hpp"

const int sensorEsquerda = A0;
const int sensorDireita  = A1;

void setup() {
  Serial.begin(9600);
  pinMode(sensorEsquerda, INPUT);
  pinMode(sensorDireita, INPUT);
}

void loop() {
  // Lê os sensores
  SharpResult leituraEsq = lerSharp(sensorEsquerda, 20.0);
  SharpResult leituraDir = lerSharp(sensorDireita, 25.0);

  // Exibe os dados no serial monitor
  Serial.print("[ESQ] Distância: ");
  Serial.print(leituraEsq.distancia_cm);
  Serial.print(" cm | Objeto: ");
  Serial.print(leituraEsq.objeto_detectado ? "SIM" : "NÃO");

  Serial.print("  ||  ");

  Serial.print("[DIR] Distância: ");
  Serial.print(leituraDir.distancia_cm);
  Serial.print(" cm | Objeto: ");
  Serial.println(leituraDir.objeto_detectado ? "SIM" : "NÃO");

  delay(200);
}
