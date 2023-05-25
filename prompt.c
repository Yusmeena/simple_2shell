#include "shell.h"

/**
*handleit_signal - this function handle ctrl c
*@look: parse in the line
*/

void handleit_signal(int look)
{
	if (look == SIGINT)
	{
		PRINTF("\n($) ");
	}
}

/**
*show - this funtion output prompt
*/
void show(void)
{
	PRINTF("($) ");
}
