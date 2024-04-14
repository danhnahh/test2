#pragma once
#ifndef MAIN_FUNCTIONS_H
#define MAIN_FUNCTIONS_H

#include "CommonFunc.h"
using namespace std;

class object {
public:
	SDL_Texture* Texmuoi;
	int xk;
	int yk;
	double k;
	bool trongmanhinh = true;
	int ykdaptuong=0;
	bool test_alive = 1;
	void free() {
		SDL_Texture* Texmuoi;
		trongmanhinh = true;
		ykdaptuong=0;
	    test_alive = 1;
		xk= 1280 * ((std::rand() % 4) <= 1);
		yk = std::rand() % (650 - 50 + 1) + 50;
	}
	object() :
		xk(1280 * ((std::rand() % 4) <= 1)),
		yk(std::rand() % (650 - 50 + 1) + 50)
	{}
};
class Move {
public:
	int dichuyen;
	
	Move():
		dichuyen(std::rand() % 2 == 0 ? -1 : 1)
	{}
};

class Boss_Bullet {
	public:
		int x;
		int y;
		void rebullet() {
			x = 250; y = 250;
	}
};



std::vector<object> muoi;
std::vector<object> muoito;
std::vector<object> bigfish;

std::vector<Move> canhodichuyen;

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
	if (SDL_Init(SDL_INIT_AUDIO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return 0;
	}

	// Kh?i t?o SDL2_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return 0;
	}


	return success;
}

