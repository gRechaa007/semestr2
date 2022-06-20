#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

#define SCREEN_WIDTH 850
#define SCREEN_HEIGHT 600


#define BODY_WIDTH 50
#define BODY_HEIGHT 50

const int EAT_WIDTH = 40;
const int EAT_HEIGHT = 40;

const int CELL_WIDTH = SCREEN_WIDTH / BODY_WIDTH;
const int CELL_HEIGHT = SCREEN_HEIGHT / BODY_HEIGHT;

	/*const int screenWidth = 1280;
	const int screenHeight = 720;*/
const char* fileNameGrass = "3.png";
int xPos = 0;
int yPos = 60;
int widthGrass = 30;
int heightGrass = 30;



typedef struct SnakeNode_ {
    int lifetime;
} SnakeNode;

typedef struct Snake_ {
    int length;
    int pos_x;
    int pos_y;
    int dir_x;
    int dir_y;
    float speed;
    float last_step_update;
    bool hunger;
}Snake;

typedef struct Eat_ {
    int x;
    int y;
}Eat;

Eat eat = { -1, -1 };

SnakeNode snake_body[24][13];


Snake snake = {
    .length = 2,
    .pos_x = 12,
    .pos_y = 6,
    .dir_x = 1,
    .dir_y = 0,
    .speed = 0.15f,
    .last_step_update = 0,
    .hunger = false,
};

void init_snake() {
    for (int i = 0; i < snake.length; i++) {
        int x = snake.pos_x - snake.dir_x * i;
        int y = snake.pos_y - snake.dir_y * i;
        snake_body[x][y].lifetime = snake.length - i;
    }
}

void drop_eat() {
    int x;
    int y;
    do {
        x = GetRandomValue(0, CELL_WIDTH - 1);
        y = GetRandomValue(0, CELL_HEIGHT - 1);
    } while (snake_body[x][y].lifetime > 0);
    eat.x = x;
    eat.y = y;
}

void Setup() {
    for (int i = 0; i < CELL_WIDTH; i++) {
        for (int j = 0; j < CELL_HEIGHT; j++) {
            snake_body[i][j].lifetime = 0;
        }
    }
    init_snake();
    drop_eat();
}
//
//void Grass(const char* fileNameGrass, int screenWidth, int screenHeight, int textureWidth, int textureHeight, int xPos, int yPos)
//{
//      Texture2D textureOfGrass = LoadTexture(fileNameGrass);
//       DrawText("S N A K E", (SCREEN_WIDTH / 2) - 100, 50, 40, DARKGREEN);
//       for (int i = 0; i < SCREEN_WIDTH;i += 30)
//       {
//           for (int j = 80; j < SCREEN_HEIGHT; j += 30)
//           {
//               DrawTexture(textureOfGrass, xPos + i, yPos + j, GREEN);
//           }
//       }
//
//}


void drawing() {
    for (int i = 0; i < CELL_WIDTH; i++) {
        for (int j = 0; j < CELL_HEIGHT; j++) {
            if (snake_body[i][j].lifetime > 0) {
                DrawRectangle(BODY_WIDTH * i, BODY_HEIGHT * j, BODY_WIDTH - 15, BODY_HEIGHT - 15, LIME );
            }
        }
    }
    DrawRectangle(snake.pos_x * BODY_WIDTH, snake.pos_y * BODY_HEIGHT, BODY_WIDTH, BODY_HEIGHT, DARKGREEN);
}

void Control() {
    if ((snake.dir_y == 0) && (IsKeyPressed(KEY_UP))) {
        snake.dir_y = 1;
        snake.dir_x = 0;
    }
    if ((snake.dir_y == 0) && (IsKeyPressed(KEY_DOWN))) {
        snake.dir_y = -1;
        snake.dir_x = 0;
    }
    if ((snake.dir_x == 0) && (IsKeyPressed(KEY_LEFT))) {
        snake.dir_y = 0;
        snake.dir_x = -1;
    }
    if ((snake.dir_x == 0) && (IsKeyPressed(KEY_RIGHT))) {
        snake.dir_y = 0;
        snake.dir_x = 1;
    }
}

void check_eat() {
    if (snake.pos_x == eat.x && snake.pos_y == eat.y) {
        snake.length++;
        snake.hunger = true;
        drop_eat();
    }
}

void move_snake() {
    snake.last_step_update += GetFrameTime();
    if (snake.last_step_update >= snake.speed) {
        snake.last_step_update = 0;
    }
    else {
        return;
    }


    if (snake.hunger) {
        snake.hunger = false;
    }
    else {
        for (int i = 0; i < CELL_WIDTH; i++) {
            for (int j = 0; j < CELL_HEIGHT; j++) {
                if (snake_body[i][j].lifetime > 0) {
                    snake_body[i][j].lifetime--;
                }
            }
        }
    }

    snake.pos_x += snake.dir_x;
    snake.pos_y += snake.dir_y;

    if (snake.pos_x >= CELL_WIDTH) {
        snake.pos_x = 0;
    }
    if (snake.pos_x < 0) {
        snake.pos_x = CELL_WIDTH - 1;
    }
    if (snake.pos_y >= CELL_HEIGHT) {
        snake.pos_y = 0;
    }
    if (snake.pos_y < 0) {
        snake.pos_y = CELL_HEIGHT - 1;
    }
    snake_body[snake.pos_x][snake.pos_y].lifetime = snake.length;
}

void draw_eat() {
    int tmpW = (BODY_WIDTH - EAT_WIDTH) / 2;
    int tmpH = (BODY_HEIGHT - EAT_HEIGHT) / 2;
    DrawRectangle(eat.x * BODY_WIDTH + tmpW, eat.y * BODY_HEIGHT + tmpH, EAT_HEIGHT, EAT_WIDTH, RED);
}

void Movement() {
    check_eat();
    move_snake();
    Control();
}

void eat_draw() {
    draw_eat();
    drawing();
}

int main(void) {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "S N A K E");
   
    

    SetTargetFPS(60);

    RenderTexture2D wind = LoadRenderTexture(SCREEN_WIDTH, SCREEN_HEIGHT);
    Setup();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        DrawText("S N A K E", (SCREEN_WIDTH / 2) - 100, 50, 40, DARKGREEN);
        Grass(fileNameGrass, SCREEN_WIDTH, SCREEN_HEIGHT, 30, 30, 0, 60);
        
        BeginTextureMode(wind);
        ClearBackground(GREEN);
      /*  Texture2D textureOfGrass = LoadTexture(fileNameGrass);
        DrawText("S N A K E", (SCREEN_WIDTH / 2) - 100, 50, 40, DARKGREEN);
        for (int i = 0; i < SCREEN_WIDTH;i += 30)
        {
            for (int j = 80; j < SCREEN_HEIGHT; j += 30)
            {
                DrawTexture(textureOfGrass, xPos + i, yPos + j, GREEN);
            }
        }*/

        eat_draw();

        EndTextureMode(wind);

        DrawTexture(wind.texture, 0, 0, WHITE);

        EndDrawing();
        Movement();
    }

    CloseWindow();
    return 0;
}