#include "raylib.h"
#include <stdio.h>

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 450

int
main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "pong");
    SetTargetFPS(60);

    Vector2 ball       = {400, 225};
    Vector2 ball_speed = {5, 5};
    int ball_radius    = 10;

    Rectangle p1 = {30, 175, 15, 100};
    Rectangle p2 = {755, 175, 15, 100};
    int paddle_speed = 8;

    int score_p1, score_p2 = 0;

    while (!WindowShouldClose()) {

        // player 1 commands (w/s)
        if (IsKeyDown(KEY_W)) {
          p1.y -= paddle_speed;
          printf("player 1 down\n");
        }

        if (IsKeyDown(KEY_S)) {
          p1.y += paddle_speed;
          printf("player 1 up\n");
        }

        // player 2 commands (o/l)
        if (IsKeyDown(KEY_O)) {
          p2.y -= paddle_speed;
          printf("player 2 down\n");
        }

        if (IsKeyDown(KEY_L)) {
          p2.y += paddle_speed;
          printf("player 2 up\n");
        }


        if (p1.y < 0) p1.y = 0;
        if (p1.y > SCREEN_HEIGHT - p1.height)
          p1.y = SCREEN_HEIGHT - p1.height;

        if (p2.y < 0) p2.y = 0;
        if (p2.y > SCREEN_HEIGHT - p2.height)
          p2.y = SCREEN_HEIGHT - p2.height;

        ball.x += ball_speed.x;
        ball.y += ball_speed.y;

///////////////////

        BeginDrawing();
        ClearBackground(BLACK);

        DrawLine(400, 0, 400, 450, WHITE);

        DrawRectangleRec(p1, WHITE);
        DrawRectangleRec(p2, WHITE);

        DrawCircleV(ball, ball_radius, WHITE);

        DrawText(TextFormat("%d", score_p1), 300, 20, 40, WHITE);
        DrawText(TextFormat("%d", score_p2), 480, 20, 40, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

