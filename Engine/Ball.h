#pragma once
#include "Player.h"
#include "Score.h"

class Ball
{
public:
	Ball(Graphics& gfx, Player& player, Wall& wall);

	void DrawBall();
	void BallBehavior();
	void WallCollision();
	void PlayerCollision();

	bool initialize_ball();
	bool restart_ball();

public:
	int get_ballsize() const { return ball_sizexy; }

private:
	bool initialized = false;
	void reflect(int axis);
	enum axis { x, y };

private:
	// Drawing related
	static constexpr int ball_sizexy = 10;

	// Movement Related
	static constexpr int init_ball_posx = Graphics::ScreenWidth / 2;
	static constexpr int init_ball_posy = Graphics::ScreenHeight / 2;
	int ball_posx = init_ball_posx;
	int ball_posy = init_ball_posy;
	int ballspeedx = 5;
	int ballspeedy = 5;

	Graphics& gfx;
	Player& player;
	Wall& wall;
};