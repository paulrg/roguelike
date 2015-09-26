//
//  draw.h
//  SDL_Caster
//
//  Created by Paul Gage on 12/13/12.
//  Copyright (c) 2012 Paul Gage. All rights reserved.
//

#ifndef __SDL_Caster__draw__
#define __SDL_Caster__draw__

#include <stdio.h>
#include "SDL/SDL.h"
//#include "global.h"


//void DrawPixel(SDL_Surface *screen, int x, int y, Uint8 R, Uint8 G, Uint8 B);
//void DrawLine(int x_i, int y_i, int x_f, int y_f);
void DrawLineRect(SDL_Surface *source, double x_i, double y_i, double x_f, double y_f, int red, int green, int blue);

#endif /* defined(__SDL_Caster__draw__) */
