#pragma once
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Ball.h"
#include "Player.h"
#include "Wall.h"
#include "Score.h"

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();

private:
	void init_anim();

private:
	
	// Player movement variables
	static constexpr int spd = 4;
	static constexpr int boost_init_val = 1;
	static constexpr int boost_lim = 8;
	static constexpr int boost_increaseby_frame = 1;
	int p1boost = boost_init_val;
	int p2boost = boost_init_val;

	// Score variables
	int p_score_increase_rate = 20;

	// Animation variables
	bool animate = false;

	static constexpr int linesize_x = 2;
	static constexpr int lineincrease_by = 8;
	static constexpr Color linecolor = Colors::White;

	int bottomline_initialpos_y = Graphics::ScreenHeight / 2;
	int bottomline_sizey = 0;
	int bottomline_pos_x = Graphics::ScreenWidth / 2;
	int bottomline_enddraw_y = Graphics::ScreenHeight - 15 * 2;

	int x = (Graphics::ScreenWidth / 2) + 2;
	int y = Graphics::ScreenHeight / 2;
	int sx = x - 2;
	int sy = y;

	// Class Variables Initiators
	MainWindow & wnd;
	Graphics gfx;
	Mouse mouse;
	Wall wall;
	Player player;
	Ball ball;
	Score score;
};