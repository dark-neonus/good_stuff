#ifndef LOGGING_H_
#define LOGGING_H_

#include "PlatformConfig.h"


#if defined(CPP_MODE)

#include <iostream>
#include <stdexcept>

#define PRINT(msg) std::cout << msg;
#define PRINTLN(msg) std::cout << msg << std::endl;
#define LOG(msg) std::cout << "LOG: " << msg << std::endl;
#define WARNING(msg) std::cout << "WARNING: " << msg << std::endl;
#define ERROR(msg) std::cout << "ERROR: " << msg << std::endl;
#define THROW_EXCEPTION(msg) throw std::runtime_error(msg);

#elif defined(ARDUINO_MODE)

#include <Arduino.h>

#define PRINT(msg) Serial.print(msg);
#define PRINTLN(msg) Serial.println(msg);
#define LOG(msg) Serial.print("LOG: "); Serial.println(msg);
#define WARNING(msg) Serial.print("WARNING: "); Serial.println(msg);
#define ERROR(msg) Serial.print("ERROR: "); Serial.println(msg);
#define THROW_EXCEPTION(msg) Serial.println("EXCEPTION: "); Serial.println(msg); while(1);

#elif defined(CUSTOM_MODE)

#define PRINT(msg)
#define PRINTLN(msg)
#define LOG(msg)
#define WARNING(msg)
#define ERROR(msg)
#define THROW_EXCEPTION(msg)

#endif


#endif // LOGGING_H_