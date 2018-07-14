#include "Score.h"

Score::Score(Graphics & gfx, Player& player, Wall& wall)
	:
	gfx(gfx),
	player(player),
	wall(wall)
{}

void Score::DrawScore()
{

	if (player.get_p1_score() <= player.get_p2_score())
	{
		score2_drawing();
		score1_drawing();
	}
	else if (player.get_p2_score() <= player.get_p1_score())
	{
		score1_drawing();
		score2_drawing();
	}

	if (player.get_p1_score() == player.get_p2_score())
	{
		current_p1_scorecolor = p_equality_color;
		current_p2_scorecolor = current_p1_scorecolor;
	}
	else
	{
		current_p1_scorecolor = Colors::Red;
		current_p2_scorecolor = Colors::Green;
	}
}

void Score::score1_drawing()
{
	gfx.DrawRect(wall.get_wallls(), wall.get_topwall_y(), player.get_p1_score(),
		Graphics::ScreenHeight - wall.get_topwall_y() - wall.get_wall_width() - sc_padding_from_wall,
		current_p1_scorecolor);
}

void Score::score2_drawing()
{
	gfx.DrawRect(wall.get_wallls(), wall.get_topwall_y(), player.get_p2_score(),
		Graphics::ScreenHeight - wall.get_topwall_y() - wall.get_wall_width() - sc_padding_from_wall,
		current_p2_scorecolor);
}
