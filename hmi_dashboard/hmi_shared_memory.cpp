#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "hmi_shared_memory.h"
#include "hmi_dashboard.h"

tshared_memory Can_Data;
tshared_memory *ptr_Can_Data;
key_t Key;
int Id_Shared_Memory;
int Id_Semaphore;
struct sembuf Operation;

// LOCAL DEFINES
#define FILEKEY "/bin/ls"
#define KEY 10
#define BYTES sizeof(Can_Data)
#define SEMAPHORES 1

// FUNCTION DEFINITIONS
uint8_t hmi_init_shared_memory(void){
    //Get Key
    Key = ftok (FILEKEY, KEY);
    if(Key ==-1)
        return 1;

    // Get Semaphore Id
    Id_Semaphore = semget(Key, SEMAPHORES,0777| IPC_CREAT);
    if(Id_Semaphore ==-1)
        return 1;

    // Get Shared Memory Id
    Id_Shared_Memory = shmget (Key, BYTES,0777);
    if(Id_Shared_Memory ==-1)
        return 1;

    // Get pointer to Shared Memory
    ptr_Can_Data =(tshared_memory *)shmat (Id_Shared_Memory,(char*)0,0);
    if(ptr_Can_Data ==NULL)
        return 1;

    // Init semaphore values
    Operation.sem_num =0;
    Operation.sem_flg =0;
    Operation.sem_op =1;
    return 0;
}

void hmi_deinit_shared_memory(void){
    // Free the shared memory
    shmdt ((char*)ptr_Can_Data);
    return;
}

uint8_t hmi_compare_data(tshared_memory* valid_data){
    // Local variables
    uint8_t cmp_res;
    // Change Semaphore to RED
    Operation.sem_op =-1;
    // Set the Semaphore to RED
    semop (Id_Semaphore,&Operation,1);
    if(memcmp(ptr_Can_Data, valid_data,sizeof(tshared_memory))==0){
        cmp_res =0;
    }else{
        cmp_res =1;
    }
    // Change Semaphore to GREEN
    Operation.sem_op =1;
    // Set the Semaphore to GREEN
    semop (Id_Semaphore,&Operation,1);
    return cmp_res;
}

void hmi_copy_data(tshared_memory* valid_data){
    //Change Semaphore to RED
    Operation.sem_op =-1;
    // Set the Semaphore to RED
    semop (Id_Semaphore,&Operation,1);
    // update Can values - shared memory values to valid data struct
    memcpy(valid_data, ptr_Can_Data,sizeof(tshared_memory));
    // Change Semaphore to GREEN
    Operation.sem_op =1;
    // Set the Semaphore to GREEN
    semop (Id_Semaphore,&Operation,1);
}
