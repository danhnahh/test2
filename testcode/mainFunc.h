#pragma once
#ifndef MAIN_FUNCTIONS_H
#define MAIN_FUNCTIONS_H

#include "CommonFunc.h"

class object {
public:
	SDL_Texture* Texmuoi;
	int xk = 1280*(rand() % 2);
	int yk = rand() % (720 - 50 + 1) + 50;
	double k;
	int x;
	int y;

};

object muoi[20];

bool init();
bool loadMedia();
void close();

SDL_Texture* loadTexture(std::string path);


bool init()
{

	bool success = true;


	gWindow = SDL_CreateWindow("danhnahh", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);


	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{

		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);


		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
			success = false;
		}
	}


	return success;
}

bool loadMedia()
{

	bool success = true;

	gTexture = loadTexture("D:/UET/C++/vscode violet/CHECKCODE/test1/Debug/picture/background.jpg");
	gTexture1 = loadTexture("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/picture/mainshark.png");
	gTexture2 = loadTexture("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/picture/smallfish.png");
	gTexture3 = loadTexture("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/picture/smallfish.png");
	for (int i = 0; i < 20; i++)
		muoi[i].Texmuoi = loadTexture("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/picture/smallfish.png");


	win = loadTexture("D:/UET/C++/vscode violet/CHECKCODE/test1/Debug/picture/victory.jpg");
	return success;
}

SDL_Texture* loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	//Create texture from surface pixels
	newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
	//Get rid of old loaded surface
	SDL_FreeSurface(loadedSurface);

	return newTexture;
}

void close()
{
	//Free loaded image
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

#endif