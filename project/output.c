#include "project.h"
#define BLACK 0x0000
#define WHITE 0xFFFF
#define RED 0xF800
#define GREEN 0x07E0
#define YELLOW 0xFFE0
#define ORANGE 0xFC00
#define BLUE 0x001F

pi_framebuffer_t *fb = NULL;

void openDisplay(void){
	if(fb == NULL){
		fb = getFrameBuffer();
	}
}
void closeDisplay(void){
	if(fb){
		clearFrameBuffer(fb,BLACK);
		freeFrameBuffer(fb);
		fb = NULL;
	}
}

void displayBlock(int x, int y){

	sense_fb_bitmap_t *bm = fb->bitmap;
	clearFrameBuffer(fb,BLACK);
	

	if(x == 3 && y == 3){
		bm->pixel[x][y]=GREEN;
		bm->pixel[x+1][y]=GREEN;
		bm->pixel[x][y+1]=GREEN;
		bm->pixel[x+1][y+1]=GREEN;
		
	}
	if(x == 2 || x == 4){
		if(y >= 2 && y <= 4){
			bm->pixel[x][y]=YELLOW;
			bm->pixel[x+1][y]=YELLOW;
			bm->pixel[x][y+1]=YELLOW;
			bm->pixel[x+1][y+1]=YELLOW;
		}
	}

	if(x == 3){
		if(y == 2 || y == 4){
			bm->pixel[x][y]=YELLOW;
			bm->pixel[x+1][y]=YELLOW;
			bm->pixel[x][y+1]=YELLOW;
			bm->pixel[x+1][y+1]=YELLOW;
		}
	}
	
	if(x == 1 || x == 5){
		if(y >= 1 && y <= 5){
			bm->pixel[x][y]=ORANGE;
			bm->pixel[x+1][y]=ORANGE;
			bm->pixel[x][y+1]=ORANGE;
			bm->pixel[x+1][y+1]=ORANGE;
		}
	}
	if(y == 1 || y == 5){
		if(x >= 2 && x <= 4){
			bm->pixel[x][y]=ORANGE;
			bm->pixel[x+1][y]=ORANGE;
			bm->pixel[x][y+1]=ORANGE;
			bm->pixel[x+1][y+1]=ORANGE;
		}
	}

	if(x == 0 || x == 6 || y == 0 || y == 6){
		bm->pixel[x][y]=RED;
		bm->pixel[x+1][y]=RED;
		bm->pixel[x][y+1]=RED;
		bm->pixel[x+1][y+1]=RED;
	}
	
}



void clearDisplay(void){
	if(fb){
		clearFrameBuffer(fb,BLACK);
	}
}
