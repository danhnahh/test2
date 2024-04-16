#pragma once
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>


static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;
SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

SDL_Texture* Boss = NULL;
SDL_Texture* gTexture = NULL;
SDL_Texture* gTexture1 = NULL;
SDL_Texture* gTexture2 = NULL;
SDL_Texture* gTexture3 = NULL;
SDL_Texture* Win = NULL;
SDL_Texture* Lose = NULL;
SDL_Texture* startmenu = NULL;
SDL_Texture* Pause = NULL;
SDL_Texture* Bullet1 = NULL;
SDL_Texture* Type = NULL;
SDL_Texture* Type1 = NULL;
SDL_Texture* Type2 = NULL;
SDL_Texture* Type3 = NULL;

SDL_RendererFlip fliptype = SDL_FLIP_NONE;

SDL_RendererFlip fliptype1;

SDL_RendererFlip fliptypecato;

Mix_Music* music;
Mix_Music* daddy;
Mix_Chunk* eatlevel1;
Mix_Chunk* eatlevel2;
Mix_Chunk* eatlevel3;
Mix_Chunk* bang;
//screen
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;
const int RENDER_DRAW_COLOR = 0XFF;

#endif
