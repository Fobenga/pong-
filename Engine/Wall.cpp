#include "Wall.h"

Wall::Wall(Graphics& gfx)
	:
	gfx(gfx)
{}

void Wall::DrawWall()
{
	// Top wall
	gfx.DrawRect(wall_posx, wall_posy, wallx_size, wall_width);

	// Left wall
	gfx.DrawRect(wall_posx, wall_posy, wall_width, wally_size - wall_posx);
	
	// Right wall
	gfx.DrawRect(wallx_size + wall_width, wall_posy, wall_width, wally_size - wall_posx);
	
	// Bottom wall
	gfx.DrawRect(wall_posx, wally_size, wallx_size, wall_width);
}