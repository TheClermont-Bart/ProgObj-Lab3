#include "entrypoint.h"
#include "raylib.h"

using namespace std;
    int score_H = 0;
    int score_PC = 0;

class Ball{
    public: // PRIVATE + rajouter m_
    float x;
    float y;
    int speed_x;
    int speed_y;
    int radius;
//PUBLIC
void Draw(){
    //Boule
    DrawCircle(x,y,radius,WHITE);
}

void Update(){

    x += speed_x;
    y += speed_y;
    if(y+radius >= GetScreenHeight() || y-radius <=0){ //Position + grosseur de la boule
        speed_y *= -1;
    }
    if(x+radius >= GetScreenWidth()){
        score_PC++;
        speed_x *= -1;
    }
    if(x-radius <=0){
        score_H++;
        speed_x *= -1;
    }
}
};
Ball ball;

class Paddle{
    public:
    float x;
    float y;
    float width;
    float height;
    int speed;

    void Draw(){
        DrawRectangle(x,y,width,height,WHITE);
    }

    void Update(){
        if(IsKeyDown(KEY_UP)){
            y -= speed;
        }
        if(IsKeyDown(KEY_DOWN)){
            y += speed;
        }
        if(y <= 0){
            y = 0;
        }
        if(y + height >= GetScreenHeight()){
            y = GetScreenHeight() - height;
        }
    }
};
Paddle player;

void raylib_start(void){
    const int screen_Width = 720;
    const int screen_Height = 480;
    InitWindow(screen_Width, screen_Height, "Pong Game!");
    SetWindowState(FLAG_VSYNC_HINT);
    // SetTargetFPS(60);
    float dt = GetFrameTime();

    ball.radius = 20;
    ball.x = screen_Width/2;
    ball.y = screen_Height/2;
    ball.speed_x = 5;
    ball.speed_y = 5;

    player.width = 25;
    player.height = 120;
    player.x = screen_Width - player.width - 10; // Largeur de l'ecran - la palette - 10 pour decoller du mur
    player.y = screen_Height/2 - player.height/2;
    player.speed = 7;

    while(!WindowShouldClose()){
        if(IsKeyDown(KEY_ESCAPE)){
            break;
        }

        BeginDrawing();
        
        ClearBackground(BLACK);

        DrawFPS(10,10);

         //Score
        DrawText(TextFormat("Score PC = %d Score Human = %d",score_PC,score_H),screen_Width/2-210,5,25,RED);
        
        ball.Update();
        player.Update();

        if(CheckCollisionCircleRec(Vector2{ball.x,ball.y}, ball.radius, Rectangle{player.x,player.y,player.width,player.height})){
            ball.speed_y *= -1;
            ball.speed_x *= -1;
        }
        
        ball.Draw();
        player.Draw();

        //Paddle PC
        DrawRectangle(10,screen_Height/2 - 60,25,120,WHITE); // screen_Height/2 - 60 = Mettre le centre au centre du rectangle
        
        //Division du terrain
        DrawLine(screen_Width/2, 0, screen_Width/2, screen_Height,WHITE);


        EndDrawing();


    //Game Logic
    
    }

    
}