#include "raylib.h"

int main(){
    //window demitions
    int width{800};
    int height{450};
    InitWindow(width, height, "Axe Game Miko");

    //circle coordinates
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    //axe coordinates
    int axe_x{400};
    int axe_y{0};
    int axe_length{50};
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};
    
    int direction{10};
    bool collision_with_axe = 
        (b_axe_y >= u_circle_y) && 
        (u_axe_y <= b_circle_y) && 
        (r_axe_x >= l_circle_x) && 
        (l_axe_x <= r_circle_x);

    SetTargetFPS(60);
    while( WindowShouldClose() != true ){
        BeginDrawing();
        ClearBackground(GRAY);

        if( collision_with_axe ){
            DrawText("GameOver!", 400, 200, 20, RED);
        }
        else{
            //Game logic Start

            //Update Edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            //Update collision with axe
            collision_with_axe = 
                (b_axe_y >= u_circle_y) && 
                (u_axe_y <= b_circle_y) && 
                (r_axe_x >= l_circle_x) && 
                (l_axe_x <= r_circle_x);


            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

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
        }        

        //Game logic End
        EndDrawing();
    }
}