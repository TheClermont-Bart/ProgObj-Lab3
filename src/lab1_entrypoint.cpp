#include "entrypoint.h"
#include "raylib.h"

//Creer votre class Engin ici et appeler une fonction start que vous définisser à la classe dans la fonction raylib_start plus bas.
void raylib_start(void){
    InitWindow(720,480, "Fenetre");
    int w,h;
    w = GetScreenWidth()*0.8;
    h = GetScreenHeight()*0.3;

    while(!WindowShouldClose()){
        if(IsKeyDown(KEY_ESCAPE)){
            break;
        }

        BeginDrawing();
        
        ClearBackground(SKYBLUE);
        
        //Gazon
        DrawRectangle(0,400,GetScreenHeight()*2,200,DARKGREEN); 

        //Texte
        DrawText("ALLO TOI!!!!", w/2,5,75,RED);
        
        //Soleil
        DrawCircle(50,50,60,YELLOW);

        //Maison
        DrawRectangle(w/2,GetScreenHeight()-180,100,100,CLITERAL(Color){ 127, 106, 79, 255 });
        DrawTriangle({275,300},{400,300},{338,200}, BLACK);

        //Arbre
        DrawRectangle(75,320,30,100,CLITERAL(Color){ 127, 106, 79, 255 });
        DrawCircle(90,315,50,DARKGREEN);




        EndDrawing();


    //Game Logic
    
    }
}