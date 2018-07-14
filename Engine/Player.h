#pragma once
#include "Wall.h"

class Player
{
public:
	Player(Graphics& c_gfx, Wall c_wall);
	void DrawPlayers();
	void WallCollision();

private:
	static constexpr int p_sizex = 10;
	static constexpr int p_sizey = 70;

	static constexpr int padding = 10;
	const int p1_posx = wall.get_wallls() + padding;
	const int p2_posx = wall.get_wallrs() - padding;

	static constexpr int players_initial_ypos = Graphics::ScreenHeight / 2;

public:
	int p1_posy = players_initial_ypos;
	int p2_posy = players_initial_ypos;

private:
	int p1_score = 0;
	int p2_score = 0;

public:
	int get_p1_score() { return p1_score; };
	int get_p2_score() { return p2_score; };
	void set_p1_score(int increase_by);
	void set_p2_score(int increase_by);

	int get_p1_posx();
	int get_p2_posx();

	int get_p_sizey();
	int get_p_sizex();

private:
	Graphics & gfx;
	Wall& wall;

};