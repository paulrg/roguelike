// generator.c

#include "generator.h"

// generate map

void map_generate(int maparray[][MAPX])
{
	int i, j;
	
	// First generate all tiles as open spaces
	// This could be made more efficient later since it is kinda redundant
	for (i = 0; i < MAPY; i++)
	{
		for (j = 0; j < MAPX; j++)
		{
			maparray[i][j] = 0;
		}
	}
	
	// Now generate a wall around the map
	
	// top wall
	for (i = 0; i < MAPX; i++)
	{
		maparray[0][i] = 1;
	}
	
	//bottom wall
	for (i = 0; i < MAPX; i++)
	{
		maparray[MAPY-1][i] = 1;
	}
	
	//left wall
	for (j = 0; j < MAPY; j++)
	{
		maparray[j][0] = 1;
	}
	
	//right wall
	for (j = 0; j < MAPY; j++)
	{
		maparray[j][MAPX-1] = 1;
	}
	
	//
	// Random generation section
	//
	// Generate a random number of "seeds." Then these seeds will randomly be a different entity type, such as
	// a wall, item, monster, etc.
	//
	// Ideas:
	// - A wall seed could have a random type of "outgrowth." Would need to make sure it's impossible
	// to trap player
	
	int num_seeds = 0;
	num_seeds = rand() % 10 + 1;
	
	
	
	
	
	
}
