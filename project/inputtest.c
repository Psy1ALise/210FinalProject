#include "project.h"

int main(void){
	
	int cnt = 0;

	pi_i2c_t* gyro = geti2cDevice();
	
	openJoystick();
	
	coordinate_t data;

	int run = 1;

	if (gyro){
		configureAccelGyro(gyro);
		printf("Please leave the pi flat on the table for calibration\n");
		while(run && getGyroPosition(gyro, &data) && data.x!= 0.0){
			usleep(100);
		}
		printf("You may pick up the pi.\n");
		printf("To stop, push the joystick to stop anytime.\n");
		while(run && getGyroPosition(gyro,&data)){
			if(cnt == 100){
				cnt = 0;
				printf("Gyro: %f %f %f\n",data.x,data.y,data.z);
			}
			cnt++;
			checkJoystick(handler,10);
			if(get_joycode() == 28){
				run = 0;
			}
		}
		closeJoystick();
		freei2cDevice(gyro);
	}
	return 0;
}

