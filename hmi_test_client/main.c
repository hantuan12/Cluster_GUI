#include <stdio.h>
#include <stdlib.h>
#include "menu_options.h"
#include "shared_memory.h"
int main(void)
{
	char menu_option =' ';
	init_shared_memory();
    while(menu_option !='9'){
        system("clear");
        display_main_menu();
        menu_option = getchar();
        change_option_value(menu_option);
	}
	deinit_shared_memory();
    return 0;
}
