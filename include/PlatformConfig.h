#ifndef PLATFORM_CONFIG_H_
#define PLATFORM_CONFIG_H_

#define CPP_MODE
// #define ARDUINO_MODE
// #define CUSTOM_MODE

#if defined(CPP_MODE)

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#elif defined(ARDUINO_MODE)

#define MAX(a, b) max(a, b)
#define MIN(a, b) min(a, b)

#elif defined(CUSTOM_MODE)

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#else
    #error "You must define one of the following: CPP_MODE, ARDUINO_MODE, CUSTOM_MODE"
#endif

#endif // PLATFORM_CONFIG_H_