#pragma once
#include "Player.h"
#include "Score.h"
#include <random>


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
	int ballhit_p1 = player.get_p1_posy();
	int ballhit_p2 = player.get_p2_posy();


	bool get_ballrestared() { return ball_restarting; }

	int get_ballsize() const { return ball_sizexy; }
	int get_ballpos_y() const { return ball_posy; }
	int get_ballpos_x() const { return ball_posx; }


private:
	auto randomizer(int init, int end)
	{
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<> range(init, end);

		return range(rng);
	}

private:
	bool initialized = false;
	bool ball_restarting = false;
	void reflect(int axis);
	enum axis { x, y };

private:
	// Drawing related
	static constexpr int ball_sizexy = 10;

	// Movement Related
	static constexpr int init_ball_posx = (Graphics::ScreenWidth / 2) - (ball_sizexy / 2) + 1;
	static constexpr int init_ball_posy = Graphics::ScreenHeight / 2;
	int ball_posx = init_ball_posx;
	int ball_posy = init_ball_posy;
	int ballspeedx = 10;
	int ballspeedy = 10;

	Graphics& gfx;
	Player& player;
	Wall& wall;
};