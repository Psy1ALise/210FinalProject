#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include <linux/input.h>
#include <unistd.h>
#include "sense.h"


void handler(unsigned int code);
void openJoystick(void);
void closeJoystick(void);
void checkJoystick(void (*callback)(unsigned int code), int delay);
void interrupt_handler(int sig);
int get_joycode(void);

void openDisplay(void);
void closeDisplay(void);
void displayBlock(int xAngle, int yAngle);
void clearDisplay(void);

