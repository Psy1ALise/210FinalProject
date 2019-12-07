#include "project.h"

int main(void){
	openDisplay();
	
	printf("The pi will work like a gyroscope\n");
	printf("The block will show different colors at different positions.\n");
	
	displayBlock(0,0);
	sleep(1);
	displayBlock(1,1);
	sleep(1);
	displayBlock(2,2);
	sleep(1);
	displayBlock(3,3);
	sleep(1);
	displayBlock(4,4);
	sleep(1);
	displayBlock(5,5);
	sleep(1);
	displayBlock(6,6);
	sleep(1);
	displayBlock(7,7);
	sleep(1);

	closeDisplay();
	return 0;
}
