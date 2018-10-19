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
	static constexpr Color score_color = { 100,100,100 };
	static constexpr int sc_padding_from_wall = 10;
	int sc_sizey = Graphics::ScreenHeight;

	static constexpr Color main_p1_scorecolor = { 100,50,50 };
	static constexpr Color main_p2_scorecolor = { 50,50,100 };

	Color current_p1_scorecolor = main_p1_scorecolor;
	Color current_p2_scorecolor = main_p2_scorecolor;

	static constexpr Color p_equality_color = Colors::Gray;

private:
	Graphics& gfx;
	Player& player;
	Wall& wall;
};