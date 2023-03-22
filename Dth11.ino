#include "DHT.h"

#define DHTPIN 2

#define DHTTYPE DHT11
const int Temperatura = 2;

DHT dht(DHTPIN, DHTTYPE);
int valorTemperatura;

void setup() {
  Serial.begin (9600);
  Serial.println("DHTxx test!");

  dht.begin();
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();

  float t = dht.readTemperature ();

  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float hif = dht.computeHeatIndex (f, h);

  float hic = dht.computeHeatIndex (t, h, false);

  Serial.print ("Humidity:  ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature:  ");
  Serial.print(t);
  Serial.print("  *C  ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index:  ");
  Serial.print(hic);
  Serial.print("  *C  ");
  Serial.print(hif);
  Serial.println("*F ");
   // Lee el valor del potenciómetro y lo envía a Processing a través del puerto serie
  valorTemperatura = analogRead(Temperatura);
  Serial.println(valorTemperatura);
  delay(50); // Pequeña pausa para evitar una transmisión muy rápida de datos por el puerto serie
}