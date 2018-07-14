#pragma once
#include "Graphics.h"
#include "Player.h"
#include "Wall.h"

class Score
{
public:
	Score(Graphics& gfx, Player& player, Wall& wall);
	void DrawScore();

private:
	void score1_drawing();
	void score2_drawing();

private:
	static constexpr Color score_color = { 50,50,50 };
	static constexpr int sc_padding_from_wall = 10;
	int sc_sizey = Graphics::ScreenHeight;
	
	Color current_p1_scorecolor = Colors::Red;
	Color current_p2_scorecolor = Colors::Green;
	static constexpr Color p_equality_color = Colors::Gray;

private:
	Graphics& gfx;
	Player& player;
	Wall& wall;
}; 