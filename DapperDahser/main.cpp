#include "raylib.h"

int main(){
    //window dimensions 
    const int windowWidth{512};
    const int windowHeight{380};
    const int targetFPS{60};

    InitWindow(windowWidth, windowHeight, "DD Game");
    SetTargetFPS(targetFPS);
    
    while(!WindowShouldClose()){
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        // stop drawing
        EndDrawing();
    }
    CloseWindow();
}