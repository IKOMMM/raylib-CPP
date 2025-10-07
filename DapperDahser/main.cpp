#include "raylib.h"

int main(){
    //window dimensions 
    const int windowWidth{512};
    const int windowHeight{380};
    const int targetFPS{60};    

    //rectangle dimensions
    const int width{50};
    const int height{80};
    int posY{windowHeight-height};
    int velocity{-10};

    InitWindow(windowWidth, windowHeight, "DD Game");
    SetTargetFPS(targetFPS);
    
    while(!WindowShouldClose()){
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        if(IsKeyPressed(KEY_SPACE)){
            velocity -= 10;
        }

        DrawRectangle(windowWidth/2, posY, width, height, BLUE);

        // stop drawing
        EndDrawing();
    }
    CloseWindow();
}