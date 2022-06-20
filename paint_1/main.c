#include "raylib.h"

#define MaxColorsCount 6          

void Cleaning_Button(bool buttonAction, int buttonState, Vector2 mousePos, Rectangle btnBoundsCleaning, Rectangle colorsRecs, int colorMouseHover, RenderTexture2D target)
{
    if (IsKeyPressed(KEY_C))
    {
        // Clear field for painting
        BeginTextureMode(target);
        ClearBackground(WHITE);
        EndTextureMode();
    }

    if (CheckCollisionPointRec(mousePos, btnBoundsCleaning))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) buttonState = 2;
        else buttonState = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) buttonAction = true;
    }
    else buttonState = 0;
    if (buttonAction)
    {
        BeginTextureMode(target);
        ClearBackground(WHITE);
        EndTextureMode();
        buttonAction = false;
        buttonState = 0;
    }
}

int main(void)
{
    const int screenWidth = 1000;
    const int screenHeight = 650;

    InitWindow(screenWidth, screenHeight, "painter");

    Texture2D buttonCleaning = LoadTexture("CleanButton.png");

    float frameHeight = (float)buttonCleaning.height;
    Rectangle sourceRecCleaning = { 0, 0, (float)buttonCleaning.width, frameHeight };
    Rectangle btnBoundsCleaning = { 275, 0, (float)buttonCleaning.width, frameHeight };
    int btnState = 0;
    bool btnAction = false;

    Color colors[MaxColorsCount] = { BLACK,  RED,  BLUE, YELLOW, GREEN, WHITE };
    Rectangle colorsRecs[MaxColorsCount] = { 0 };

    for (int i = 0; i < MaxColorsCount; i++)
    {
        colorsRecs[i].x = 10 + 30.0f * i + 10 * i;
        colorsRecs[i].y = 10;
        colorsRecs[i].width = 30;
        colorsRecs[i].height = 30;
    }

    int colorSelected = 0;
    int colorMouseHover = 0;
    float brushSize = 10.0f; //boll размер
    bool mouseWasPressed = false;

    RenderTexture2D target = LoadRenderTexture(screenWidth, screenHeight);

    BeginTextureMode(target);
    ClearBackground(WHITE);
    EndTextureMode();

    SetTargetFPS(1200);
    while (!WindowShouldClose())
    {
        btnAction = false;

        Vector2 mousePos = GetMousePosition();

        Cleaning_Button(btnAction, btnState, mousePos, btnBoundsCleaning, colorsRecs[6], colorMouseHover, target);

        // Choose color 
        for (int i = 0; i < MaxColorsCount; i++)
        {
            if (CheckCollisionPointRec(mousePos, colorsRecs[i]))
            {
                colorMouseHover = i;
                break;
            }
            else colorMouseHover = -1;
        }

        if ((colorMouseHover >= 0) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            colorSelected = colorMouseHover;

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {

            BeginTextureMode(target);
            if (mousePos.y > 50)
                DrawCircle((int)mousePos.x, (int)mousePos.y, brushSize, colors[colorSelected]);
            EndTextureMode();
        }

        BeginDrawing();


        DrawTextureRec(target.texture, (Rectangle) { 0, 0, (float)target.texture.width, (float)-target.texture.height }, (Vector2) { 0, 0 }, WHITE);

        if (mousePos.y > 50)
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                DrawCircleLines((int)mousePos.x, (int)mousePos.y, brushSize + 5.0f, MAROON);
            else
                DrawCircle(GetMouseX(), GetMouseY(), brushSize + 5.0f, colors[colorSelected]);
        }

        DrawRectangle(0, 0, GetScreenWidth(), 50, Fade(RED, 0.8f));
        DrawText("P O I N T E R !", 425, 10, 30, BLACK);

        for (int i = 0; i < MaxColorsCount; i++)
            DrawRectangleRec(colorsRecs[i], colors[i]);

        if (colorMouseHover >= 0)
            DrawRectangleRec(colorsRecs[colorMouseHover], Fade(YELLOW, 1.8f));


        for (int i = 0; i < MaxColorsCount; i++)
        {
            DrawRectangleLinesEx((Rectangle) { colorsRecs[i].x - 2, colorsRecs[i].y - 2, colorsRecs[i].width + 4, colorsRecs[i].height + 4 }, 3, Fade(BLACK, 0.5f));
        }
        DrawRectangleLinesEx((Rectangle) { colorsRecs[colorSelected].x - 2, colorsRecs[colorSelected].y - 2, colorsRecs[colorSelected].width + 4, colorsRecs[colorSelected].height + 4 }, 3, GOLD);

        DrawTextureRec(buttonCleaning, sourceRecCleaning, (Vector2) { btnBoundsCleaning.x, btnBoundsCleaning.y }, WHITE);

        if (mousePos.x >= btnBoundsCleaning.x && mousePos.y <= btnBoundsCleaning.y + btnBoundsCleaning.height && mousePos.x <= btnBoundsCleaning.x + btnBoundsCleaning.width && mousePos.y > btnBoundsCleaning.y)
            DrawRectangleRec(btnBoundsCleaning, Fade(LIGHTGRAY, .4f));

        EndDrawing();
    }

    UnloadRenderTexture(target);
    CloseWindow();
    return 0;
}