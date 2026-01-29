#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>






int main(void)
{
    
    const int screenWidth = 800;
    const int screenHeight = 800;
    Vector2 circlePos = { (float) screenWidth / 2, (float) screenHeight / 2 };
    InitWindow(screenWidth, screenHeight, "Flappy_test");

    int FPS = 120;
    double momentumDown = 0.1;
    double momentumUp = 30;
    double gravity = 1.05;
    bool momentumupbool = false;
    SetTargetFPS(FPS);             

    while (!WindowShouldClose())  
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
            momentumupbool = true;
            for (int i = 0; i < 9; i++)
            {

                if (momentumupbool = true)
                {
                    circlePos.y -= (momentumUp);
                    DrawCircleV(circlePos, 20.0, LIGHTGRAY);
                }
                momentumUp = momentumUp * 0.8;
                
            }
            momentumUp = 30;
  
            
        }
        
        
        


        if (IsKeyDown(KEY_H)) {
            circlePos.x = GetMouseX();
            circlePos.y = GetMouseY();
        }


        

        

        ClearBackground(RAYWHITE);

        DrawCircleV(circlePos,20.0,LIGHTGRAY);
        

        EndDrawing();

        if (momentumUp <= 10)
        {
            momentumupbool = false;
        }
        

    }

    
    CloseWindow();

    return 0;
}
