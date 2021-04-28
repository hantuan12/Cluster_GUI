#include "menu_options.h"
#include <stdint.h>

void display_main_menu(void){
	printf("--------------------------------------------------------\n");
	printf("\t Can Data Emulation - HMI Test Client \n\n");
    printf("-------------------------Main Menu----------------------\n");
    printf("\t a) TURN LEFT \n");
    printf("\t b) LOW BEAM \n");
    printf("\t c) HANDBRAKE \n");
    printf("\t d) CHECK ENGINE \n");
    printf("\t e) AIRBAG \n");
    printf("\t f) KEY STATUS \n");
    printf("\t g) PARKING BRAKE \n");
    printf("\t h) LOW BATTERY \n");
    printf("\t i) TURN RIGHT \n");
    printf("\t j) HIGH BEAM \n");
    printf("\t k) OIL \n");
    printf("\t l) SEATBELT \n");
    printf("\t m) ABS BREAK \n");
    printf("\t n) DOOR WANING LIGHT \n");
    printf("\t o) EXTERIOR LIGHT DEFAULT \n");
    printf("\t p) HAZARD WARINING LIGHT \n");
    printf("\t q) TIREPRESURE_1 \n");
    printf("\t r) TIREPRESURE_2 \n");
    printf("\t s) TIREPRESURE_3 \n");
    printf("\t t) TIREPRESURE_4 \n");
    printf("\t 1) GEAR \n");
    printf("\t 2) MOTOR TEMPERATURE \n");
    printf("\t 3) ENV TEMP \n");
    printf("\t 4) SPEED \n");
    printf("\t 5) FUEL \n");
    printf("\t 6) EFFICIENCY \n");
    printf("\t 7) ODOMETER\n");
    printf("\t 8) RPMs \n");
	printf("--------------------------------------------------\n");
    printf("\t 9) Exit \n");
	printf("--------------------------------------------------\n");
	printf("\t Select option to change:");
}
uint8_t display_boolean_sub_menu(void){
	uint8_t new_value;
	char option;
	printf("--------------------------------------------------\n");
	printf("\t Boolean Options \n\n");
	printf("-------------------------Sub-Menu-----------------\n");
	printf("\t 0) OFF \n");
	printf("\t 1) ON \n");
	printf("--------------------------------------------------\n");
	printf("\t Select value:");
	getchar();
	scanf("%c",&option);
	if(option =='0'){
		new_value = OFF;
	}else{
		new_value = ON;
	}
	return new_value;
}
float display_float_sub_menu(void){
	float new_value;
	printf("--------------------------------------------------\n");
	printf("\t Float Options \n\n");
	printf("----------------------Sub-Menu--------------------\n");
	printf("\t Before enter the new value, please check \n");
    printf("\t range values for each option. \n");
	printf("--------------------------------------------------\n");
	printf("\t Enter new value:");
	getchar();
	scanf("%f",&new_value);
	return new_value;
}
int display_int_sub_menu(void){
	int new_value;
	printf("--------------------------------------------------\n");
	printf("\t Integer Options \n\n");
	printf("----------------------Sub-Menu--------------------\n");
	printf("\t Before enter the new value, please check \n");
	printf("\t range values for each option. \n");
	printf("--------------------------------------------------\n");
	printf("\t Enter new value:");
	getchar();
	scanf("%i",&new_value);
	return new_value;
}
void change_option_value(char option){
	uint8_t boolean_value;
	float float_value;
	int int_value;
	switch(option){
        case'a':
			boolean_value = display_boolean_sub_menu();
			getchar();
			write_uint8_value(option, boolean_value);
			break;
        case'b':
			boolean_value = display_boolean_sub_menu();
			getchar();
			write_uint8_value(option, boolean_value);
			break;
        case'c':
			boolean_value = display_boolean_sub_menu();
			getchar();
			write_uint8_value(option, boolean_value);
			break;
        case'd':
			boolean_value = display_boolean_sub_menu();
			getchar();
			write_uint8_value(option, boolean_value);
			break;
        case'e':
			boolean_value = display_boolean_sub_menu();
			getchar();
			write_uint8_value(option, boolean_value);
			break;
        case'f':
			boolean_value = display_boolean_sub_menu();
			getchar();
			write_uint8_value(option, boolean_value);
			break;
        case'g':
			boolean_value = display_boolean_sub_menu();
			getchar();
			write_uint8_value(option, boolean_value);
			break;
        case'h':
            boolean_value = display_boolean_sub_menu();
            getchar();
            write_uint8_value(option, boolean_value);
            break;
        case'i':
            boolean_value = display_boolean_sub_menu();
            getchar();
            write_uint8_value(option, boolean_value);
            break;
        case'j':
            boolean_value = display_boolean_sub_menu();
            getchar();
            write_uint8_value(option, boolean_value);
            break;
        case'k':
            boolean_value = display_boolean_sub_menu();
            getchar();
            write_uint8_value(option, boolean_value);
            break;
        case'l':
            boolean_value = display_boolean_sub_menu();
            getchar();
            write_uint8_value(option, boolean_value);
            break;
        case'm':
            boolean_value = display_boolean_sub_menu();
            getchar();
            write_uint8_value(option, boolean_value);
            break;
        case'n':
            boolean_value = display_boolean_sub_menu();
            getchar();
            write_uint8_value(option, boolean_value);
            break;
        case'o':
            boolean_value = display_boolean_sub_menu();
            getchar();
            write_uint8_value(option, boolean_value);
            break;
        case'p':
            boolean_value = display_boolean_sub_menu();
            getchar();
            write_uint8_value(option, boolean_value);
            break;    
        case'q':
            int_value = display_int_sub_menu();
            getchar();
            write_int_value(option, int_value);
            break;
        case'r':
            int_value = display_int_sub_menu();
            getchar();
            write_int_value(option, int_value);
            break;
        case's':
            int_value = display_int_sub_menu();
            getchar();
            write_int_value(option, int_value);
            break;
        case't':
            int_value = display_int_sub_menu();
            getchar();
            write_int_value(option, int_value);
            break;
        case'1':
            int_value = display_int_sub_menu();
            getchar();
            write_int_value(option, int_value);
            break;
        case'2':
            float_value = display_float_sub_menu();
            getchar();
            write_float_value(option, float_value);
            break;
        case'3':
            float_value = display_float_sub_menu();
            getchar();
            write_float_value(option, float_value);
            break;
        case'4':
            float_value = display_float_sub_menu();
            getchar();
            write_float_value(option, float_value);
            break;
        case'5':
            float_value = display_float_sub_menu();
            getchar();
            write_float_value(option, float_value);
            break;
        case'6':
            float_value = display_float_sub_menu();
            getchar();
            write_float_value(option, float_value);
            break;
        case'7':
            int_value = display_int_sub_menu();
            getchar();
            write_int_value(option, int_value);
            break;
        case'8':
            int_value = display_int_sub_menu();
            getchar();
            write_int_value(option, int_value);
            break;
        default:
            break;
	}
}
