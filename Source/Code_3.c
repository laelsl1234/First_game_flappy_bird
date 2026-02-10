#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>







int main(void)
{

    int text_width = MeasureText("Aperte ENTER para iniciar jogo.", 30);

    Rectangle rectangleU = {
        (float)600, //600
        (float)0,
        70.0f,
        300.0f // 300
    };
    Rectangle rectangleD = {
        (float)600,
        (float)(rectangleU.y + rectangleU.height + 200),
        70.0f,
        600.0f
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
    
    bool gamerunning = false;
    bool preGame = true;
    int score = 0;
    bool checkscore = true;
    bool endedgame = false;
   
    SetTargetFPS(FPS);             

    while (!WindowShouldClose())
    {
        if (preGame)
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                gamerunning = true;
                preGame = false;
                
            }
            endedgame = false;
            ClearBackground(BLACK);

            DrawText("Aperte ENTER para iniciar jogo.", 150 , (screenHeight / 2), 30, GREEN);
        }

    if (gamerunning == true)
        {
        endedgame = true;
        BeginDrawing();

        if (!IsKeyDown(KEY_SPACE))
        {
            circlePos.y += 5;
        }
        else if (IsKeyDown(KEY_SPACE))
        {
            circlePos.y -= 5;
        }





        if (IsKeyDown(KEY_H)) {
            circlePos.x = GetMouseX();
            circlePos.y = GetMouseY();
        }

        
        rectangleD.y = (rectangleU.y + rectangleU.height + 200);
        

        ClearBackground(SKYBLUE);

        DrawCircleV(circlePos, 30.0, YELLOW);

        
        DrawRectangleRec(rectangleD, GREEN);
        DrawRectangleRec(rectangleU, GREEN);

        DrawRectangleLinesEx(rectangleD, 6.0, DARKGREEN);
        DrawRectangleLinesEx(rectangleU, 6.0, DARKGREEN);

        DrawRectangleRec(rectangleL, BLUE);
        DrawRectangleRec(rectangleH, BLUE);


        

        

        //DrawRectangleRec(rectangleS, WHITE);
        //DrawRectangleRec(rectangleSA, BLACK);

        //DrawTexture(player_textr, 50, 50, RED);

        
        

        if (score < 4)
        {
            rectangleD.x -= 2;
            rectangleU.x -= 2;
            rectangleS.x -= 2;
            rectangleSA.x -= 2;
        }
        else if(score > 3 && score < 8)
        {
            rectangleD.x -= 3;
            rectangleU.x -= 3;
            rectangleS.x -= 3;
            rectangleSA.x -= 3;

        }
        else if (score > 7 && score < 20)
        {
            rectangleD.x -= 4;
            rectangleU.x -= 4;
            rectangleS.x -= 4;
            rectangleSA.x -= 4;

        }
        else if (score > 19)
        {
            rectangleD.x -= 5;
            rectangleU.x -= 5;
            rectangleS.x -= 5;
            rectangleSA.x -= 5;

        }

        int rand = GetRandomValue(100, 380);

        if (rectangleD.x + rectangleD.width <= 0)
        {
            rectangleD.x = 800;
            rectangleU.y = rand;
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
    if (endedgame)
    {
        if (CheckCollisionCircleRec(circlePos, 30.0, rectangleD))
        {
            ClearBackground(BLACK);
            DrawText("Fim de Jogo", ((float)screenWidth / 2.5), ((float)screenHeight / 2), 30, RED);
            DrawText("Aperte R para reiniciar", ((float)screenWidth / 3), ((float)screenHeight / 2) + 30, 30, RED);
            gamerunning = false;
        }
        if (CheckCollisionCircleRec(circlePos, 30.0, rectangleU))
        {
            ClearBackground(BLACK);
            DrawText("Fim de Jogo", ((float)screenWidth / 2.5), ((float)screenHeight / 2), 30, RED);
            DrawText("Aperte R para reiniciar", ((float)screenWidth / 3), ((float)screenHeight / 2) + 30, 30, RED);
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
            DrawText("Fim de Jogo", ((float)screenWidth / 2.5), ((float)screenHeight / 2), 30, RED);
            DrawText("Aperte R para reiniciar", ((float)screenWidth / 3), ((float)screenHeight / 2) + 30, 30, RED);
            gamerunning = false;
        }
        if (CheckCollisionCircleRec(circlePos, 30.0, rectangleL))
        {
            ClearBackground(BLACK);
            DrawText("Fim de Jogo", ((float)screenWidth / 2.5), ((float)screenHeight / 2), 30, RED);
            DrawText("Aperte R para reiniciar", ((float)screenWidth / 3), ((float)screenHeight / 2) + 30, 30, RED);

            gamerunning = false;
        }

        if (!gamerunning)
        {
            if (IsKeyPressed(KEY_R))
            {
                gamerunning = false;
                preGame = true;
                circlePos.x = (float)screenWidth / 2;
                circlePos.y = (float)screenHeight / 2;

                rectangleU.x = 600;
                rectangleD.x = 600;
                rectangleS.x = 600;
                rectangleSA.x = 800;
                endedgame = true;
                score = 0;
                rectangleU.y = 0;

            }
        }
    }

        

        EndDrawing();

    }

    

    CloseWindow();

    return 0;
};
