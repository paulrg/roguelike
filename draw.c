//
//  draw.cpp
//  SDL_Caster
//
//  Created by Paul Gage on 12/13/12.
//  Copyright (c) 2012 Paul Gage. All rights reserved.
//

#include "draw.h"

// void DrawPixel(SDL_Surface *screen, int x, int y, Uint8 R, Uint8 G, Uint8 B)
// {
    // Uint32 color = SDL_MapRGB(screen->format, R, G, B);
    
    // if ( SDL_MUSTLOCK(screen) ) {
        // if ( SDL_LockSurface(screen) < 0 ) {
            // return;
        // }
    // }
    
    // Uint32 *bufp;
    
    // bufp = (Uint32 *)screen->pixels + y*screen->pitch/4 + x;
    // *bufp = color;
    
    
    // if ( SDL_MUSTLOCK(screen) ) {
        // SDL_UnlockSurface(screen);
    // }
    // SDL_UpdateRect(screen, x, y, 1, 1);
// }

// void DrawLine(int x_i, int y_i, int x_f, int y_f)
// {
    // int i;
    // for (i = y_i; i < y_f; i++)
    // {
        // DrawPixel(screen, x_i, i, 200, 200, 200);
    // }
// }

void DrawLineRect(SDL_Surface *source, double x_i, double y_i, double x_f, double y_f, int red, int green, int blue)
{
	SDL_Rect rect = {(Sint16)(x_i),(Sint16)(y_i),(Uint16)(x_f - x_i),(Uint16)(y_f - y_i)};
    SDL_FillRect(source, &rect, SDL_MapRGB(source->format, red, green, blue));
}