
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<vector>

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*personaje,*zombie1,*zombie2,*zombie3,*meta;
SDL_Rect rect_background,rect_personaje,rect_zombie1, rect_zombie2,rect_zombie3,rect_meta,my_rect;
SDL_Texture *barra1,*barra2,*barra3,*barra4,*barra5,*barra6,*barra7,*barra8,*barra9,*barra10,*barra11;
SDL_Rect rect_barra1,rect_barra2,rect_barra3,rect_barra4,rect_barra5,rect_barra6,rect_barra7,rect_barra8,rect_barra9,rect_barra10,rect_barra11;

int screen_width = 700;
int screen_height = 400;

bool estaColisionando(SDL_Rect a, SDL_Rect b)

{

    if(a.x + a.w < b.x)
        return false;

    if(b.x + b.w < a.x)
        return false;

    if(b.y + b.h < a.y)
        return false;

    if(a.y + a.h < b.y)
        return false;
    return true;

}


int main( int argc, char* args[] )
{

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }

    if((window = SDL_CreateWindow("Image Loading", 100, 0, screen_width /*WIDTH*/, screen_height/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }


    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"Fondo.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = 800;
    rect_background.h = 400;
        //Textura del Juego
    personaje = IMG_LoadTexture(renderer, "personaje.png");
    SDL_QueryTexture(personaje, NULL, NULL, &w, &h);
    rect_personaje.x = 0;
    rect_personaje.y = 0;
    rect_personaje.w = 60;
    rect_personaje.h = 80;
        //Barra abajo del personaje principal
    barra1 = IMG_LoadTexture(renderer, "barra1.png");
    SDL_QueryTexture(barra1, NULL, NULL, &w, &h);
    rect_barra1.x = 0;
    rect_barra1.y = 90;
    rect_barra1.w =150;
    rect_barra1.h = 15;
        //barra de enfrente del personaje principal
    barra2 = IMG_LoadTexture(renderer, "barra1.png");
    SDL_QueryTexture(barra2, NULL, NULL, &w, &h);
    rect_barra2.x = 230;
    rect_barra2.y = 0;
    rect_barra2.w =15;
    rect_barra2.h = 220;
        //barra concecutiva a la anterior
    barra3 = IMG_LoadTexture(renderer, "barra1.png");
    SDL_QueryTexture(barra3, NULL, NULL, &w, &h);
    rect_barra3.x = 230;
    rect_barra3.y = 220;
    rect_barra3.w =150;
    rect_barra3.h = 15;
        //zombie
    zombie1 = IMG_LoadTexture(renderer, "zombie1.png");
    SDL_QueryTexture(zombie1, NULL, NULL, &w, &h);
    rect_zombie1.x = 30;
    rect_zombie1.y = 100;
    rect_zombie1.w =60;
    rect_zombie1.h = 80;
        //barra abajo de zombie
    barra4 = IMG_LoadTexture(renderer, "barra1.png");
    SDL_QueryTexture(barra4, NULL, NULL, &w, &h);
    rect_barra4.x = 140;
    rect_barra4.y = 190;
    rect_barra4.w =15;
    rect_barra4.h = 150;
        //barra consecutiva a la anterior
    barra5 = IMG_LoadTexture(renderer, "barra1.png");
    SDL_QueryTexture(barra5, NULL, NULL, &w, &h);
    rect_barra5.x = 140;
    rect_barra5.y = 325;
    rect_barra5.w =370;
    rect_barra5.h = 15;
        //Barra consecutiva al anterior
    barra6 = IMG_LoadTexture(renderer, "barra1.png");
    SDL_QueryTexture(barra6, NULL, NULL, &w, &h);
    rect_barra6.x = 495;
    rect_barra6.y = 130;
    rect_barra6.w =15;
    rect_barra6.h =200;
        //segundo zombie
    zombie2 = IMG_LoadTexture(renderer, "zombie1.png");
    SDL_QueryTexture(zombie2, NULL, NULL, &w, &h);
    rect_zombie2.x = 270;
    rect_zombie2.y = 135;
    rect_zombie2.w =60;
    rect_zombie2.h = 80;
        //barra ariba de segundo zombie
    barra7 = IMG_LoadTexture(renderer, "barra1.png");
    SDL_QueryTexture(barra7, NULL, NULL, &w, &h);
    rect_barra7.x = 370;
    rect_barra7.y = 0;
    rect_barra7.w =15;
    rect_barra7.h =140;

    barra8 = IMG_LoadTexture(renderer, "barra1.png");
    SDL_QueryTexture(barra8, NULL, NULL, &w, &h);
    rect_barra8.x = 370;
    rect_barra8.y = 0;
    rect_barra8.w =300;
    rect_barra8.h =15;
        //barra que sostiene al zombie
    barra9 = IMG_LoadTexture(renderer, "barra1.png");
    SDL_QueryTexture(barra9, NULL, NULL, &w, &h);
    rect_barra9.x = 510;
    rect_barra9.y = 210;
    rect_barra9.w =70;
    rect_barra9.h =15;
        // tercer zombie
    zombie3 = IMG_LoadTexture(renderer, "zombie2.png");
    SDL_QueryTexture(zombie3, NULL, NULL, &w, &h);
    rect_zombie3.x = 510;
    rect_zombie3.y = 130;
    rect_zombie3.w =60;
    rect_zombie3.h = 80;
        //barra enfrente del tercer zombie
     barra10 = IMG_LoadTexture(renderer, "barra1.png");
    SDL_QueryTexture(barra10, NULL, NULL, &w, &h);
    rect_barra10.x = 655;
    rect_barra10.y = 10;
    rect_barra10.w =15;
    rect_barra10.h =340;

    meta = IMG_LoadTexture(renderer, "meta.png");
    SDL_QueryTexture(meta, NULL, NULL, &w, &h);
    rect_meta.x = 540;
    rect_meta.y = 300;
    rect_meta.w =80;
    rect_meta.h = 80;


    bool game_over = false;
    int velocidad = 5;

    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_d)
                    rect_personaje.x++;
                if(Event.key.keysym.sym == SDLK_a)
                    rect_personaje.x--;
                if(Event.key.keysym.sym == SDLK_w)
                    rect_personaje.y--;
                if(Event.key.keysym.sym == SDLK_s)
                    rect_personaje.y++;
            }
        }
        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
        int x_anterior = rect_personaje.x;
        int y_anterior = rect_personaje.y;

        if( currentKeyStates[ SDL_SCANCODE_UP ] )
        {
            rect_personaje.y-=velocidad;
        }
        if( currentKeyStates[ SDL_SCANCODE_DOWN ] )
        {
            rect_personaje.y+=velocidad;
        }
        if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
        {
            rect_personaje.x-=velocidad;
        }
        if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
        {
            rect_personaje.x+=velocidad;
        }

        if(rect_personaje.x<0 || rect_personaje.x+rect_personaje.w > screen_width)
        {
            rect_personaje.x = x_anterior;
        }

        if(rect_personaje.y<0 || rect_personaje.y+rect_personaje.h > screen_height)
        {
            rect_personaje.y = y_anterior;
        }

        if(estaColisionando(rect_personaje, my_rect))
        {
            rect_personaje.x = x_anterior;
            rect_personaje.y = y_anterior;
            rect_personaje.y  ++;

        }




        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, personaje, NULL, &rect_personaje);
        SDL_RenderCopy(renderer, barra1, NULL, &rect_barra1);
        SDL_RenderCopy(renderer, barra2, NULL, &rect_barra2);
        SDL_RenderCopy(renderer, barra3, NULL, &rect_barra3);
        SDL_RenderCopy(renderer, zombie1, NULL, &rect_zombie1);
        SDL_RenderCopy(renderer, barra4, NULL, &rect_barra4);
        SDL_RenderCopy(renderer, barra5, NULL, &rect_barra5);
        SDL_RenderCopy(renderer, barra6, NULL, &rect_barra6);
        SDL_RenderCopy(renderer, zombie2, NULL, &rect_zombie2);
        SDL_RenderCopy(renderer, barra7, NULL, &rect_barra7);
        SDL_RenderCopy(renderer, barra8, NULL, &rect_barra8);
        SDL_RenderCopy(renderer, barra9, NULL, &rect_barra9);
        SDL_RenderCopy(renderer, zombie3, NULL, &rect_zombie3);
        SDL_RenderCopy(renderer, barra10, NULL, &rect_barra10);
        SDL_RenderCopy(renderer, meta, NULL, &rect_meta);
        SDL_RenderPresent(renderer);

        SDL_Delay(1);
    }

	return 0;
}


