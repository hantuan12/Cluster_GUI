#ifndef HMI_SHARED_MEMORY_H
#define HMI_SHARED_MEMORY_H

#include <stdint.h>

//TYPE
typedef struct{
    float temp;
    float env_temp;
    float speed;
    float fuel;
    float efficiency;
    uint32_t odometer;
    uint16_t rpms;
    uint8_t tire_pressure_1;
    uint8_t tire_pressure_2;
    uint8_t tire_pressure_3;
    uint8_t tire_pressure_4;
    uint8_t gear;
    uint8_t left_narrow;
    uint8_t low_beam;
    uint8_t hand_brake;
    uint8_t check_engine;
    uint8_t airbag;
    uint8_t key_status;
    uint8_t parking_brake;
    uint8_t low_battery;
    uint8_t right_narrow;
    uint8_t high_beam;
    uint8_t oil;
    uint8_t seat_belt;
    uint8_t abs_brake;
    uint8_t door_warning;
    uint8_t exterior_light_fault;
    uint8_t hazard_lights;
} tshared_memory;

// FUNCTION PROTOTYPES
uint8_t hmi_init_shared_memory(void);
void hmi_deinit_shared_memory(void);
uint8_t hmi_compare_data(tshared_memory* valid_data);
void hmi_copy_data(tshared_memory* valid_data);

#endif
