#include <QObject>
#include <QQmlContext>
#include <QtQuick/QQuickView>
#include "qtquick2applicationviewer.h"
#include <time.h>
#include "hmi_dashboard.h"

/* LOCAL DEFINES */
#define ENABLED 1
#define DISABLED 0.0

void hmi_state_shutdown_event(QtQuick2ApplicationViewer *hmi_dashboard){
    // Set values to Dashboard screen
    hmi_dashboard->rootContext()->setContextProperty("env_temp",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("odometer",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("low_battery",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("temp",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("speed",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("fuel",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("efficiency",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("rpms",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("tire_pressure_1",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("tire_pressure_2",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("tire_pressure_3",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("tire_pressure_4",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("gear",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("left_narrow",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("low_beam",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("hand_brake",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("check_engine",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("airbag",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("key_status",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("parking_brake",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("right_narrow",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("high_beam",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("oil",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("seat_belt",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("abs_brake",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("door_warning",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("exterior_light_fault",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("hazard_lights",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("shutdown",ENABLED);
}

void hmi_state_animation_event(QtQuick2ApplicationViewer *hmi_dashboard){
    // Local Counters
    static uint8_t ctr =0;
    static uint8_t flag =0;
    // Set values to Dashboard screen
    hmi_dashboard->rootContext()->setContextProperty("env_temp",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("efficiency",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("odometer",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("tire_pressure_1",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("tire_pressure_2",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("tire_pressure_3",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("tire_pressure_4",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("gear",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("left_narrow",ENABLED);
    hmi_dashboard->rootContext()->setContextProperty("low_beam",ENABLED);
    hmi_dashboard->rootContext()->setContextProperty("hand_brake",ENABLED);
    hmi_dashboard->rootContext()->setContextProperty("check_engine",ENABLED);
    hmi_dashboard->rootContext()->setContextProperty("airbag",ENABLED);
    hmi_dashboard->rootContext()->setContextProperty("key_status",ENABLED);
    hmi_dashboard->rootContext()->setContextProperty("parking_brake",ENABLED);
    hmi_dashboard->rootContext()->setContextProperty("low_battery",ENABLED);
    hmi_dashboard->rootContext()->setContextProperty("right_narrow",ENABLED);
    hmi_dashboard->rootContext()->setContextProperty("high_beam",ENABLED);
    hmi_dashboard->rootContext()->setContextProperty("oil",ENABLED);
    hmi_dashboard->rootContext()->setContextProperty("seat_belt",ENABLED);
    hmi_dashboard->rootContext()->setContextProperty("abs_brake",ENABLED);
    hmi_dashboard->rootContext()->setContextProperty("door_warning",ENABLED);
    hmi_dashboard->rootContext()->setContextProperty("exterior_light_fault",ENABLED);
    hmi_dashboard->rootContext()->setContextProperty("hazard_lights",ENABLED);
    hmi_dashboard->rootContext()->setContextProperty("shutdown",DISABLED);
    // Set the values for animation
    if(ctr<240 && flag ==0){
        hmi_dashboard->rootContext()->setContextProperty("speed",ctr);
        hmi_dashboard->rootContext()->setContextProperty("rpms",ctr*37.5);
        hmi_dashboard->rootContext()->setContextProperty("fuel",ctr/4);
        hmi_dashboard->rootContext()->setContextProperty("temp",ctr/1.6);
        ctr+=10;
    }else if(ctr ==240 && flag ==0){
        flag =1;
        hmi_dashboard->rootContext()->setContextProperty("speed",ctr);
        hmi_dashboard->rootContext()->setContextProperty("rpms",ctr*37.5);
        hmi_dashboard->rootContext()->setContextProperty("fuel",ctr/4);
        hmi_dashboard->rootContext()->setContextProperty("temp",ctr/1.6);
        return;
    }
    if(ctr>0 && flag ==1){
        hmi_dashboard->rootContext()->setContextProperty("speed",ctr);
        hmi_dashboard->rootContext()->setContextProperty("rpms",ctr*37.5);
        hmi_dashboard->rootContext()->setContextProperty("fuel",ctr/4);
        hmi_dashboard->rootContext()->setContextProperty("temp",ctr/1.6);
        ctr-=10;
    }else if(ctr ==0 && flag ==1){
        flag =0;
        hmi_dashboard->rootContext()->setContextProperty("speed",ctr);
        hmi_dashboard->rootContext()->setContextProperty("rpms",ctr*37.5);
        hmi_dashboard->rootContext()->setContextProperty("fuel",ctr/4);
        hmi_dashboard->rootContext()->setContextProperty("temp",ctr/1.6);
    }
}

void hmi_state_default_event(QtQuick2ApplicationViewer *hmi_dashboard){
    //return;
    // Set values to Dashboard screen
    hmi_dashboard->rootContext()->setContextProperty("temp",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("env_temp",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("speed",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("fuel",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("efficiency",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("odometer",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("rpms",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("tire_pressure_1",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("tire_pressure_2",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("tire_pressure_3",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("tire_pressure_4",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("gear",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("left_narrow",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("low_beam",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("hand_brake",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("check_engine",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("airbag",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("key_status",ENABLED);
    hmi_dashboard->rootContext()->setContextProperty("parking_brake",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("right_narrow",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("high_beam",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("oil",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("seat_belt",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("abs_brake",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("door_warning",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("exterior_light_fault",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("hazard_lights",DISABLED);
    hmi_dashboard->rootContext()->setContextProperty("shutdown",DISABLED);
}

void hmi_state_runtime_event(tshared_memory *data, QtQuick2ApplicationViewer *hmi_dashboard){
    // Set values to Dashboard screen
    hmi_dashboard->rootContext()->setContextProperty("temp",data->temp);
    hmi_dashboard->rootContext()->setContextProperty("env_temp",data->env_temp);
    hmi_dashboard->rootContext()->setContextProperty("speed",data->speed);
    hmi_dashboard->rootContext()->setContextProperty("fuel",data->fuel);
    hmi_dashboard->rootContext()->setContextProperty("efficiency",data->efficiency);
    hmi_dashboard->rootContext()->setContextProperty("odometer",data->odometer);
    hmi_dashboard->rootContext()->setContextProperty("rpms",data->rpms);
    hmi_dashboard->rootContext()->setContextProperty("tire_pressure_1",data->tire_pressure_1);
    hmi_dashboard->rootContext()->setContextProperty("tire_pressure_2",data->tire_pressure_2);
    hmi_dashboard->rootContext()->setContextProperty("tire_pressure_3",data->tire_pressure_3);
    hmi_dashboard->rootContext()->setContextProperty("tire_pressure_4",data->tire_pressure_4);
    hmi_dashboard->rootContext()->setContextProperty("gear",data->gear);
    hmi_dashboard->rootContext()->setContextProperty("left_narrow",data->left_narrow);
    hmi_dashboard->rootContext()->setContextProperty("low_beam",data->low_beam);
    hmi_dashboard->rootContext()->setContextProperty("hand_brake",data->hand_brake);
    hmi_dashboard->rootContext()->setContextProperty("check_engine",data->check_engine);
    hmi_dashboard->rootContext()->setContextProperty("airbag",data->airbag);
    hmi_dashboard->rootContext()->setContextProperty("key_status",data->key_status);
    hmi_dashboard->rootContext()->setContextProperty("parking_brake",data->parking_brake);
    hmi_dashboard->rootContext()->setContextProperty("low_battery",data->low_battery);
    hmi_dashboard->rootContext()->setContextProperty("right_narrow",data->right_narrow);
    hmi_dashboard->rootContext()->setContextProperty("high_beam",data->high_beam);
    hmi_dashboard->rootContext()->setContextProperty("oil",data->oil);
    hmi_dashboard->rootContext()->setContextProperty("seat_belt",data->seat_belt);
    hmi_dashboard->rootContext()->setContextProperty("abs_brake",data->abs_brake);
    hmi_dashboard->rootContext()->setContextProperty("door_warning",data->door_warning);
    hmi_dashboard->rootContext()->setContextProperty("exterior_light_fault",data->exterior_light_fault);
    hmi_dashboard->rootContext()->setContextProperty("hazard_lights",data->hazard_lights);
    hmi_dashboard->rootContext()->setContextProperty("shutdown",DISABLED);
}
