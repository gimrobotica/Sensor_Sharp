#ifndef SHARP_SENSOR_HPP
#define SHARP_SENSOR_HPP

struct SharpResult {
  float distancia_cm;
  bool objeto_detectado;
};

/**
 * Lê um sensor Sharp GP2Y0A41SK0F.
 * @param pinoAnalogico - Pino analógico conectado ao sensor.
 * @param limite_cm - Distância limite para considerar detecção (default = 15 cm).
 * @return SharpResult com distância estimada e flag de detecção.
 */
SharpResult lerSharp(int pinoAnalogico, float limite_cm = 15.0);

#endif
