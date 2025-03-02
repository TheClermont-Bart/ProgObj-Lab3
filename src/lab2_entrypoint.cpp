#include "entrypoint.h"
#include "raylib.h"
#include <math.h>

//Creer votre class Engin ici et appeler une fonction start que vous définisser à la classe dans la fonction raylib_start plus bas.
void raylib_start(void){
    InitWindow(720,480, "Jeu");
    SetTargetFPS(60);
    float dt = GetFrameTime();
    float y = 240.0f;
    float x = 335.0f;

    while(!WindowShouldClose()){
        if(IsKeyDown(KEY_ESCAPE)){
            break;
        }

        BeginDrawing();
        
        ClearBackground(GREEN);

        DrawRectangle(x,y,40,40,BLACK);
        DrawText(TextFormat("X = %0.0f et Y = %0.0f",x,y),x-40-4,y+50,15,RED); // x-40-4 -> Position du rectangle - largeur du rectangle + moitier sizeofTextFormt;


        if(IsKeyDown(KEY_W)){
            y -= 20;
        }

        if(IsKeyDown(KEY_S)){
            y += 20;
        }

        if(IsKeyDown(KEY_D)){
            x += 20;
        }

        if(IsKeyDown(KEY_A)){
            x -= 20;
        }

        if(x <= 0){
            x = 720;
        }
        if(x > 720){
            x = 0;
        }

        if(y <= 0){
            y = 480;
        }
        if(y > 480){
            y = 0;
        }

        EndDrawing();


    //Game Logic
    
    }


}