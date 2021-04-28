#include "hmi_dashboard.h"
#include "hmi_shared_memory.h"
#include "hmi_states_values.h"

// HMI states
HMI_STATES hmi_state;
// Struct for valid data from Shared Memory - Can Protocol
tshared_memory hmi_valid_data;

//LOCAL DEFINES
#define HMI_VALIDATION_CTR 19
#define ENABLED 1
#define DISABLED 0
#define HMI_ANIMATION_CTR_LIMIT 48

// FUNCTION DEFINITIONS
Window::Window(QWindow *parent):
    QQuickView(parent)
        {
            Dashboard = new QtQuick2ApplicationViewer(this);
            // Run shutdown event - Fist event on HMI Dashboard initialization
            hmi_state_shutdown_event(Dashboard);
            // Initial HMI state
            hmi_state = HMI_STATE_SHUTDOWN;
            // Init all hmi_valid_data struct values to 0
            memset(&hmi_valid_data,0,sizeof(hmi_valid_data));
            Dashboard->setMainQmlFile(QStringLiteral("qrc:/main.qml"));
            Dashboard->showExpanded();
           }

void Window::Update_Can_Data()
{
    // Local variables
    uint8_t hmi_shmem_res;
    uint8_t hmi_cmp_data_res;
    static uint8_t hmi_validation_ctr =0;
    static uint8_t hmi_animation_ctr =0;
    hmi_shmem_res = hmi_init_shared_memory();
    if(hmi_shmem_res ==0){
        // Compare valid_data with shared memory
        hmi_cmp_data_res = hmi_compare_data(&hmi_valid_data);
        // Check if at least one value was changed
        if( hmi_cmp_data_res ==0){
                // No value was changed
                hmi_validation_ctr++;
                // Check if a communication error occurs
                if(hmi_validation_ctr > HMI_VALIDATION_CTR && hmi_state !=HMI_STATE_ANIMATION){
                    hmi_state = HMI_STATE_COMUNNICATION_ERROR;
                    hmi_validation_ctr =0;
                }else if(hmi_validation_ctr < HMI_VALIDATION_CTR && hmi_state ==HMI_STATE_ANIMATION){
                // Skip hmi_validation_ctr from HMI Animation
                    hmi_validation_ctr--;
                }
        }else{
            // Copy shared memory values to hmi_valid_data
            hmi_copy_data(&hmi_valid_data);
            hmi_validation_ctr =0;
        }
    }else{
        return;
    }
    // Deinit shared memory
    hmi_deinit_shared_memory();
    //HMI Dashboard states handler
    switch(hmi_state)
    {
        case HMI_STATE_SHUTDOWN:
        {
            if(hmi_valid_data.key_status == DISABLED){
                hmi_state = HMI_STATE_SHUTDOWN;
                hmi_state_shutdown_event(Dashboard);
            }else if(hmi_valid_data.low_battery == ENABLED){
                hmi_state = HMI_STATE_DEFAULT;
                hmi_state_default_event(Dashboard);
                Dashboard->rootContext()->setContextProperty("low_battery", ENABLED);
            }else{
                hmi_state = HMI_STATE_ANIMATION;
                hmi_state_animation_event(Dashboard);
                hmi_animation_ctr++;
            }
            break;
        }
        case HMI_STATE_ANIMATION:
        {
            if(hmi_valid_data.key_status == DISABLED){
                hmi_state = HMI_STATE_SHUTDOWN;
                hmi_state_shutdown_event(Dashboard);
            }else if(hmi_valid_data.low_battery == ENABLED){
                hmi_state = HMI_STATE_DEFAULT;
                hmi_state_default_event(Dashboard);
                Dashboard->rootContext()->setContextProperty("low_battery", ENABLED);
            }else if(hmi_animation_ctr <= HMI_ANIMATION_CTR_LIMIT){
                hmi_state = HMI_STATE_ANIMATION;
                hmi_state_animation_event(Dashboard);
                hmi_animation_ctr++;
            }else{
                hmi_state = HMI_STATE_DEFAULT;
                hmi_animation_ctr =0;
                hmi_state_default_event(Dashboard);
            }
            break;
        }
        case HMI_STATE_DEFAULT:
        {
            if(hmi_valid_data.key_status == DISABLED){
                hmi_state = HMI_STATE_SHUTDOWN;
                hmi_state_shutdown_event(Dashboard);
            }else if(hmi_valid_data.low_battery == ENABLED){
                hmi_state = HMI_STATE_DEFAULT;
                hmi_state_default_event(Dashboard);
                Dashboard->rootContext()->setContextProperty("low_battery", ENABLED);
            }else{
                hmi_state = HMI_STATE_RUNTIME;
                hmi_state_runtime_event(&hmi_valid_data, Dashboard);
            }
            break;
        }
        case HMI_STATE_RUNTIME:
        {
            if(hmi_valid_data.key_status == DISABLED){
                hmi_state = HMI_STATE_SHUTDOWN;
                hmi_state_shutdown_event(Dashboard);
            }else if(hmi_valid_data.low_battery == ENABLED){
                hmi_state = HMI_STATE_DEFAULT;
                hmi_state_default_event(Dashboard);
                Dashboard->rootContext()->setContextProperty("low_battery", ENABLED);
            }else{
                hmi_state = HMI_STATE_RUNTIME;
                hmi_state_runtime_event(&hmi_valid_data, Dashboard);
            }
            break;
        }
        case HMI_STATE_COMUNNICATION_ERROR:
            {
            if(hmi_valid_data.key_status == ENABLED && hmi_cmp_data_res ==1){
                hmi_state = HMI_STATE_DEFAULT;
                hmi_state_default_event(Dashboard);
            }else if(hmi_valid_data.key_status == ENABLED){
                hmi_state = HMI_STATE_COMUNNICATION_ERROR;
                hmi_state_default_event(Dashboard);
            }else{
                hmi_state = HMI_STATE_SHUTDOWN;
                hmi_state_shutdown_event(Dashboard);
            }
            break;
        }
    }
}
