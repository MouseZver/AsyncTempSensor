#include <AsyncTempSensor.h>

// Callback-функция
void onTemperatureReady(int index, float temperature) {
    Serial.print("🌡 Температура от датчика ");
    Serial.print(index);
    Serial.print(": ");
    Serial.println(temperature);
}

// Инициализация датчика
AsyncTempSensor tempSensor(2, onTemperatureReady);

void setup() {
    Serial.begin(9600);
    tempSensor.begin(); // Начать работу
}

void loop() {
    tempSensor.update(1000); // Обновлять каждые 1000 мс
}