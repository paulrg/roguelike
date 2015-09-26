#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL/SDL.h"
#include "globaldefs.h"
#include "draw.h"
#include "generator.h"


// function prototypes
SDL_Surface* init_screen(const int width, const int height, const int bpp);
void spawn_player(int x, int y, int map[MAPX][MAPY]);
void scan_map(SDL_Surface* screen, int map[MAPX][MAPY]);
void check_keypress(SDL_Event event, int* movingup, int* movingdown, int* movingleft, int* movingright, int* quit);
void move_player_up(int* playerx, int* playery, int map[MAPX][MAPY]);
void move_player_down(int* playerx, int* playery, int map[MAPX][MAPY]);
void move_player_left(int* playerx, int* playery, int map[MAPX][MAPY]);
void move_player_right(int* playerx, int* playery, int map[MAPX][MAPY]);


// Initialize SDL and a screen pointer, return the pointer
SDL_Surface* init_screen(const int width, const int height, const int bpp)
{
		SDL_Surface* screen = NULL;
		SDL_Init( SDL_INIT_EVERYTHING);
		// Uncomment to have console output, but it closes cmd prompt for some reason
		// freopen( "CON", "w", stdout );
		// freopen( "CON", "w", stderr );
		screen = SDL_SetVideoMode(width, height, bpp, SDL_SWSURFACE);
		return screen;

}

// spawn the player on the map
void spawn_player(int x, int y, int map[MAPX][MAPY])
{
	if (map[y][x] == 0)
	{
		map[y][x] = 2;
	}
}

// Scan the map and draw
void scan_map(SDL_Surface* screen, int map[MAPX][MAPY])
{

	int i, j;
	int scalerx = 0;
	int scalery = 0;
	
	for (i = 0; i < MAPX; i++)
	{
		for (j = 0; j < MAPY; j++)
		{
			printf("scalerx: %d \t scalery: %d\n",scalerx, scalery);
			// block value 0 = open area
			if (map[i][j] == 0)
			{
				DrawLineRect(screen, j+scalerx, i+scalery, j+scalerx+BLOCKHEIGHT, i+scalery+BLOCKWIDTH, 255, 120, 60);
			}
			// block value 1 = wall
			else if (map[i][j] == 1)
			{
				DrawLineRect(screen, j+scalerx, i+scalery, j+scalerx+BLOCKHEIGHT, i+scalery+BLOCKWIDTH, 100, 100, 100);
			}
			// block value 2 = player
			else if (map[i][j] == 2)
			{
				DrawLineRect(screen, j+scalerx, i+scalery, j+scalerx+BLOCKHEIGHT, i+scalery+BLOCKWIDTH, 0, 102, 0);
			}
			else
			{
			
			}
			scalerx = scalerx+BLOCKWIDTH;
		}
		scalerx = 0;
		scalery = scalery+BLOCKHEIGHT;
		
	}

}

// Checks for key presses. Modifies movement toggle variables if movement keys are pressed. Also toggles quit variable
// if the user closes the window or press q
void check_keypress(SDL_Event event, int* moving_up, int* moving_down, int* moving_left, int* moving_right, int* quit)
{

// If there are events to handle
        if (SDL_PollEvent(&event))
        {
            // KeyDown events: These events occur when the key is pressed down. For movement this activates
            // a movement variable, in order to allow movement to keep occuring while the key is held down.
            
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_UP:
                        *moving_up = 1;
                        break;	
                    case SDLK_DOWN:
                        *moving_down = 1;
                        break;
                    case SDLK_LEFT:
                        *moving_left = 1;
                        break;
                    case SDLK_RIGHT:
                        *moving_right = 1;
                        break;
					case SDLK_q:
						*quit = 1;
						break;
					default:
						printf("An invalid key was enterred\n");
						break;
				}
			}
			if (event.type == SDL_KEYUP)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_UP:
                        *moving_up = 0;
                        break;
                    case SDLK_DOWN:
                        *moving_down = 0;
                        break;
                    case SDLK_LEFT:
                        *moving_left = 0;
                        break;
                    case SDLK_RIGHT:
                        *moving_right = 0;
                        break;
                    default:
                        break;
                }
			}
           // If user has closed window
            if (event.type == SDL_QUIT)
            {
                // Quit
                *quit = 1;
            }
		}	
}


// player movement functions
// check player position against boundaries so we cannot access outside an array
void move_player_up(int* playerx, int* playery, int map[MAPX][MAPY])
{

	if (map[*playery-1][*playerx] == 0 && *playery -1 < MAPY && *playery - 1 > 0)
	{
		map[*playery-1][*playerx] = 2;
		map[*playery][*playerx] = 0;
		*playery = *playery - 1;
	}

}
void move_player_down(int* playerx, int* playery, int map[MAPX][MAPY])
{

	if (map[*playery+1][*playerx] == 0 && *playery +1 < MAPY && *playery +1 > 0)
	{
		map[*playery+1][*playerx] = 2;
		map[*playery][*playerx] = 0;
		*playery = *playery + 1;
	}


}
void move_player_left(int* playerx, int* playery, int map[MAPX][MAPY])
{

	if (map[*playery][*playerx-1] == 0 && *playerx -1 < MAPX && *playerx - 1 > 0)
	{
		map[*playery][*playerx-1] = 2;
		map[*playery][*playerx] = 0;
		*playerx = *playerx - 1;
	}


}
void move_player_right(int* playerx, int* playery, int map[MAPX][MAPY])
{

	if (map[*playery][*playerx+1] == 0 && *playerx + 1 < MAPY && *playerx + 1 > 0)
	{
		map[*playery][*playerx+1] = 2;
		map[*playery][*playerx] = 0;
		*playerx = *playerx + 1;
	}


}



int main(int argc, char* args[])
{
	// array of a level map
	int level_map[MAPX][MAPY];
	
	// generate map environment
	map_generate(level_map);
	
	// initial player tile position
	int playerx = 0;
	int playery = 0;
	
	// generate some random player positions within the walls
	srand (time(NULL));
	playerx = rand() % (MAPX - 2) + 1;
	playery = rand() % (MAPY - 2) + 1;
	
	spawn_player(playerx, playery, level_map);

	// Main window properties
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const int SCREEN_BPP = 32;
		
	// Call sdl init and create screen
	SDL_Surface* screen = init_screen(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);
	
	// Scan map and draw to screen
	scan_map(screen, level_map);
	
	// Refresh screen
	SDL_Flip(screen);

	// Create sdl event
	SDL_Event event;	
	
	// create a variable that decides whether the user wants to quit or not
	// 0 == no quit, 1 == quit
	int quit = 0;
	
	// movement toggle variables
	int moving_up = 0;
	int moving_left = 0;
	int moving_right = 0;
	int moving_down = 0;
	
	while (quit == 0)
	{
	
		// check for key presses. function also checks whether user closed the window 
		
		check_keypress(event, &moving_up, &moving_down, &moving_left, &moving_right, &quit);
		

		// Check whether the player is moving
		if (moving_up == 1)
		{
			move_player_up(&playerx, &playery, level_map);
		}
		if (moving_down == 1)
		{
			move_player_down(&playerx, &playery, level_map);
		}
		if (moving_left == 1)
		{
			move_player_left(&playerx, &playery, level_map);
		}
		if (moving_right == 1)
		{
			move_player_right(&playerx, &playery, level_map);
		}
		
		
		// scan the map and draw
		scan_map(screen, level_map);

		// refresh the screen
		SDL_Flip(screen);
	
		// delay
		SDL_Delay(FRAMEDELAY);
	}
		
	SDL_Quit();
	
	return 0;
}
