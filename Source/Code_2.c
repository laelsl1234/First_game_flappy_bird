#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>







int main(void)
{
    Rectangle rectangleD = {
        (float)600,
        (float)500,
        70.0f,
        300.0f
    };
    Rectangle rectangleU = {
        (float)600,
        (float)0,
        70.0f,
        280.0f
    };
    Rectangle rectangleS = {
        (float)600,
        (float)250,
        70.0f,
        300.0f
    };
    Rectangle rectangleSA = {
        (float)800,
        (float)0,
        70.0f,
        900.0f
    };

    Rectangle rectangleH = {
        (float)0,
        (float)0,
        800.0f,
        20.0f
    };
    Rectangle rectangleL = {
        (float)0,
        (float)785,
        800.0f,
        20.0f
    };
    
    const int screenWidth = 800;
    const int screenHeight = 800;
    Vector2 circlePos = { (float) screenWidth / 2, (float) screenHeight / 2 };

    InitWindow(screenWidth, screenHeight, "Flappy_test");

    const int FPS = 120;
    double momentumDown = 0.1;
    double momentumUp = 30;
    const double gravity = 1.05;
    bool gamerunning = true;
    bool isGoingUp = false;
    int score = 0;
    bool checkscore = true;
    bool prevdown = false;
    bool prevup = false;
    SetTargetFPS(FPS);             

    while (!WindowShouldClose())
    {
    if (gamerunning == true)
        {
        BeginDrawing();

        if (!IsKeyPressed(KEY_SPACE))
        {
            circlePos.y += ((FPS * GetFrameTime()) * momentumDown);
            momentumDown = momentumDown * gravity;
        }

        if (IsKeyPressed(KEY_SPACE))
        {

            momentumDown = 0.1;
            isGoingUp = true;

            while (isGoingUp == true)
            {
                circlePos.y -= ((FPS * GetFrameTime()) * momentumUp);

                DrawCircleV(circlePos, 30.0, YELLOW);

                momentumUp *= 0.7;

                if (momentumUp <= 10)
                {
                    isGoingUp = false;
                }

            }
            momentumUp = 30;
        }





        if (IsKeyDown(KEY_H)) {
            circlePos.x = GetMouseX();
            circlePos.y = GetMouseY();
        }

        



        ClearBackground(RAYWHITE);

        DrawCircleV(circlePos, 30.0, YELLOW);

        DrawRectangleRec(rectangleD, RED);
        DrawRectangleRec(rectangleU, BLUE);

        DrawRectangleRec(rectangleL, GREEN);
        DrawRectangleRec(rectangleH, YELLOW);

        //DrawRectangleRec(rectangleS, WHITE);
        //DrawRectangleRec(rectangleSA, BLACK);

        

        rectangleD.x -= 1;
        rectangleU.x -= 1;
        rectangleS.x -= 1;
        rectangleSA.x -= 1;
        if (rectangleD.x + rectangleD.width <= 0)
        {
            rectangleD.x = 800;
        }
        if (rectangleU.x + rectangleU.width <= 0)
        {
            rectangleU.x = 800;
        }
        if (rectangleS.x + rectangleS.width <= 0)
        {
            rectangleS.x = 800;
        }
        if (rectangleSA.x + rectangleSA.width <= 0)
        {
            rectangleSA.x = 800;
        }
        
        DrawText(TextFormat("Score: %i",score), (0), (0), 30, RED);

    }
        if (CheckCollisionCircleRec(circlePos, 30.0,rectangleD))
        {
            ClearBackground(BLACK);
            DrawText("Game Over", ( (float)screenWidth / 2.5), ( (float)screenHeight / 2), 30, RED);

            gamerunning = false;
        }
        if (CheckCollisionCircleRec(circlePos, 30.0, rectangleU))
        {
            ClearBackground(BLACK);
            DrawText("Game Over", ( (float)screenWidth / 2.5), ( (float)screenHeight / 2), 30, RED);

            gamerunning = false;
        }
        if (CheckCollisionCircleRec(circlePos, 30.0, rectangleS))
        {
            if (checkscore)
            {
                score += 1;

                checkscore = false;
            }
        }
        if (CheckCollisionCircleRec(circlePos, 30.0, rectangleSA))
        {
            checkscore = true;
        }
        if (CheckCollisionCircleRec(circlePos, 30.0, rectangleH))
        {
            ClearBackground(BLACK);
            DrawText("Game Over", ((float)screenWidth / 2.5), ((float)screenHeight / 2), 30, RED);

            gamerunning = false;
        }
        if (CheckCollisionCircleRec(circlePos, 30.0, rectangleL))
        {
            ClearBackground(BLACK);
            DrawText("Game Over", ((float)screenWidth / 2.5), ((float)screenHeight / 2), 30, RED);

            gamerunning = false;
        }
        




        EndDrawing();

    }

    
    CloseWindow();

    return 0;
}
