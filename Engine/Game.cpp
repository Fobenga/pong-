#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	wall(gfx),
	player(gfx, wall),
	ball(gfx, player, wall),
	score(gfx, player, wall)
{}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	/*
		=== Players input ===

	Player 1:
	W - Up
	S - Down
	SHIFT - Boost

	Player 2:
	UP ARROW - Up
	DOWN ARROW  - Down
	END - boost

	*/

	// Player 1 input
	if(wnd.kbd.KeyIsPressed('W')) // up movement
		player.p1_posy -= spd * p1boost;

	if(wnd.kbd.KeyIsPressed('S')) // dowm movement
		player.p1_posy += spd * p1boost;

	if(wnd.kbd.KeyIsPressed(VK_SHIFT)) // boost
	{
		p1boost += boost_increaseby_frame;
		if(p1boost >= boost_lim)
			p1boost = boost_lim;
	}
	else p1boost = boost_init_val;
	// ========================

	// Player 2 input
	if(wnd.kbd.KeyIsPressed(VK_UP)) // up movement
		player.p2_posy -= spd + p2boost;

	if(wnd.kbd.KeyIsPressed(VK_DOWN)) // down movement
		player.p2_posy += spd + p2boost;

	if(wnd.kbd.KeyIsPressed(VK_END)) // boost
	{
		p2boost += boost_increaseby_frame;
		if(p2boost >= boost_lim)
			p2boost = boost_lim;
	}
	else p2boost = boost_init_val;
	// ========================

	// For debug only (comment this to compile the release version)
	// if(wnd.kbd.KeyIsPressed('X'))
	// 	wnd.Kill();
	// 
	// if(wnd.kbd.KeyIsPressed('N'))
	// 	player.set_p1_score(20);
	// 
	// if(wnd.kbd.KeyIsPressed('M'))
	// 	player.set_p2_score(20);

	// Ball related
	if(wnd.kbd.KeyIsPressed(VK_RETURN))
		animate = true;

	if(wnd.kbd.KeyIsPressed('R'))
		ball.restart_ball();
	// ========================

	// Temporary player self movement
	//player.p1_posy = ball.get_ballpos_y() - player.get_p_sizey() / 2;
	// player.p2_posy = ball.get_ballpos_y() - player.get_p_sizey() / 2;

// Game starts
}

void Game::init_anim()
{
	if(animate)
	{

		// Line going down
		if(bottomline_sizey >= bottomline_enddraw_y / 2)
			bottomline_sizey = bottomline_enddraw_y / 2;
		else
			bottomline_sizey += lineincrease_by;

		gfx.DrawRect(bottomline_pos_x, bottomline_initialpos_y, linesize_x, bottomline_sizey, linecolor);
		// Line going up
		if(y <= 15)
		{
			y = 15;
			animate = false;
			if(!ball.get_ballrestared())
				ball.initialize_ball();
		}
		else
			y -= lineincrease_by;

		gfx.DrawRectRev(x, y, sx, sy, linecolor);
	}

	if(!animate)
	{
		gfx.DrawRectRev(x, y, sx, sy, linecolor);
		gfx.DrawRect(bottomline_pos_x, bottomline_initialpos_y, linesize_x, bottomline_sizey, linecolor);
	}

}

void Game::ComposeFrame()
{
	score.DrawScore();
	ball.DrawBall();
	player.DrawPlayers();
	wall.DrawWall();
	init_anim();
}
