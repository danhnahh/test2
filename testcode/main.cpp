#include "CommonFunc.h"
#include "mainFunc.h"

using namespace std;


bool init();


bool loadMedia();


void close();

int thu2[10000];

bool thudaptuong[10000];

int thucato[10000];

int thubigfish[10000];

bool thubossquaydau = false;


//int i = 0;
//int j = 0;
//int count = 22;
//int x = 0;
//int y = 0;
//double x1 = SCREEN_WIDTH / 2;
//double y1 = 0;
//double x2 = 250;
//double y2 = 250;
//int thu = 0;
//
//bool lose = true;
//int h = 0;
//int k = 0;
//int h1 = 0;
//int k1 = 0;
//int h2 = 0;
//int k2 = 0;

int main(int argc, char* args[])
{
	Boss_Bullet bullet;
	//std::srand(std::time(NULL));
	int i = 0;
	int j = 0;
	int count = 22;
	int x = 0;
	int y = 0;
	double x1 = SCREEN_WIDTH / 2;
	double y1 = 0;
	int x2 = 250;
	int y2 = 250;
	int thu = 0;
	//
	bool lose = true;
	int h = 0;
	int k = 0;
	int h1 = 0;
	int k1 = 0;
	int h2 = 0;
	int k2 = 0;
	int dem = 0;

	bool win = false;
	int typegame = 0;
	bool pause = false;
	float X;
	float Y;
	int start = 0;
	bool alive = true;
	bullet.x = x2 + 100;
	bullet.y = y2 + 100;
	bullet.rebullet();
	int daban = false;
	float angle;
	bool click = false;
	bool checktype = false;
	/*float delta_x;
	float delta_y;
	float angle;*/
	//std::srand(std::time(nullptr));
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
			/*Mix_PlayMusic(music, -1);*/

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
					
					SDL_GetMouseState((&x), (&y));
					//cout << x << " " << y << endl;
					if (e.type == SDL_MOUSEBUTTONDOWN && x >= 478 && x <= 755 && y >= 275 && y <= 354 && checktype == false)
					{
						cout << "okeokeoke";
						start = 1;
						click = true;
						checktype = true;
					}
					else if (e.type == SDL_MOUSEBUTTONUP) click = false;
					if (e.type == SDL_MOUSEBUTTONDOWN && ((lose == false && x >= 518 && x <= 741 && y >= 601 && y <= 654) || ( win == true && x >= 581 && x <= 695 && y >= 395 && y <= 435)) )
					{
						bullet;
						win = false;
						lose = true;
						start = 0;
						int i = 0;
						int j = 0;
						int count = 22;
						int x = 0;
						int y = 0;
						double x1 = SCREEN_WIDTH / 2;
						double y1 = 0;
						x2 = 250;
						y2 = 250;
						int thu = 0;
						//
						typegame = 0;
						int h = 0;
						int k = 0;
						int h1 = 0;
						int k1 = 0;
						int h2 = 0;
						int k2 = 0;
						dem = 0;
						checktype = false;
						alive = true;
						bullet.rebullet();
						bullet.x = x2 + 100;
						bullet.y = y2 + 100;
						for (int i = 0; i < (int)muoi.size(); i++) {
							muoi[i].free();
						}
						for (int i = 0; i < (int)muoito.size(); i++) {
							muoito[i].free();
						}
						for (int i = 0; i < (int)bigfish.size(); i++) {
							bigfish[i].free();
						}
					}
					
					if(pause == true)
					{
						if (e.type == SDL_MOUSEBUTTONDOWN && x >= 448 && x <= 829 && y >= 193 && y <= 295 )
						{
							pause = false;
						}
						if(e.type == SDL_MOUSEBUTTONDOWN && x >= 428 && x <= 829 && y >= 368 && y <= 459)
						{
							bullet;
							win = false;
							pause = false;
							lose = true;
							start = 0;
							i = 0;
							j = 0;
							count = 22;
							 
							x = 0;
							y = 0;
							x1 = SCREEN_WIDTH / 2;
							y1 = 0;
							x2 = 250;
							y2 = 250;
							thu = 0;
							//
							checktype = false;
							typegame = 0;
							h = 0;
							k = 0;
							h1 = 0;
							k1 = 0;
							h2 = 0;
							k2 = 0;
							dem = 0;
							alive = true;
							bullet.rebullet();
							bullet.x = x2 +100;
							bullet.y = y2 + 100;
							for (int i = 0; i < (int)muoi.size(); i++) {
								muoi[i].free();
							}
							for (int i = 0; i < (int)muoito.size(); i++) {
								muoito[i].free();
							}
							for (int i = 0; i < (int)bigfish.size(); i++) {
								bigfish[i].free();
							}
						}
					}
					else 
					{
						if (e.type == SDL_MOUSEBUTTONDOWN && x >= 1125 && x <= 1231 && y >= 17 && y <= 88)
						{
							pause = true;
						}
					}
				}
					X = x;
					Y = y;
					
				if (start == 0)
				{
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
					SDL_RenderClear(gRenderer);

					Mix_PlayMusic(music, -1);
					
					SDL_Rect startgame = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
					SDL_RenderClear(gRenderer);
					SDL_RenderCopy(gRenderer, startmenu, NULL, &startgame);
					SDL_RenderPresent(gRenderer);
				}
				if (start == 1 && click == false)
				{
					/*click = true;*/
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
					SDL_RenderClear(gRenderer);

					Mix_PlayMusic(music, -1);
					cout << x <<" " << y << endl;
					SDL_Rect type = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
					SDL_RenderClear(gRenderer);
					SDL_RenderCopy(gRenderer, Type, NULL, &type);
					SDL_Rect type1 = {72,248,266,173};
					SDL_RenderCopy(gRenderer, Type1, NULL, &type1);
					SDL_Rect type2 = {493,251,266,173};
					SDL_RenderCopy(gRenderer, Type2, NULL, &type2);
					SDL_Rect type3 = {908,249,266,173};
					SDL_RenderCopy(gRenderer, Type3, NULL, &type3);
					
					if (e.type == SDL_MOUSEBUTTONDOWN && x >= 48 && x <= 343 && y >= 239 && y <= 431)
					{
						click = true;
						typegame = 1;
						start = 2;
					}
					else if (e.type == SDL_MOUSEBUTTONUP) click = false;
					if (e.type == SDL_MOUSEBUTTONDOWN && x >= 478 && x <= 766 && y >= 237 && y <= 428)
					{
						click = true;
						typegame = 2;
						start = 2;
					}
					else if (e.type == SDL_MOUSEBUTTONUP) click = false;
					if (e.type == SDL_MOUSEBUTTONDOWN && x >= 910 && x <= 1172 && y >= 247 && y <= 412)
					{
						click = true;
						typegame = 3;
						start = 2;
					}
					else if (e.type == SDL_MOUSEBUTTONUP) click = false;
					SDL_RenderPresent(gRenderer);
				}
				if (pause == true)
				{

					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
					SDL_RenderClear(gRenderer);

					Mix_PlayMusic(music, -1);

					SDL_Rect pausegame = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
					SDL_RenderClear(gRenderer);
					SDL_RenderCopy(gRenderer, Pause, NULL, &pausegame);
					SDL_RenderPresent(gRenderer);
				}
				
				if (start == 2) {
					if (typegame == 2)
					{
						if (pause == false)
						{

							if (e.motion.xrel > 0) {
								fliptype = SDL_FLIP_NONE;
							}
							if (e.motion.xrel < 0) {
								fliptype = SDL_FLIP_HORIZONTAL;
							}
							/*std::cout << dem;*/










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




							SDL_Rect rectmuoi[50];
							int testquaydau[50] = {};
							h1 = (h1 + 1) % 4;
							k1 = (k1 + h1 / 3) % 14;
							for (int i = 0; i < (int)muoi.size(); i++)
							{

								SDL_Rect ca_nho[13];
								for (int k = 0; k < 13; k++)
								{
									ca_nho[k] = { k * 480,0,480,270 };
								}
								if (muoi[i].test_alive == 1 && alive == true)
								{
									if (muoi[i].xk == 1280)
									{
										thu2[i] = 0;
									}
									else if (muoi[i].xk <= 0)
									{
										thu2[i] = 1;
									}
									if (k1 >= 13)
									{
										k1 = 0;
									}
									if (muoi[i].yk >= 700)
									{
										muoi[i].trongmanhinh = false;
									}
									if (muoi[i].yk <= 0)
									{
										muoi[i].trongmanhinh = false;
									}
									if (muoi[i].trongmanhinh == false)
									{

										if (muoi[i].yk >= 700) muoi[i].ykdaptuong = -2;
										if (muoi[i].yk <= 0) muoi[i].ykdaptuong = 2;
									}
									if (abs(muoi[i].yk - y) < 50 && abs(muoi[i].xk - x) < 150)
									{
										testquaydau[i] = 1;
									}
									if (thu2[i] == 1 && testquaydau[i] == 1)
									{
										rectmuoi[i] = { muoi[i].xk -= 2,muoi[i].yk += (rand() % 3) * ((rand() % 2 == 0) ? -1 : 1), 80, 80 };
										SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, &ca_nho[k1], &rectmuoi[i], NULL, NULL, SDL_FLIP_NONE);


									}
									else if (thu2[i] == 0 && testquaydau[i] == 1)
									{
										rectmuoi[i] = { muoi[i].xk += 2, muoi[i].yk += (rand() % 3) * ((rand() % 2 == 0) ? -1 : 1), 80, 80 };
										SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, &ca_nho[k1], &rectmuoi[i], NULL, NULL, SDL_FLIP_HORIZONTAL);

									}
									else if (thu2[i] == 0)
									{
										rectmuoi[i] = { muoi[i].xk -= (rand() % 3) , muoi[i].yk += canhodichuyen[i].dichuyen, 80, 80 };
										SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, &ca_nho[k1], &rectmuoi[i], NULL, NULL, SDL_FLIP_NONE);
										if (muoi[i].trongmanhinh == false)
										{
											rectmuoi[i] = { muoi[i].xk -= (rand() % 3) , muoi[i].yk += muoi[i].ykdaptuong, 80, 80 };
											SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, &ca_nho[k1], &rectmuoi[i], NULL, NULL, SDL_FLIP_NONE);
											//muoi[i + 1].trongmanhinh = false;
										}


									}
									else if (thu2[i] == 1)
									{
										rectmuoi[i] = { muoi[i].xk += (rand() % 3) ,muoi[i].yk += canhodichuyen[i].dichuyen, 80, 80 };
										SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, &ca_nho[k1], &rectmuoi[i], NULL, NULL, SDL_FLIP_HORIZONTAL);
										if (muoi[i].trongmanhinh == false)
										{
											rectmuoi[i] = { muoi[i].xk += (rand() % 3) , muoi[i].yk += muoi[i].ykdaptuong, 80, 80 };
											SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, &ca_nho[k1], &rectmuoi[i], NULL, NULL, SDL_FLIP_HORIZONTAL);
											//muoi[i + 1].trongmanhinh = false;
										}

									}
								}
							}






							SDL_Rect Rectcato[10];

							int ca_to_quay_dau[10] = {};

							h = (h + 1) % 4;
							k = (k + h / 3) % 26;
							for (int i = 0; i < 10; i++)
							{

								SDL_Rect ca_vua[29];
								for (int k = 0; k < 29; k++)
								{
									ca_vua[k] = { k * 480,0,480,480 };
								}

								if (muoito[i].test_alive == 1 && alive == true)
								{
									if (muoito[i].xk == 1280)
									{

										thucato[i] = 0;

									}
									else if (muoito[i].xk <= 0)
									{

										thucato[i] = 1;

									}
									if (k >= 29)
									{
										k = 0;
									}
									if (abs(muoito[i].yk - y) < 50 && abs(muoito[i].xk - x) < 150)
									{
										ca_to_quay_dau[i] = 1;
									}
									if (thucato[i] == 1 && ca_to_quay_dau[i] == 1 && dem >= 10)
									{
										Rectcato[i] = { muoito[i].xk -= 4, muoito[i].yk += 0, 80, 80 };
										SDL_RenderCopyEx(gRenderer, muoito[i].Texmuoi, &ca_vua[k], &Rectcato[i], NULL, NULL, SDL_FLIP_NONE);


									}
									else if (thucato[i] == 0 && ca_to_quay_dau[i] == 1 && dem >= 10)
									{
										Rectcato[i] = { muoito[i].xk += 4, muoito[i].yk += 0, 80, 80 };
										SDL_RenderCopyEx(gRenderer, muoito[i].Texmuoi, &ca_vua[k], &Rectcato[i], NULL, NULL, SDL_FLIP_HORIZONTAL);


									}
									else if (thucato[i] == 0)
									{
										Rectcato[i] = { muoito[i].xk -= 2, muoito[i].yk += 0, 80, 80 };
										SDL_RenderCopyEx(gRenderer, muoito[i].Texmuoi, &ca_vua[k], &Rectcato[i], NULL, NULL, SDL_FLIP_NONE);
									}
									else if (thucato[i] == 1)
									{
										Rectcato[i] = { muoito[i].xk += 2,muoito[i].yk += 0, 80, 80 };
										SDL_RenderCopyEx(gRenderer, muoito[i].Texmuoi, &ca_vua[k], &Rectcato[i], NULL, NULL, SDL_FLIP_HORIZONTAL);

									}
								}


							}

							SDL_Rect Rectbigfish[5];

							int bigfish_quay_dau[5] = {};
							h2 = (h2 + 1) % 4;
							k2 = (k2 + h2 / 3) % 25;

							for (int i = 0; i < 5; i++)
							{
								SDL_Rect ca_to[29];
								for (int k = 0; k < 29; k++)
								{
									ca_to[k] = { k * 480,0,480,345 };
								}

								if (bigfish[i].test_alive == 1 && alive == true)
								{

									if (bigfish[i].xk == 1280)
									{

										thubigfish[i] = 0;

									}
									else if (bigfish[i].xk <= 0)
									{

										thubigfish[i] = 1;

									}

									if (abs(bigfish[i].yk - y) < 100 && abs(bigfish[i].xk - x) < 350)
									{
										bigfish_quay_dau[i] = 1;
									}
									if (thubigfish[i] == 1 && bigfish_quay_dau[i] == 1 && dem >= 20)
									{
										Rectbigfish[i] = { bigfish[i].xk -= 4, bigfish[i].yk += 0, 150, 150 };
										SDL_RenderCopyEx(gRenderer, bigfish[i].Texmuoi, &ca_to[k2], &Rectbigfish[i], NULL, NULL, SDL_FLIP_NONE);

									}
									else if (thubigfish[i] == 0 && bigfish_quay_dau[i] == 1 && dem >= 20)
									{
										Rectbigfish[i] = { bigfish[i].xk += 4, bigfish[i].yk += 0, 150, 150 };
										SDL_RenderCopyEx(gRenderer, bigfish[i].Texmuoi, &ca_to[k2], &Rectbigfish[i], NULL, NULL, SDL_FLIP_HORIZONTAL);

									}
									else if (thubigfish[i] == 0)
									{
										Rectbigfish[i] = { bigfish[i].xk -= 2, bigfish[i].yk += 0, 150, 150 };
										SDL_RenderCopyEx(gRenderer, bigfish[i].Texmuoi, &ca_to[k2], &Rectbigfish[i], NULL, NULL, SDL_FLIP_NONE);

									}
									else if (thubigfish[i] == 1)
									{
										Rectbigfish[i] = { bigfish[i].xk += 2,bigfish[i].yk += 0, 150, 150 };
										SDL_RenderCopyEx(gRenderer, bigfish[i].Texmuoi, &ca_to[k2], &Rectbigfish[i], NULL, NULL, SDL_FLIP_HORIZONTAL);
									}
								}

							}
							float delta_x;
							float delta_y;
							/*float angle;*/


							SDL_Rect boss;
							if (dem >= 10)
							{
								if (x2 <= 0) {

									thubossquaydau = false;

								}
								if (x2 >= 1280) {

									thubossquaydau = true;
								}
								if (thubossquaydau == false) {
									boss = { x2 += 5, y2 += 0, 200, 200 };
									SDL_RenderCopyEx(gRenderer, Boss, NULL, &boss, NULL, NULL, SDL_FLIP_NONE);
								}
								if (thubossquaydau == true) {
									boss = { x2 -= 5, y2 -= 0, 200, 200 };
									SDL_RenderCopyEx(gRenderer, Boss, NULL, &boss, NULL, NULL, SDL_FLIP_HORIZONTAL);
								}
								if (daban == false) {
									delta_x = X - bullet.x;
									delta_y = Y - bullet.y;
									angle = atan2(delta_y, delta_x);

								}
								daban = true;

								SDL_Rect banbullet;
								banbullet = { bullet.x += 10 * cos(angle), bullet.y += 10 * sin(angle), 30,30 };
								SDL_RenderCopy(gRenderer, Bullet1, NULL, &banbullet);
								if (bullet.y >= 720 || bullet.y <= 0 || bullet.x >= 1280 || bullet.x <= 0)
								{
									bullet.rebullet();
									bullet.x = x2 + 100;
									bullet.y = y2 + 100;
									daban = false;
								}


							}

							if (alive == true)
							{

								SDL_Rect rect[19];

								for (int i = 0; i < 19; i++) {
									rect[i] = { i * 115  ,0  ,114,114 };


								}
								
								SDL_Rect rect4;
								if (dem < 10)
								{
									rect4 = { x - 50,y - 50,100,100 };
								}
								if (dem >= 10) rect4 = { x - 100,y - 100,200,200 };
								if (dem >= 20) rect4 = { x - 150,y - 150,300,300 };

								SDL_RenderCopyEx(gRenderer, gTexture1, &rect[i], &rect4, 0, NULL, fliptype);
								j = (j + 1) % 11;
								i = (i + j / 10) % 20;
								if (i >= 19)
								{
									i = 0;
								}

							}

							for (int i = 0; i < (int)muoi.size(); i++) {
								if ((int)abs(x - muoi[i].xk) <= 20 && (int)abs(y - muoi[i].yk) <= 20 && muoi[i].test_alive == 1 && alive == true)
								{

									/*SDL_DestroyTexture(muoi[i].Texmuoi);
									muoi[i].xk = -100;
									muoi[i].yk = -100;*/
									muoi[i].test_alive = 0;
									muoi[i].free();
									
									if (win == false || lose == true) Mix_PlayChannel(-1, eatlevel1, 1);

									dem += 1;
								}
							}
							for (int i = 0; i < (int)muoi.size(); i++) {
								if ((int)abs(bullet.x - muoi[i].xk) <= 20 && (int)abs(bullet.y - muoi[i].yk) <= 20 && muoi[i].test_alive == 1 && alive == true)
								{

									/*SDL_DestroyTexture(muoi[i].Texmuoi);
									muoi[i].xk = -100;
									muoi[i].yk = -100;*/
									muoi[i].test_alive = 0;
									if (win == false || lose == true) Mix_PlayChannel(-1, bang, 1);
									muoi[i].free();
									bullet.rebullet();
									bullet.x = x2 + 100;
									bullet.y = y2 + 100;
									daban = false;

								}
							}
							for (int i = 0; i < 10; i++) {
								if ((int)abs(x - muoito[i].xk) <= 50 && (int)abs(y - muoito[i].yk) <= 50 && dem >= 10 && muoito[i].test_alive == 1 && alive == true)
								{
									/*SDL_DestroyTexture(muoito[i].Texmuoi);
									muoito[i].xk = -100;
									muoito[i].yk = -100;*/
									muoito[i].test_alive = 0;
									muoito[i].free();
									
									if (win == false || lose == true) Mix_PlayChannel(-1, eatlevel2, 1);
									dem += 1;
								}
							}
							for (int i = 0; i < 10; i++) {
								if ((int)abs(bullet.x - muoito[i].xk) <= 50 && (int)abs(bullet.y - muoito[i].yk) <= 50 && muoito[i].test_alive == 1 && alive == true)
								{
									/*SDL_DestroyTexture(muoito[i].Texmuoi);
									muoito[i].xk = -100;
									muoito[i].yk = -100;*/
									muoito[i].test_alive = 0;
									if (win == false || lose == true) Mix_PlayChannel(-1, bang, 1);
									muoito[i].free();
									bullet.rebullet();
									bullet.x = x2 + 100;
									bullet.y = y2 + 100;
									daban = false;
								}
							}
							for (int i = 0; i < (int)muoito.size(); i++)
							{
								if (abs(x - muoito[i].xk) <= 30 && abs(y - muoito[i].yk) <= 30 && dem < 10)
								{
									alive = false;
									lose = false;
								}
							}
							for (int i = 0; i < (int)bigfish.size(); i++) {
								if ((int)abs(x - bigfish[i].xk) <= 50 && (int)abs(y - bigfish[i].yk) <= 50 && dem >= 20 && bigfish[i].test_alive == 1 && alive == true)
								{
									/*SDL_DestroyTexture(bigfish[i].Texmuoi);
									bigfish[i].xk = -100;
									bigfish[i].yk = -100;*/
									bigfish[i].test_alive = 0;
									bigfish[i].free();
								}
							}
							for (int i = 0; i < (int)bigfish.size(); i++) {
								if ((int)abs(bullet.x - bigfish[i].xk) <= 50 && (int)abs(bullet.y - bigfish[i].yk) <= 50 && bigfish[i].test_alive == 1 && alive == true)
								{
									/*SDL_DestroyTexture(bigfish[i].Texmuoi);
									bigfish[i].xk = -100;
									bigfish[i].yk = -100;*/
									bigfish[i].test_alive = 0;
									if (win == false || lose == true) Mix_PlayChannel(-1, bang, 1);
									bigfish[i].free();
									bullet.rebullet();
									bullet.x = x2 + 100;
									bullet.y = y2 + 100;
									daban = false;

								}
							}
							for (int i = 0; i < 5; i++)
							{
								if (abs(x - bigfish[i].xk) <= 30 && abs(y - bigfish[i].yk) <= 30 && dem < 20) {
									alive = false;
									lose = false;
								}
							}

							for (int i = 0; i < (int)bigfish.size(); i++)
							{
								for (int j = 0; j < (int)muoito.size(); j++)
								{
									//if (abs(bigfish[i].xk - muoito[j].xk) <= 65 && abs(bigfish[i].yk - muoito[j].yk) <= 65) bigfish_gap_midfish = true;
									if (abs(bigfish[i].xk - muoito[j].xk) <= 50 && abs(bigfish[i].yk - muoito[j].yk) <= 50 && muoito[j].test_alive == 1)
									{
										/*SDL_DestroyTexture(muoito[j].Texmuoi);
										muoito[j].xk = -100;
										muoito[j].yk = -100;*/
										muoito[j].test_alive = 0;
										muoito[j].free();
									}
								}
							}
							for (int i = 0; i < (int)bigfish.size(); i++)
							{
								for (int j = 0; j < (int)muoi.size(); j++)
								{
									//if (abs(bigfish[i].xk - muoito[j].xk) <= 65 && abs(bigfish[i].yk - muoito[j].yk) <= 65) bigfish_gap_midfish = true;
									if (abs(bigfish[i].xk - muoi[j].xk) <= 20 && abs(bigfish[i].yk - muoi[j].yk) <= 20 && muoi[j].test_alive == 1)
									{
										/*SDL_DestroyTexture(muoi[j].Texmuoi);
										muoi[j].xk = -100;
										muoi[j].yk = -100;*/
										muoi[j].test_alive = 0;
										muoi[j].free();
									}
								}
							}
							for (int i = 0; i < (int)muoito.size(); i++)
							{
								for (int j = 0; j < (int)muoi.size(); j++)
								{
									//if (abs(bigfish[i].xk - muoito[j].xk) <= 65 && abs(bigfish[i].yk - muoito[j].yk) <= 65) bigfish_gap_midfish = true;
									if (abs(muoito[i].xk - muoi[j].xk) <= 20 && abs(muoito[i].yk - muoi[j].yk) <= 20 && muoi[j].test_alive == 1)
									{
										/*SDL_DestroyTexture(muoi[j].Texmuoi);
										muoi[j].xk = -100;
										muoi[j].yk = -100;*/
										muoi[j].test_alive = 0;
										muoi[j].free();
									}
								}
							}



							SDL_Delay(20);
							if (dem >= 25)
							{
								win = true;
								alive = false;

							}
							if (win == true) {
								SDL_Rect inwin = { 0,00,SCREEN_WIDTH ,SCREEN_HEIGHT };
								SDL_RenderCopy(gRenderer, Win, NULL, &inwin);
							}
							if (lose == false)
							{
								SDL_Rect inlose = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
								SDL_RenderCopy(gRenderer, Lose, NULL, &inlose);
								alive = false;
							}


							SDL_RenderPresent(gRenderer);
						}
					}
					if (typegame == 1)
					{
						if (pause == false)
						{

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




							SDL_Rect rectmuoi[50];
							int testquaydau[50] = {};
							h1 = (h1 + 1) % 4;
							k1 = (k1 + h1 / 3) % 14;
							for (int i = 0; i < (int)muoi.size(); i++)
							{

								SDL_Rect ca_nho[13];
								for (int k = 0; k < 13; k++)
								{
									ca_nho[k] = { k * 480,0,480,270 };
								}
								if (muoi[i].test_alive == 1 && alive == true)
								{
									if (muoi[i].xk == 1280)
									{
										thu2[i] = 0;
									}
									else if (muoi[i].xk <= 0)
									{
										thu2[i] = 1;
									}
									if (k1 >= 13)
									{
										k1 = 0;
									}
									if (muoi[i].yk >= 700)
									{
										muoi[i].trongmanhinh = false;
									}
									if (muoi[i].yk <= 0)
									{
										muoi[i].trongmanhinh = false;
									}
									if (muoi[i].trongmanhinh == false)
									{

										if (muoi[i].yk >= 700) muoi[i].ykdaptuong = -2;
										if (muoi[i].yk <= 0) muoi[i].ykdaptuong = 2;
									}
									
									 if (thu2[i] == 0)
									{
										rectmuoi[i] = { muoi[i].xk -= (rand() % 3) , muoi[i].yk += canhodichuyen[i].dichuyen, 80, 80 };
										SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, &ca_nho[k1], &rectmuoi[i], NULL, NULL, SDL_FLIP_NONE);
										if (muoi[i].trongmanhinh == false)
										{
											rectmuoi[i] = { muoi[i].xk -= (rand() % 3) , muoi[i].yk += muoi[i].ykdaptuong, 80, 80 };
											SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, &ca_nho[k1], &rectmuoi[i], NULL, NULL, SDL_FLIP_NONE);
											//muoi[i + 1].trongmanhinh = false;
										}


									}
									else if (thu2[i] == 1)
									{
										rectmuoi[i] = { muoi[i].xk += (rand() % 3) ,muoi[i].yk += canhodichuyen[i].dichuyen, 80, 80 };
										SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, &ca_nho[k1], &rectmuoi[i], NULL, NULL, SDL_FLIP_HORIZONTAL);
										if (muoi[i].trongmanhinh == false)
										{
											rectmuoi[i] = { muoi[i].xk += (rand() % 3) , muoi[i].yk += muoi[i].ykdaptuong, 80, 80 };
											SDL_RenderCopyEx(gRenderer, muoi[i].Texmuoi, &ca_nho[k1], &rectmuoi[i], NULL, NULL, SDL_FLIP_HORIZONTAL);
											//muoi[i + 1].trongmanhinh = false;
										}

									}
								}
							}






							SDL_Rect Rectcato[10];

							int ca_to_quay_dau[10] = {};

							h = (h + 1) % 4;
							k = (k + h / 3) % 26;
							for (int i = 0; i < 10; i++)
							{

								SDL_Rect ca_vua[29];
								for (int k = 0; k < 29; k++)
								{
									ca_vua[k] = { k * 480,0,480,480 };
								}

								if (muoito[i].test_alive == 1 && alive == true)
								{
									if (muoito[i].xk == 1280)
									{

										thucato[i] = 0;

									}
									else if (muoito[i].xk <= 0)
									{

										thucato[i] = 1;

									}
									if (k >= 29)
									{
										k = 0;
									}
									
									if (thucato[i] == 0)
									{
										Rectcato[i] = { muoito[i].xk -= 2, muoito[i].yk += 0, 80, 80 };
										SDL_RenderCopyEx(gRenderer, muoito[i].Texmuoi, &ca_vua[k], &Rectcato[i], NULL, NULL, SDL_FLIP_NONE);
									}
									else if (thucato[i] == 1)
									{
										Rectcato[i] = { muoito[i].xk += 2,muoito[i].yk += 0, 80, 80 };
										SDL_RenderCopyEx(gRenderer, muoito[i].Texmuoi, &ca_vua[k], &Rectcato[i], NULL, NULL, SDL_FLIP_HORIZONTAL);

									}
								}


							}

							SDL_Rect Rectbigfish[5];

							int bigfish_quay_dau[5] = {};
							h2 = (h2 + 1) % 4;
							k2 = (k2 + h2 / 3) % 25;

							for (int i = 0; i < 5; i++)
							{
								SDL_Rect ca_to[29];
								for (int k = 0; k < 29; k++)
								{
									ca_to[k] = { k * 480,0,480,345 };
								}

								if (bigfish[i].test_alive == 1 && alive == true)
								{

									if (bigfish[i].xk == 1280)
									{

										thubigfish[i] = 0;

									}
									else if (bigfish[i].xk <= 0)
									{

										thubigfish[i] = 1;

									}

									
									if (thubigfish[i] == 0)
									{
										Rectbigfish[i] = { bigfish[i].xk -= 2, bigfish[i].yk += 0, 150, 150 };
										SDL_RenderCopyEx(gRenderer, bigfish[i].Texmuoi, &ca_to[k2], &Rectbigfish[i], NULL, NULL, SDL_FLIP_NONE);

									}
									else if (thubigfish[i] == 1)
									{
										Rectbigfish[i] = { bigfish[i].xk += 2,bigfish[i].yk += 0, 150, 150 };
										SDL_RenderCopyEx(gRenderer, bigfish[i].Texmuoi, &ca_to[k2], &Rectbigfish[i], NULL, NULL, SDL_FLIP_HORIZONTAL);
									}
								}

							}
							float delta_x;
							float delta_y;
							/*float angle;*/


							SDL_Rect boss;
							
								if (x2 <= 0) {

									thubossquaydau = false;

								}
								if (x2 >= 1280) {

									thubossquaydau = true;
								}
								if (thubossquaydau == false) {
									boss = { x2 += 5, y2 += 0, 200, 200 };
									SDL_RenderCopyEx(gRenderer, Boss, NULL, &boss, NULL, NULL, SDL_FLIP_NONE);
								}
								if (thubossquaydau == true) {
									boss = { x2 -= 5, y2 -= 0, 200, 200 };
									SDL_RenderCopyEx(gRenderer, Boss, NULL, &boss, NULL, NULL, SDL_FLIP_HORIZONTAL);
								}
								if (daban == false) {
									delta_x = X - bullet.x;
									delta_y = Y - bullet.y;
									angle = atan2(delta_y, delta_x);

								}
								daban = true;

								SDL_Rect banbullet;
								banbullet = { bullet.x += 10 * cos(angle), bullet.y += 10 * sin(angle), 30,30 };
								SDL_RenderCopy(gRenderer, Bullet1, NULL, &banbullet);
								if (bullet.y >= 720 || bullet.y <= 0 || bullet.x >= 1280 || bullet.x <= 0)
								{
									bullet.rebullet();
									bullet.x = x2 + 100;
									bullet.y = y2 + 100;
									daban = false;
								}


							


							
							for (int i = 0; i < (int)muoi.size(); i++) {
								if ((int)abs(bullet.x - muoi[i].xk) <= 20 && (int)abs(bullet.y - muoi[i].yk) <= 20 && muoi[i].test_alive == 1 && alive == true)
								{

									/*SDL_DestroyTexture(muoi[i].Texmuoi);
									muoi[i].xk = -100;
									muoi[i].yk = -100;*/
									muoi[i].test_alive = 0;
									if (win == false) Mix_PlayChannel(-1, bang, 1);
									muoi[i].free();
									bullet.rebullet();
									bullet.x = x2 + 100;
									bullet.y = y2 + 100;
									dem += 1;
									daban = false;

								}
							}
							
							for (int i = 0; i < 10; i++) {
								if ((int)abs(bullet.x - muoito[i].xk) <= 50 && (int)abs(bullet.y - muoito[i].yk) <= 50 && muoito[i].test_alive == 1 && alive == true)
								{
									/*SDL_DestroyTexture(muoito[i].Texmuoi);
									muoito[i].xk = -100;
									muoito[i].yk = -100;*/
									muoito[i].test_alive = 0;
									if (win == false) Mix_PlayChannel(-1, bang, 1);
									muoito[i].free();
									bullet.rebullet();
									bullet.x = x2 + 100;
									bullet.y = y2 + 100;
									dem += 1;
									daban = false;
								}
							}
							
							
							for (int i = 0; i < (int)bigfish.size(); i++) {
								if ((int)abs(bullet.x - bigfish[i].xk) <= 50 && (int)abs(bullet.y - bigfish[i].yk) <= 50 && bigfish[i].test_alive == 1 && alive == true)
								{
									/*SDL_DestroyTexture(bigfish[i].Texmuoi);
									bigfish[i].xk = -100;
									bigfish[i].yk = -100;*/
									bigfish[i].test_alive = 0;

									if(win == false) Mix_PlayChannel(-1, bang, 1);
									
									bigfish[i].free();
									bullet.rebullet();
									bullet.x = x2 + 100;
									bullet.y = y2 + 100;
									dem += 1;
									daban = false;

								}
							}
							

							for (int i = 0; i < (int)bigfish.size(); i++)
							{
								for (int j = 0; j < (int)muoito.size(); j++)
								{
									//if (abs(bigfish[i].xk - muoito[j].xk) <= 65 && abs(bigfish[i].yk - muoito[j].yk) <= 65) bigfish_gap_midfish = true;
									if (abs(bigfish[i].xk - muoito[j].xk) <= 50 && abs(bigfish[i].yk - muoito[j].yk) <= 50 && muoito[j].test_alive == 1)
									{
										/*SDL_DestroyTexture(muoito[j].Texmuoi);
										muoito[j].xk = -100;
										muoito[j].yk = -100;*/
										muoito[j].test_alive = 0;
										muoito[j].free();
									}
								}
							}
							for (int i = 0; i < (int)bigfish.size(); i++)
							{
								for (int j = 0; j < (int)muoi.size(); j++)
								{
									//if (abs(bigfish[i].xk - muoito[j].xk) <= 65 && abs(bigfish[i].yk - muoito[j].yk) <= 65) bigfish_gap_midfish = true;
									if (abs(bigfish[i].xk - muoi[j].xk) <= 20 && abs(bigfish[i].yk - muoi[j].yk) <= 20 && muoi[j].test_alive == 1)
									{
										/*SDL_DestroyTexture(muoi[j].Texmuoi);
										muoi[j].xk = -100;
										muoi[j].yk = -100;*/
										muoi[j].test_alive = 0;
										muoi[j].free();
									}
								}
							}
							for (int i = 0; i < (int)muoito.size(); i++)
							{
								for (int j = 0; j < (int)muoi.size(); j++)
								{
									//if (abs(bigfish[i].xk - muoito[j].xk) <= 65 && abs(bigfish[i].yk - muoito[j].yk) <= 65) bigfish_gap_midfish = true;
									if (abs(muoito[i].xk - muoi[j].xk) <= 20 && abs(muoito[i].yk - muoi[j].yk) <= 20 && muoi[j].test_alive == 1)
									{
										/*SDL_DestroyTexture(muoi[j].Texmuoi);
										muoi[j].xk = -100;
										muoi[j].yk = -100;*/
										muoi[j].test_alive = 0;
										muoi[j].free();
									}
								}
							}



							SDL_Delay(20);
							if (dem >= 10)
							{
								win = true;

							}
							if (win == true) {
								SDL_Rect inwin = { 0,00,SCREEN_WIDTH ,SCREEN_HEIGHT };
								SDL_RenderCopy(gRenderer, Win, NULL, &inwin);
							}
							if (lose == false)
							{
								SDL_Rect inlose = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
								SDL_RenderCopy(gRenderer, Lose, NULL, &inlose);
								alive = false;
							}


							SDL_RenderPresent(gRenderer);
						}
					}
				}
			}
		}
	}



	close();

	return 0;
}
