#include "raylib.h"

int main(){

    //window demitions
    int width{800};
    int height{450};
    InitWindow(width, height, "Axe Game Miko");

    //circle coordinates
    int circle_x{200};
    int circle_y{200};

    //axe coordinates
    int axe_x{400};
    int axe_y{0};
    int direction{10};

    SetTargetFPS(60);
    while( WindowShouldClose() != true ){
        BeginDrawing();
        ClearBackground(GRAY);

        //Game logic Start
        DrawCircle(circle_x, circle_y, 25, BLUE);
        DrawRectangle(axe_x, axe_y, 50, 50, RED);

        if( IsKeyDown(KEY_D) && circle_x < width ){
            circle_x += 10;
        }
        else if( IsKeyDown(KEY_A) && circle_x > 0 ){
            circle_x -= 10;
        }

        //move axe
        axe_y += direction;
        if(axe_y > height || axe_y < 0 ){
            direction = -direction;
        }

        //Game logic End
        EndDrawing();
    }
}