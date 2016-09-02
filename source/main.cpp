#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  int time = 0;

	gfxInitDefault();

	while (aptMainLoop())
	{
		gspWaitForVBlank();
		hidScanInput();

		u32 keysPressed = hidKeysDown();
		if (keysPressed & KEY_START)
			break;

		u8* fb = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);

		memset(fb, 0, 240*400*3);

    int x, y;
    for(x = 0; x < 400; x++) {
      for(y = 0; y < 240; y++) {
        float b = (((sin(y*sin(time/40.0)*M_PI*10.0/400.0)+1)/4) + ((sin(x*sin(time/77.0)*M_PI*13.0/400.0)+1)/4));
        float g = (((sin(y*sin(time/53.0)*M_PI*23.0/400.0)+1)/4) + ((sin(x*sin(time/97.0)*M_PI*17.0/400.0)+1)/4));
        float r = (((sin(y*sin(time/27.0)*M_PI*17.0/400.0)+1)/4) + ((sin(x*sin(time/27.0)*M_PI*31.0/400.0)+1)/4));
        fb[((x*240)+y)*3+0] = (int)(b*255);
        fb[((x*240)+y)*3+1] = (int)(g*255);
        fb[((x*240)+y)*3+2] = (int)(r*255);
      }
    }

    time++;

		gfxFlushBuffers();
		gfxSwapBuffers();
	}

	gfxExit();
	return 0;
}
