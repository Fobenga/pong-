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

	// Draw ball
	gfx.DrawRect(ball_posx, ball_posy, ball_sizexy, ball_sizexy);
}

bool Ball::initialize_ball()
{
	if(!initialized)
	{
		initialized = true;
		ball_restarting = false;
		return initialized;
	}
	return false;
}

bool Ball::restart_ball()
{
	auto random = randomizer(-1, 1);
	if(random != 0)
	{
		ballspeedx *= random;
		ballspeedy = randomizer(2, 10) * random;
	}

	ball_restarting = true;
	if(initialized)
	{
		ball_posx = init_ball_posx;
		ball_posy = randomizer(25, Graphics::ScreenHeight - 25);

		// initialized = false;
		return initialized;
	}
	return false;
}

void Ball::BallBehavior()
{
	if(initialized)
	{
		ball_posx += ballspeedx;
		ball_posy += ballspeedy;
	}
	else
	{
		ball_posx = init_ball_posx;
		const int rand_init = randomizer(25, Graphics::ScreenHeight - 25);
		ball_posy = rand_init;
	}

}

void Ball::reflect(int axis)
{
	if(axis == axis::x)
	{
		ballspeedx *= -1;

		// Randomize the angle
		ballspeedy = randomizer(2, 10);
	}

	if(axis == axis::y)
		ballspeedy *= -1;
}

void Ball::WallCollision()
{
	// If balls hit top wall
	if(ball_posy <= wall.get_topwall_y())
	{
		reflect(y);
	}
	// If balls hit bottom wall
	if(ball_posy + ball_sizexy >= wall.get_bottomwall_y())
	{
		reflect(y);
	}

	// If balls hit left wall (p2 score+)
	if((ball_posx <= wall.get_wallls()))
	{
		player.set_p2_score(20);
		restart_ball();
	}
	else ball_restarting = false;

	// If balls hit right wall (p1 score+)
	if(ball_posx >= wall.get_wallrs())
	{
		player.set_p1_score(20);
		restart_ball();
	}
	else ball_restarting = false;
}

void Ball::PlayerCollision()
{
	// P1 Smart collider
	if(ball_posx <= player.get_p1_posx() + player.get_p_sizex() &&
	   ball_posy >= (player.p1_posy))
	{
		if(ball_posy <= player.p1_posy + (player.get_p_sizey() / 2))
		{
			reflect(x);
			if(ballspeedy > 0)
				reflect(y);
		}

		if(ball_posy >= player.p1_posy + (player.get_p_sizey() / 2) &&
		   ball_posy <= player.p1_posy + player.get_p_sizey())
		{
			reflect(x);
			if(ballspeedy < 0)
				reflect(y);
		}
	}

	// P2 Smart collider
	if(ball_posx >= player.get_p2_posx() - player.get_p_sizex() &&
	   ball_posy >= (player.p2_posy))
	{
		if(ball_posy <= player.p2_posy + (player.get_p_sizey() / 2))
		{
			reflect(x);
			if(ballspeedy > 0)
				reflect(y);
		}

		if(ball_posy >= player.p2_posy + (player.get_p_sizey() / 2) &&
		   ball_posy <= player.p2_posy + player.get_p_sizey())
		{
			reflect(x);
			if(ballspeedy < 0)
				reflect(y);
		}
	}

}

