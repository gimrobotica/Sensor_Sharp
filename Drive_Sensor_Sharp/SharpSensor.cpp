#include "SharpSensor.hpp"
#include <Arduino.h>

SharpResult lerSharp(int pinoAnalogico, float limite_cm) {
  int leitura = analogRead(pinoAnalogico);
  float volts = leitura * (5.0 / 1023.0);

  // Fórmula aproximada para GP2Y0A41SK0F
  float distancia_cm = 13.0 / (volts - 0.2);

  if (distancia_cm < 4 || distancia_cm > 30) {
    distancia_cm = -1;
  }

  bool detectado = (distancia_cm > 0 && distancia_cm <= limite_cm);

  return { distancia_cm, detectado };
}
