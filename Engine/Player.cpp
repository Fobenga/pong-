#include "Player.h"

Player::Player(Graphics & c_gfx, Wall c_wall)
	:
	gfx(c_gfx),
	wall(c_wall)
{}

void Player::DrawPlayers()
{
	// Verify collisions
	WallCollision();

	// p1 drawing 
	gfx.DrawRect(p1_posx, p1_posy, p_sizex, p_sizey);

	// p2 drawing
	gfx.DrawRect(p2_posx, p2_posy, p_sizex, p_sizey);
}

void Player::WallCollision()
{
	// Player 1 wall collision
	if(p1_posy <= wall.get_topwall_y())
		p1_posy = wall.get_topwall_y();

	if(p1_posy + p_sizey >= wall.get_bottomwall_y())
		p1_posy = wall.get_bottomwall_y() - p_sizey;

	// Player 2 wall collision
	if(p2_posy <= wall.get_topwall_y())
		p2_posy = wall.get_topwall_y();

	if(p2_posy + p_sizey >= wall.get_bottomwall_y())
		p2_posy = wall.get_bottomwall_y() - p_sizey;
}

void Player::set_increaser(bool value)
{
	if(value)
		score_increasing = true;
	else 
		score_increasing = false;
}

void Player::set_p1_score(int increase_by)
{
	if(score_increasing)
		p1_score += increase_by;
	else p1_score = 0;
}

void Player::set_p2_score(int increase_by)
{
	if(score_increasing)
		p2_score += increase_by;
	else p2_score = 0;
}

int Player::get_p1_posx()
{
	return p1_posx;
}

int Player::get_p1_posy()
{
	return p1_posy;
}

int Player::get_p2_posx()
{
	return p2_posx;
}

int Player::get_p2_posy()
{
	return p2_posy;
}

int Player::get_p_sizey()
{
	return p_sizey;
}

int Player::get_p_sizex()
{
	return p_sizex;
}
