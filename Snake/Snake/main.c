#include "raylib.h"
#include "stdio.h"
#include "stdlib.h"

#include "snake.h"

#define MENU   5

typedef enum GameScreen { menuScreen = 0, gameScreen, endScreen } GameScreen;

static const char* MENU_POSS[] = {
	"LEVEL:",
	"FIRST",
	"SECOND",
	"THIRD",
	"PLAY"
};

int main(void)
{
	const int screenWidth = 1280;
	const int screenHeight = 720;
	const char* fileNameGrass = "3.png";
	int xPos = 0;
	int yPos = 60;
	int widthGrass = 30;
	int heightGrass = 30;


	int currentProcess = 0;
	bool textureReload = false;

	InitWindow(screenWidth, screenHeight, "basic window");
	GameScreen currentScreen = menuScreen;


	SetTargetFPS(60);

	Texture2D textureOfGrass = LoadTexture(fileNameGrass);

	int textureWidth = textureOfGrass.width;
	int textureHeight = textureOfGrass.height;
	int field_width = 8;
	int field_height = 8;

	Rectangle toggleRecs[MENU] = { 0 };
	int mouseHoverRec = -1;

	for (int i = 0; i < MENU; i++) toggleRecs[i] = (Rectangle){ 40.0f, (float)(50 + 32 * i), 150.0f, 30.0f };

	SetTargetFPS(60);

	// Mouse control
	/*for (int i = 0; i < MENU_POSS; i++)
	{
		if (CheckCollisionPointRec(GetMousePosition(), toggleRecs[i]))
		{
			mouseHoverRec = i;

			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
			{
				currentProcess = i;
				textureReload = true;
			}
			break;
		}
		else mouseHoverRec = -1;
	}*/

	// Keyboard control
	if (IsKeyPressed(KEY_DOWN))
	{
		currentProcess++;
		if (currentProcess > (MENU_POSS - 1)) currentProcess = 0;
		textureReload = true;
	}
	else if (IsKeyPressed(KEY_UP))
	{
		currentProcess--;
		if (currentProcess < 0) currentProcess = 7;
		textureReload = true;
	}


	while (!WindowShouldClose())
	{
		switch (currentScreen)
		{
		case menuScreen:
		{
			BeginDrawing();
			ClearBackground(LIME);
			DrawText("M E N U", (screenWidth / 2) - 100, 50, 40, DARKGREEN);

			for (int i = 0; i < MENU; i++)
			{
				DrawRectangleRec(toggleRecs[i], ((i == currentProcess) || (i == mouseHoverRec)) ? SKYBLUE : LIGHTGRAY);
				DrawRectangleLines((int)toggleRecs[i].x, (int)toggleRecs[i].y, (int)toggleRecs[i].width, (int)toggleRecs[i].height, ((i == currentProcess) || (i == mouseHoverRec)) ? BLUE : GRAY);
				DrawText(MENU_POSS[i], (int)(toggleRecs[i].x + toggleRecs[i].width / 2 - MeasureText(MENU_POSS[i], 10) / 2),
					(int)toggleRecs[i].y + 11, 10, ((i == currentProcess) || (i == mouseHoverRec)) ? DARKBLUE : DARKGRAY);
			}
			if ((IsKeyPressed(KEY))
			{

			}




			EndDrawing();
		} break;


				//case TITLE:
				//{
				//	// TODO: Update TITLE screen variables here!

				//	// Press enter to change to GAMEPLAY screen
				//	if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
				//	{
				//		currentScreen = GAMEPLAY;
				//	}
				//} break;
				//case GAMEPLAY:
				//{
				//	// TODO: Update GAMEPLAY screen variables here!

				//	// Press enter to change to ENDING screen
				//	if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
				//	{
				//		currentScreen = ENDING;
				//	}
				//} break;


				/*ClearBackground(GREEN);

				DrawText("S N A K E", (screenWidth / 2) - 100, 50, 40, DARKGREEN);
				for (int i = 0; i < screenWidth;i += textureWidth)
				{
					for (int j = 80; j < screenHeight; j += textureHeight)
					{
						DrawTexture(textureOfGrass, xPos + i, yPos + j, GREEN);
					}
				}*/

				/*	EndDrawing();

					}*/
				return 0;
		}
	}
}

void drawGrass(const char* fileNameGrass)
{
	DrawText("S N A K E", (screenWidth / 2) - 100, 50, 40, DARKGREEN);
	for (int i = 0; i < screenWidth;i += textureWidth)
	{
		for (int j = 80; j < screenHeight; j += textureHeight)
		{
			DrawTexture(textureOfGrass, xPos + i, yPos + j, GREEN);
		}
	}*/
}