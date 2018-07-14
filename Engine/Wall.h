#pragma once
#include "Graphics.h"

class Wall
{
public:
	Wall(Graphics& gfx);
	void DrawWall();

public:
	// Getters
	int get_wallls() const { return wall_posx + wall_width; }
	int get_wallrs() const { return wallx_size; }

	int get_topwall_y() const { return wall_posy; }
	int get_bottomwall_y() const { return wally_size; }

	int get_wall_posxy() const { return wall_posx; }

	int get_wall_width() const { return wall_width; }

private:
	Graphics & gfx;

	// Positioning
	static constexpr int wall_posx = 10;
	static constexpr int wall_posy = wall_posx;

	// Drawing 
	static constexpr int wallx_size = Graphics::ScreenWidth - wall_posx * 2;
	static constexpr int wally_size = Graphics::ScreenHeight - wall_posy * 2;
	static constexpr int wall_width = 5;

};