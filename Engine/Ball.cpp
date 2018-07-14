#include "Ball.h"

Ball::Ball(Graphics& gfx, Player& player, Wall& wall)
	:
	gfx(gfx),
	player(player),
	wall(wall)
{}

void Ball::DrawBall()
{
	BallBehavior();
	WallCollision();
	PlayerCollision();
	gfx.DrawRect(ball_posx, ball_posy, ball_sizexy, ball_sizexy);
}

bool Ball::initialize_ball()
{
	if (!initialized)
	{
		initialized = true;
		return initialized;
	}

	return false;
}

bool Ball::restart_ball()
{
	if (initialized)
	{
		ball_posx = init_ball_posx;
		ball_posy = init_ball_posy;

		initialized = false;
		return initialized;
	}

	return false;
}

void Ball::BallBehavior()
{
	if (initialized)
	{
		ball_posx += ballspeedx;
		ball_posy += ballspeedy;
	}
}

void Ball::reflect(int axis)
{
	if (axis == axis::x)
		ballspeedx *= -1;

	if (axis == axis::y)
		ballspeedy *= -1;
}

void Ball::WallCollision()
{
	// If balls hit top wall
	if (ball_posy <= wall.get_topwall_y())
	{
		reflect(y);
	}
	// If balls hit bottom wall
	if (ball_posy + ball_sizexy >= wall.get_bottomwall_y())
	{
		reflect(y);
	}

	// If balls hit left wall (p2 score+ / p1 score-)
	if (ball_posx <= wall.get_wallls())
	{
		player.set_p2_score(20);
		restart_ball();
	}

	// If balls hit right wall (p1 score+ / p2 score-)
	if (ball_posx >= wall.get_wallrs())
	{
		player.set_p1_score(20);
		restart_ball();
	}
}

void Ball::PlayerCollision()
{
	// P1 Collision
	if ((ball_posx <= player.get_p1_posx() + player.get_p_sizex()) &&
		(ball_posy >= player.p1_posy &&
			ball_posy <= player.p1_posy + player.get_p_sizey()))
	{
		reflect(x);
	}

	// P2 Collision
	if ((ball_posx >= player.get_p2_posx() - player.get_p_sizex()) &&
		(ball_posy >= player.p2_posy &&
			ball_posy <= player.p2_posy + player.get_p_sizey()))
	{
		reflect(x);
	}
}

