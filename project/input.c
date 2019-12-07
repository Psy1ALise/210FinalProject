#include "project.h"

int joycode;
pi_joystick_t *joystick = NULL;


void handler(unsigned int code){
	printf("code: %u\n",code);
	if(code == 105){//up
		printf("up");
		joycode = code;
	}else if(code == 103){//right
		printf("right");
		joycode = code;
	}else if(code == 106){//down
		printf("down");
		joycode = code;
	}else if(code == 108){//left
		printf("left");
		joycode = code;
	}else if(code == 28){//push

		joycode = code;
		}
}

void openJoystick(){
	if(joystick == NULL){
		joystick = getJoystickDevice();
	}
}
void closeJoystick(){
	if(joystick){
		freeJoystick(joystick);
		joystick = NULL;
	}
}
void checkJoystick(void (*callback)(unsigned int code), int delay){
	pollJoystick(joystick,callback,delay);
}


int get_joycode(){
	return joycode;
}






