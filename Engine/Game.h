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

	// Player movement 
	static constexpr int spd = 2;
	static constexpr int boost_init_val = 1;
	static constexpr int boost_lim = 4;
	static constexpr int boost_increaseby_frame = 1;
	int p1boost = boost_init_val;
	int p2boost = boost_init_val;

	int p_score_increase_rate = 20;

	// Class Variables Initiators
	MainWindow & wnd;
	Graphics gfx;
	Wall wall;
	Player player;
	Ball ball;
	Score score;
};