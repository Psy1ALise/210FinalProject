#include "project.h"

int main(void){
	int cnt = 0;
	pi_i2c_t* gyro;
	coordinate_t xyz;
	gyro = geti2cDevice();
	int x = 0, y = 0;
	float xAngle = 0, yAngle = 0;

	openJoystick();
	openDisplay();
	
	int run = 1;
 	
	if(gyro){
		configureAccelGyro(gyro);
		printf("Please leave the pi on the flat table for calibration.\n");
		while(run && getGyroPosition(gyro,&xyz) && xyz.x!=0.0){
			usleep(100);
		}
		printf("You may pick up the pi.\n");
		printf("To stop, push enter on the joystick at any time.\n");
		while(run && getGyroPosition(gyro,&xyz)){
			if(cnt == 3){
				cnt = 0;
				xAngle = xyz.x;
				yAngle = xyz.y;
						
				if(xAngle > -10 && xAngle < 10){
					x = 3;
				}else if(xAngle >= 10 && xAngle < 30){
					x = 2;
				}else if(xAngle >= 30 && xAngle < 60){
					x = 1;
				}else if(xAngle >= 60){
					x = 0;
				}else if(xAngle > -30 && xAngle <= -10){
					x = 4;
				}else if(xAngle > -60 && xAngle <= 30){
					x = 5;
				}else if(xAngle <= -60){
					x = 6;
				}
				
				if(yAngle > -10 && yAngle < 10){
					y = 3;
				}else if(yAngle >= 10 && yAngle < 30){
					y = 2;
				}else if(yAngle >= 30 && yAngle < 60){
					y = 1;
				}else if(yAngle >= 60){
					y = 0;
				}else if(yAngle > -30 && yAngle <= -10){
					y = 4;
				}else if(yAngle > -60 && yAngle <= 30){
					y = 5;
				}else if(yAngle <= -60){
					y = 6;
				}
				displayBlock(x,y);
				
				}
			cnt++;
			checkJoystick(handler,5);
			if(get_joycode() == 28){
				run = 0;
			}
		}
		closeDisplay();
		closeJoystick();
		freei2cDevice(gyro);

	}
	return 0;
}


