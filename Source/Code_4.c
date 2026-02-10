//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>







int main(void)
{
    //Variable definitions
    
    //Rectangle variable definition
    Rectangle rectangleU = {
        (float)600, //600
        (float)-400,
        70.0f,
        700.0f // 300
    };
    Rectangle rectangleD = {
        (float)600,
        (float)(rectangleU.y + rectangleU.height + 250),
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

    //Const variables, player position and window initialization
    
    
    const int screenWidth = 800;
    const int screenHeight = 800;
    Vector2 circlePos = { (float) screenWidth / 2, (float) screenHeight / 2 };
    const int FPS = 120;
    InitWindow(screenWidth, screenHeight, "Flappy_test");
    
    //Variable definitions for gameplay, switches, score and etc

    int text_width = MeasureText("Aperte ENTER para iniciar jogo.", 30);
    bool gamerunning = false;
    bool preGame = true;
    int score = 0;
    bool checkscore = true;
    bool endedgame = false;
   
    SetTargetFPS(FPS);      



    //Main Loop
    while (!WindowShouldClose())
    {
        if (preGame)
        {
            //Before game starts
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
        //Gameplay loop
        endedgame = true;
        BeginDrawing();
        //Player Movement
        if (!IsKeyDown(KEY_SPACE))
        {
            circlePos.y += 5;
        }
        else if (IsKeyDown(KEY_SPACE))
        {
            circlePos.y -= 5;
        }

        rectangleD.y = (rectangleU.y + rectangleU.height + 200);
        
        //Drawing the sprites
        ClearBackground(SKYBLUE);

        DrawCircleV(circlePos, 30.0, YELLOW);

        
        DrawRectangleRec(rectangleD, GREEN);
        DrawRectangleRec(rectangleU, GREEN);

        DrawRectangleLinesEx(rectangleD, 6.0, DARKGREEN);
        DrawRectangleLinesEx(rectangleU, 6.0, DARKGREEN);

        DrawRectangleRec(rectangleL, BLUE);
        DrawRectangleRec(rectangleH, BLUE);

        //Visualization
            /*DrawRectangleRec(rectangleS, WHITE);
            DrawRectangleRec(rectangleSA, BLACK);*/

        //Speed modifier based on score
        
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
        else if (score > 19 && score < 37)
        {
            rectangleD.x -= 5;
            rectangleU.x -= 5;
            rectangleS.x -= 5;
            rectangleSA.x -= 5;

        }
        else if (score > 36 && score < 60)
        {
            rectangleD.x -= 6;
            rectangleU.x -= 6;
            rectangleS.x -= 6;
            rectangleSA.x -= 6;

        }
        else if (score > 59 && score < 100)
        {
            rectangleD.x -= 7;
            rectangleU.x -= 7;
            rectangleS.x -= 7;
            rectangleSA.x -= 7;

        }
        else if (score > 99)
        {
            rectangleD.x -= 8;
            rectangleU.x -= 8;
            rectangleS.x -= 8;
            rectangleSA.x -= 8;

        }
        //Code to make the pipes loop around the screen and change their position
        int rand = GetRandomValue(-700 , -300);

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
    //Loop for checking if the game should end, and if yes drawing the gameover text aswell as
    //stopping the gameplay loop
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
        //Loop to increment score only once everytime the ball goes through the pipes
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
            //Checks for keypress R and if pressed restarts the game
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
                rectangleU.y = -400;

            }
        }
    }

        

        EndDrawing();

    }

    

    CloseWindow();

    return 0;
};
