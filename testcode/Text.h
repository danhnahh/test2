#ifndef TEXT_H_
#define TEXT_H_
//#include "CommonFunc.h"
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

class TextObject
{
public:
	TextObject();
	~TextObject();
	
	enum TextColor {
		RED_TEXT = 0,
		WHITE_TEXT = 0,
		BLACK_TEXT=0,
	};
	bool LoadFromFile(std::string path);
	bool LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen);
	void Free();

	void SetColor(Uint8 red, Uint8 green, Uint8 blue);
	void SetColor(int type);


	void RenderText(SDL_Renderer* screen, int xp, int yp,
					SDL_Rect* clip = NULL,
					double aangle = 0.0,
					SDL_Point* center = NULL, 
					SDL_RendererFlip flip = SDL_FLIP_NONE);
	int GetWidth() const { return width_; }
	int GetHieght() const { return height_; }
	void SetText(const std::string& text) { str_val_ = text; }
	std::string GetText() const { return str_val_; }
private:
	std::string str_val_;
	SDL_Color text_color_;
	SDL_Texture* texture_;
	int width_;
	int height_;
};


#endif