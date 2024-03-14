#include "CommonFunc.h"
#include "mainFunc.h"

using namespace std;


int prevX = 0;
int prevY = 0;
float angle = 0.0f;
float speed = 0.1f;

bool init();


bool loadMedia();


void close();

int thu2[10000];
SDL_RendererFlip fliptype = SDL_FLIP_NONE;
SDL_RendererFlip fliptype1;

int main(int argc, char* args[])
{
	int i = 0;
	int j = 0;
	int count = 22;
	int x = 0;
	int y = 0;
	double x1 = SCREEN_WIDTH / 2;
	double y1 = 0;
	double x2 = 250;
	double y2 = 250;
	int thu = 0;
	int dem = 0;
	

	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			
			
			bool quit = false;

			int curentImageIndex = 0;
			int flameTime;
			Uint32 flameStart;
			SDL_Event e;
			bool flipImage = false;
			
			while (!quit)
			{
				flameStart = SDL_GetTicks();
				while (SDL_PollEvent(&e) != 0)
				{
					
					if (e.type == SDL_QUIT)
					{
						quit = true;

					}
				}
				if (e.motion.xrel > 0) {
					fliptype = SDL_FLIP_NONE;
				}
				if (e.motion.xrel < 0) {
					fliptype = SDL_FLIP_HORIZONTAL;
				}

				if ((int)abs(x - x1) <= 20 && (int)abs(y - y1) <= 20)
				{
					SDL_DestroyTexture(gTexture2);
					count -= 1;
					dem += 1;
					x1 = -10;
					y1 = -100;
					
				}
				if ((int)abs(x - x2) <= 20 && (int)abs(y - y2) <= 20)
				{
					SDL_DestroyTexture(gTexture3);
					count -= 1;
					dem += 1;
					x2 = -100;
					y2 = -10;
				}
				for (int i = 0; i < 20; i++) {
					if ((int)abs(x - muoi[i].xk) <= 20 && (int)abs(y - muoi[i].yk) <= 20)
					{
						SDL_DestroyTexture(muoi[i].Texmuoi);
						muoi[i].xk = -10;
						muoi[i].yk = -10;
						count -= 1;
						dem += 1;
					}
				}
				
				
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				
				SDL_Rect topLeftViewport;
				topLeftViewport.x = 0;
				topLeftViewport.y = 0;
				topLeftViewport.w = SCREEN_WIDTH;
				topLeftViewport.h = SCREEN_HEIGHT;
				SDL_RenderSetViewport(gRenderer, &topLeftViewport);




				SDL_RenderClear(gRenderer);
				SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

				SDL_Rect rect1 = { x1 += 0 ,y1 += 2 ,50, 50 };
				if ((int)abs(x - x1) <= 50 && (int)abs(y - y1) <= 50)
				{
					thu = 1;
				}
				if (thu == 1) SDL_Rect rect1 = { x1 += 0 ,y1 -= 4, 50,50 };
				SDL_RenderCopy(gRenderer, gTexture2, NULL, &rect1);

				SDL_Rect rect2 = { x2 += 5 ,y2 += 0,50,50 };

				SDL_RenderCopy(gRenderer, gTexture3, NULL, &rect2);

				SDL_Rect rectmuoi[20];
				int testquaydau[20] = {};
				for (int i = 0; i < 20; i++)
				{
					
					if (muoi[i].xk == 1280 )
					{
						fliptype1 = SDL_FLIP_NONE;
						thu2[i] = 0;
						
					}
					else if(muoi[i].xk == 0)
					{
						fliptype1 = SDL_FLIP_HORIZONTAL;
						thu2[i] = 1;
						
					}

					if ( abs(muoi[i].yk - y) <= 50 && abs(muoi[i].xk - x) <= 150)
					{
						testquaydau[i] = 1;
					}
					if (thu2[i] == 1 && testquaydau[i] == 1)
					{
						rectmuoi[i] = { muoi[i].xk -= 1,muoi[i].yk += 0, 50, 50 };
						SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, NULL, &rectmuoi[i], NULL, NULL, SDL_FLIP_NONE);
						
					}
					else if (thu2[i] == 0 && testquaydau[i] == 1)
					{
						rectmuoi[i] = { muoi[i].xk += 1, muoi[i].yk += 0, 50, 50 };
						SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, NULL, &rectmuoi[i], NULL, NULL, SDL_FLIP_HORIZONTAL);
						
					}
					else if (thu2[i] == 0 )
					{
						rectmuoi[i] = { muoi[i].xk -= 1, muoi[i].yk += 0, 50, 50 };
						SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, NULL, &rectmuoi[i], NULL, NULL, SDL_FLIP_NONE);
						
					}
					else if(thu2[i] == 1)
					{
						rectmuoi[i] = { muoi[i].xk += 1,muoi[i].yk += 0, 50, 50 };
						SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, NULL, &rectmuoi[i], NULL, NULL, SDL_FLIP_HORIZONTAL);
					}
					

				}
				
				SDL_Rect rect[19];

				
				for (int i = 0; i < 19; i++) {
					rect[i] = { i * 115  ,0  ,114,114 };
				}

					
					SDL_GetMouseState((&x), (&y));
					
					
					SDL_Rect rect4 = {x-50,y-50,100,100};
					if (dem >= 10) rect4 = { x - 50,y - 50,200,200 };
					if (dem >= 20) rect4 = { x - 50,y - 50,300,300 };
					SDL_RenderCopyEx(gRenderer, gTexture1, &rect[i],&rect4 , 0, NULL, fliptype);
					j = (j + 1) % 31;
					i = (i + j/30) % 20;
					if (i >= 19) {
						i = 0;
					}

				SDL_Delay(20);
				if (count == 0)
				{
					SDL_Rect inwin = { 60,60,SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 };
					SDL_RenderCopy(gRenderer, win, NULL, &inwin);
				}
				
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	

	close();

	return 0;
}
