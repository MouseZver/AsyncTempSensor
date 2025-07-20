#ifndef ASYNC_TEMP_SENSOR_H
#define ASYNC_TEMP_SENSOR_H

#include <Arduino.h>
#include <OneWire.h>

// Тип callback-функции
typedef void (*TempCallback)(int index, float temp);

// Тип для хранения 64-битного адреса датчика (8 байт)
typedef uint8_t DeviceAddress[8];

class AsyncTempSensor {
public:
    static const int MAX_DEVICES = 8;

    AsyncTempSensor(uint8_t pin, TempCallback callback = nullptr);
    void begin();
    void update(unsigned long interval);

    // Включить/выключить отладочный вывод
    void setDebugOutput(bool enabled);

    int getDeviceCount() { return _deviceCount; }

private:
    OneWire _oneWire;
    uint8_t _pin;
    TempCallback _callback = nullptr;

    DeviceAddress _addresses[MAX_DEVICES];
    int _deviceCount = 0;
    float _temperatures[MAX_DEVICES];

    unsigned long _lastConversionTime = 0;
    bool _conversionStarted = false;

    void findDevices();
    void startConversion();
};

#endif