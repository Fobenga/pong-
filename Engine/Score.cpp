#include "Score.h"

Score::Score(Graphics & gfx, Player& player, Wall& wall)
	:
	gfx(gfx),
	player(player),
	wall(wall)
{}

void Score::DrawScore()
{
	// Score 1 Drawing
	gfx.DrawRect(wall.get_wallls(), wall.get_topwall_y(),
				 player.get_p1_score(),
				 Graphics::ScreenHeight - wall.get_topwall_y() - wall.get_wall_width() - sc_padding_from_wall,
				 current_p1_scorecolor);

	// Score 2 Drawing
	gfx.DrawRectRev(Graphics::ScreenWidth - 15, wall.get_topwall_y(),
					Graphics::ScreenWidth - player.get_p2_score() - 15,
					Graphics::ScreenHeight - 15,
					current_p2_scorecolor);

	
	// Restart both score if reaches mid screen
	if((player.get_p1_score() > (Graphics::ScreenWidth / 2) - 20) ||
	   player.get_p2_score() > (Graphics::ScreenWidth / 2) - 20)
		player.set_increaser(false);
	else
		player.set_increaser(true);
}
