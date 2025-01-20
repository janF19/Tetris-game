


#include <raylib.h>
#include "Game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;
bool EventTriggered(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}


int main() 
{	
	
	InitWindow(500, 620, "Tetris");
	SetTargetFPS(60); //runs same on every computer

	Font font = LoadFontEx("Font/modern-tetris.ttf", 64, 0, 0);
	Game game = Game();

	


	//ends if esc is pressed
	//game loop is executed 60 times per second - so every method is executed that many times, need to slow is down so that block falls slower eg call down every 200 miliseconds
	while (WindowShouldClose() == false)
	{
		game.HandleInput();
		if (EventTriggered(0.2)) {
			game.MoveBlockDown();

		}
		

		BeginDrawing();
		ClearBackground(darkBlue);
		DrawTextEx(font, "Score", { 365, 15 }, 38, 2, WHITE);
		DrawTextEx(font, "Next", { 370, 175 }, 38, 2, WHITE);
		if (game.gameOver)
		{
			DrawTextEx(font, "GAME OVER", { 320, 450 }, 38, 2, WHITE);
		}
		
		DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, lightBlue);

		char scoreText[10];
		sprintf_s(scoreText, "%d", game.score);
		Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
		

		DrawTextEx(font, scoreText, { 320 + (170 - textSize.x)/2, 65}, 38, 2, WHITE);
		DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, lightBlue);
		game.Draw();

		EndDrawing();

	}

	CloseWindow();




}