bool loadMedia()
{

	bool success = true;
	Boss = loadTexture("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/picture/taungamoke.png");
	music = Mix_LoadMUS("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/music/ingame.mp3");
	daddy = Mix_LoadMUS("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/music/menu.mp3");
	eatlevel1 = Mix_LoadWAV("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/music/eatlevel1.wav");
	eatlevel2 = Mix_LoadWAV("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/music/eatlevel2.wav");
	eatlevel3 = Mix_LoadWAV("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/music/eatlevel3.wav");
	bang = Mix_LoadWAV("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/music/bang.wav");
	gTexture = loadTexture("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/picture/bkf.jpg");
	gTexture1 = loadTexture("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/picture/mainshark.png");
	startmenu = loadTexture("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/picture/startmenu.jpg");
	Pause = loadTexture("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/picture/pause.jpg");
	Bullet1 = loadTexture("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/picture/bullet1.png");
	Type = loadTexture("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/picture/choose_type_2.jpg");
	muoi.resize(20);
	muoito.resize(10);
	bigfish.resize(5);
	canhodichuyen.resize(20);
	for (int i = 0; i < 20; i++)
	{
		muoi[i].Texmuoi = loadTexture("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/picture/smallfish1.png");
	}
	for (int i = 0; i < 10; i++)
	{

		muoito[i].Texmuoi = loadTexture("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/picture/mid_fishok.png");

	}
	for (int i = 0; i < 5; i++)
	{

		bigfish[i].Texmuoi = loadTexture("D:/UET/C++/vscode violet/CHECKCODE/test1/test1/picture/bigfishok.png");

	}
	Win = loadTexture("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/picture/win.jpg");
	Lose = loadTexture("D:/UET/C++/vscode violet/CHECKCODE/testcode/Debug/picture/defeat.png");
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
	Mix_FreeMusic(music);
	Mix_FreeMusic(daddy);
	Mix_CloseAudio();
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void handleRestart() {
	
	close();

	
	if (!init()) {
		std::cout << "Failed to restart SDL." << std::endl;
		
		return;
	}

	
}

//void restart() {
//	close();
//	
//	int main1argc ;
//	char** main1argv ;
//
//	class Tailai {
//	public:
//	int global_argc;
//	char** global_argv;
//		
//		void main1(int argc1, char* args1[])
//		{
//			global_argc = argc1;
//			global_argv = args1;
//			int thu2[10000];
//
//			bool thudaptuong[10000];
//
//			int thucato[10000];
//			int thubigfish[10000];
//
//			int i = 0;
//			int j = 0;
//			int count = 22;
//			int x = 0;
//			int y = 0;
//			double x1 = SCREEN_WIDTH / 2;
//			double y1 = 0;
//			double x2 = 250;
//			double y2 = 250;
//			int thu = 0;
//
//			bool lose = true;
//			int h = 0;
//			int k = 0;
//			int h1 = 0;
//			int k1 = 0;
//			int h2 = 0;
//			int k2 = 0;
//			//std::srand(std::time(NULL));
//
//			//std::srand(std::time(nullptr));
//			if (!init())
//			{
//				printf("Failed to initialize!\n");
//			}
//			else
//			{
//
//				if (!loadMedia())
//				{
//					printf("Failed to load media!\n");
//				}
//				else
//				{
//					Mix_PlayMusic(music, -1);
//
//					bool quit = false;
//
//					int curentImageIndex = 0;
//					int flameTime;
//					Uint32 flameStart;
//					SDL_Event e;
//					bool flipImage = false;
//
//					while (!quit)
//					{
//						flameStart = SDL_GetTicks();
//						while (SDL_PollEvent(&e) != 0)
//						{
//
//							if (e.type == SDL_QUIT)
//							{
//								quit = true;
//
//							}
//						}
//						if (e.motion.xrel > 0) {
//							fliptype = SDL_FLIP_NONE;
//						}
//						if (e.motion.xrel < 0) {
//							fliptype = SDL_FLIP_HORIZONTAL;
//						}
//						/*std::cout << dem;*/
//
//
//
//
//
//
//
//
//
//						for (int i = 0; i < (int)muoi.size(); i++) {
//							if ((int)abs(x - muoi[i].xk) <= 20 && (int)abs(y - muoi[i].yk) <= 20)
//							{
//								SDL_DestroyTexture(muoi[i].Texmuoi);
//								muoi[i].xk = -10;
//								muoi[i].yk = -10;
//								count -= 1;
//								dem += 1;
//							}
//						}
//						for (int i = 0; i < 10; i++) {
//							if ((int)abs(x - muoito[i].xk) <= 50 && (int)abs(y - muoito[i].yk) <= 50 && dem >= 10)
//							{
//								SDL_DestroyTexture(muoito[i].Texmuoi);
//								muoito[i].xk = -10;
//								muoito[i].yk = -10;
//								count -= 1;
//								dem += 1;
//							}
//						}
//						for (int i = 0; i < (int)muoito.size(); i++)
//						{
//							if (abs(x - muoito[i].xk) <= 40 && abs(y - muoito[i].yk) <= 40 && dem < 10)
//							{
//								SDL_DestroyTexture(gTexture1);
//								lose = false;
//							}
//						}
//						for (int i = 0; i < (int)bigfish.size(); i++) {
//							if ((int)abs(x - bigfish[i].xk) <= 50 && (int)abs(y - bigfish[i].yk) <= 50 && dem >= 20)
//							{
//								SDL_DestroyTexture(bigfish[i].Texmuoi);
//								bigfish[i].xk = -10;
//								bigfish[i].yk = -10;
//								count -= 1;
//								dem += 1;
//							}
//						}
//						for (int i = 0; i < 5; i++)
//						{
//							if (abs(x - bigfish[i].xk) <= 40 && abs(y - bigfish[i].yk) <= 40 && dem < 20) {
//								SDL_DestroyTexture(gTexture1);
//								lose = false;
//							}
//						}
//
//						for (int i = 0; i < (int)bigfish.size(); i++)
//						{
//							for (int j = 0; j < (int)muoito.size(); j++)
//							{
//								//if (abs(bigfish[i].xk - muoito[j].xk) <= 65 && abs(bigfish[i].yk - muoito[j].yk) <= 65) bigfish_gap_midfish = true;
//								if (abs(bigfish[i].xk - muoito[j].xk) <= 50 && abs(bigfish[i].yk - muoito[j].yk) <= 50)
//								{
//									SDL_DestroyTexture(muoito[j].Texmuoi);
//									muoito[j].xk = -100;
//									muoito[j].yk = -100;
//								}
//							}
//						}
//						for (int i = 0; i < (int)bigfish.size(); i++)
//						{
//							for (int j = 0; j < (int)muoi.size(); j++)
//							{
//								//if (abs(bigfish[i].xk - muoito[j].xk) <= 65 && abs(bigfish[i].yk - muoito[j].yk) <= 65) bigfish_gap_midfish = true;
//								if (abs(bigfish[i].xk - muoi[j].xk) <= 20 && abs(bigfish[i].yk - muoi[j].yk) <= 20)
//								{
//									SDL_DestroyTexture(muoi[j].Texmuoi);
//									muoi[j].xk = -100;
//									muoi[j].yk = -100;
//								}
//							}
//						}
//						for (int i = 0; i < (int)muoito.size(); i++)
//						{
//							for (int j = 0; j < (int)muoi.size(); j++)
//							{
//								//if (abs(bigfish[i].xk - muoito[j].xk) <= 65 && abs(bigfish[i].yk - muoito[j].yk) <= 65) bigfish_gap_midfish = true;
//								if (abs(muoito[i].xk - muoi[j].xk) <= 20 && abs(muoito[i].yk - muoi[j].yk) <= 20)
//								{
//									SDL_DestroyTexture(muoi[j].Texmuoi);
//									muoi[j].xk = -100;
//									muoi[j].yk = -100;
//								}
//							}
//						}
//						SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//						SDL_RenderClear(gRenderer);
//
//
//						SDL_Rect topLeftViewport;
//						topLeftViewport.x = 0;
//						topLeftViewport.y = 0;
//						topLeftViewport.w = SCREEN_WIDTH;
//						topLeftViewport.h = SCREEN_HEIGHT;
//						SDL_RenderSetViewport(gRenderer, &topLeftViewport);
//
//
//
//
//						SDL_RenderClear(gRenderer);
//						SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
//
//
//
//
//						SDL_Rect rectmuoi[50];
//						int testquaydau[50] = {};
//						h1 = (h1 + 1) % 4;
//						k1 = (k1 + h1 / 3) % 14;
//						for (int i = 0; i < (int)muoi.size(); i++)
//						{
//
//							SDL_Rect ca_nho[13];
//							for (int k = 0; k < 13; k++)
//							{
//								ca_nho[k] = { k * 480,0,480,270 };
//							}
//							if (muoi[i].xk == 1280)
//							{
//								thu2[i] = 0;
//							}
//							else if (muoi[i].xk <= 0)
//							{
//								thu2[i] = 1;
//							}
//							if (k1 >= 13)
//							{
//								k1 = 0;
//							}
//							if (muoi[i].yk >= 700)
//							{
//								muoi[i].trongmanhinh = false;
//							}
//							if (muoi[i].yk <= 0)
//							{
//								muoi[i].trongmanhinh = false;
//							}
//							if (muoi[i].trongmanhinh == false)
//							{
//
//								if (muoi[i].yk >= 700) muoi[i].ykdaptuong = -2;
//								if (muoi[i].yk <= 0) muoi[i].ykdaptuong = 2;
//							}
//							if (abs(muoi[i].yk - y) < 50 && abs(muoi[i].xk - x) < 150)
//							{
//								testquaydau[i] = 1;
//							}
//							if (thu2[i] == 1 && testquaydau[i] == 1)
//							{
//								rectmuoi[i] = { muoi[i].xk -= 2,muoi[i].yk += (rand() % 3) * ((rand() % 2 == 0) ? -1 : 1), 80, 80 };
//								SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, &ca_nho[k1], &rectmuoi[i], NULL, NULL, SDL_FLIP_NONE);
//
//
//							}
//							else if (thu2[i] == 0 && testquaydau[i] == 1)
//							{
//								rectmuoi[i] = { muoi[i].xk += 2, muoi[i].yk += (rand() % 3) * ((rand() % 2 == 0) ? -1 : 1), 80, 80 };
//								SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, &ca_nho[k1], &rectmuoi[i], NULL, NULL, SDL_FLIP_HORIZONTAL);
//
//							}
//							else if (thu2[i] == 0)
//							{
//								rectmuoi[i] = { muoi[i].xk -= (rand() % 3) , muoi[i].yk += canhodichuyen[i].dichuyen, 80, 80 };
//								SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, &ca_nho[k1], &rectmuoi[i], NULL, NULL, SDL_FLIP_NONE);
//								if (muoi[i].trongmanhinh == false)
//								{
//									rectmuoi[i] = { muoi[i].xk -= (rand() % 3) , muoi[i].yk += muoi[i].ykdaptuong, 80, 80 };
//									SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, &ca_nho[k1], &rectmuoi[i], NULL, NULL, SDL_FLIP_NONE);
//									//muoi[i + 1].trongmanhinh = false;
//								}
//
//
//							}
//							else if (thu2[i] == 1)
//							{
//								rectmuoi[i] = { muoi[i].xk += (rand() % 3) ,muoi[i].yk += canhodichuyen[i].dichuyen, 80, 80 };
//								SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, &ca_nho[k1], &rectmuoi[i], NULL, NULL, SDL_FLIP_HORIZONTAL);
//								if (muoi[i].trongmanhinh == false)
//								{
//									rectmuoi[i] = { muoi[i].xk += (rand() % 3) , muoi[i].yk += muoi[i].ykdaptuong, 80, 80 };
//									SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, &ca_nho[k1], &rectmuoi[i], NULL, NULL, SDL_FLIP_HORIZONTAL);
//									//muoi[i + 1].trongmanhinh = false;
//								}
//
//							}
//						}
//
//
//
//
//
//
//						SDL_Rect Rectcato[10];
//
//						int ca_to_quay_dau[10] = {};
//
//						h = (h + 1) % 4;
//						k = (k + h / 3) % 26;
//						for (int i = 0; i < 10; i++)
//						{
//
//							SDL_Rect ca_vua[29];
//							for (int k = 0; k < 29; k++)
//							{
//								ca_vua[k] = { k * 480,0,480,480 };
//							}
//
//							if (muoito[i].xk == 1280)
//							{
//
//								thucato[i] = 0;
//
//							}
//							else if (muoito[i].xk <= 0)
//							{
//
//								thucato[i] = 1;
//
//							}
//							if (k >= 29)
//							{
//								k = 0;
//							}
//							if (abs(muoito[i].yk - y) < 50 && abs(muoito[i].xk - x) < 150)
//							{
//								ca_to_quay_dau[i] = 1;
//							}
//							if (thucato[i] == 1 && ca_to_quay_dau[i] == 1 && dem >= 10)
//							{
//								Rectcato[i] = { muoito[i].xk -= 4, muoito[i].yk += 0, 80, 80 };
//								SDL_RenderCopyEx(gRenderer, muoito[i].Texmuoi, &ca_vua[k], &Rectcato[i], NULL, NULL, SDL_FLIP_NONE);
//
//
//							}
//							else if (thucato[i] == 0 && ca_to_quay_dau[i] == 1 && dem >= 10)
//							{
//								Rectcato[i] = { muoito[i].xk += 4, muoito[i].yk += 0, 80, 80 };
//								SDL_RenderCopyEx(gRenderer, muoito[i].Texmuoi, &ca_vua[k], &Rectcato[i], NULL, NULL, SDL_FLIP_HORIZONTAL);
//
//
//							}
//							else if (thucato[i] == 0)
//							{
//								Rectcato[i] = { muoito[i].xk -= 2, muoito[i].yk += 0, 80, 80 };
//								SDL_RenderCopyEx(gRenderer, muoito[i].Texmuoi, &ca_vua[k], &Rectcato[i], NULL, NULL, SDL_FLIP_NONE);
//							}
//							else if (thucato[i] == 1)
//							{
//								Rectcato[i] = { muoito[i].xk += 2,muoito[i].yk += 0, 80, 80 };
//								SDL_RenderCopyEx(gRenderer, muoito[i].Texmuoi, &ca_vua[k], &Rectcato[i], NULL, NULL, SDL_FLIP_HORIZONTAL);
//
//							}
//
//
//						}
//
//						SDL_Rect Rectbigfish[5];
//
//						int bigfish_quay_dau[5] = {};
//						h2 = (h2 + 1) % 4;
//						k2 = (k2 + h2 / 3) % 25;
//
//						for (int i = 0; i < 5; i++)
//						{
//							SDL_Rect ca_to[29];
//							for (int k = 0; k < 29; k++)
//							{
//								ca_to[k] = { k * 480,0,480,345 };
//							}
//
//							if (bigfish[i].xk == 1280)
//							{
//
//								thubigfish[i] = 0;
//
//							}
//							else if (bigfish[i].xk <= 0)
//							{
//
//								thubigfish[i] = 1;
//
//							}
//
//							if (abs(bigfish[i].yk - y) < 100 && abs(bigfish[i].xk - x) < 350)
//							{
//								bigfish_quay_dau[i] = 1;
//							}
//							if (thubigfish[i] == 1 && bigfish_quay_dau[i] == 1 && dem >= 20)
//							{
//								Rectbigfish[i] = { bigfish[i].xk -= 4, bigfish[i].yk += 0, 150, 150 };
//								SDL_RenderCopyEx(gRenderer, bigfish[i].Texmuoi, &ca_to[k2], &Rectbigfish[i], NULL, NULL, SDL_FLIP_NONE);
//
//							}
//							else if (thubigfish[i] == 0 && bigfish_quay_dau[i] == 1 && dem >= 20)
//							{
//								Rectbigfish[i] = { bigfish[i].xk += 4, bigfish[i].yk += 0, 150, 150 };
//								SDL_RenderCopyEx(gRenderer, bigfish[i].Texmuoi, &ca_to[k2], &Rectbigfish[i], NULL, NULL, SDL_FLIP_HORIZONTAL);
//
//							}
//							else if (thubigfish[i] == 0)
//							{
//								Rectbigfish[i] = { bigfish[i].xk -= 2, bigfish[i].yk += 0, 150, 150 };
//								SDL_RenderCopyEx(gRenderer, bigfish[i].Texmuoi, &ca_to[k2], &Rectbigfish[i], NULL, NULL, SDL_FLIP_NONE);
//
//							}
//							else if (thubigfish[i] == 1)
//							{
//								Rectbigfish[i] = { bigfish[i].xk += 2,bigfish[i].yk += 0, 150, 150 };
//								SDL_RenderCopyEx(gRenderer, bigfish[i].Texmuoi, &ca_to[k2], &Rectbigfish[i], NULL, NULL, SDL_FLIP_HORIZONTAL);
//							}
//
//
//						}
//
//
//
//
//
//						SDL_Rect rect[19];
//
//						for (int i = 0; i < 19; i++) {
//							rect[i] = { i * 115  ,0  ,114,114 };
//						}
//
//
//						SDL_GetMouseState((&x), (&y));
//
//						SDL_Rect rect4;
//						if (dem < 10)
//						{
//							rect4 = { x - 50,y - 50,100,100 };
//						}
//						if (dem >= 10) rect4 = { x - 100,y - 100,200,200 };
//						if (dem >= 20) rect4 = { x - 150,y - 150,300,300 };
//						SDL_RenderCopyEx(gRenderer, gTexture1, &rect[i], &rect4, 0, NULL, fliptype);
//						j = (j + 1) % 11;
//						i = (i + j / 10) % 20;
//						if (i >= 19)
//						{
//							i = 0;
//						}
//
//						SDL_Delay(20);
//						if (dem >= 30)
//						{
//							SDL_Rect inwin = { 0,00,SCREEN_WIDTH ,SCREEN_HEIGHT };
//							SDL_RenderCopy(gRenderer, win, NULL, &inwin);
//						}
//						if (lose == false)
//						{
//							SDL_Rect inlose = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
//							SDL_RenderCopy(gRenderer, Lose, NULL, &inlose);
//						}
//
//						SDL_RenderPresent(gRenderer);
//					}
//				}
//			}
//
//
//
//			close();
//
//		}
//	};
//
//	Tailai okeokeoke;
//	main1argc = okeokeoke.global_argc;
//	main1argv = okeokeoke.global_argv;
//	okeokeoke.main1(main1argc,main1argv);
//	
//}



#endif