#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <math.h>

int main(int argc, char **argv)
{
    // A variável window representa a janela que nos fornecerá o contexto para desenharmos 
    // formas e imagens, e receberá eventos vindos de fontes diversas como teclado e mouse.

    /*SDL_Window* window = NULL;

   /*
    * Inicialização da janela 
    

    if (SDL_Init(SDL_INIT_VIDEO) == 0)
        window = SDL_CreateWindow("Tutorial SDL 2", 50, 50, 640, 480, 0);
    else 
        SDL_Log("Erro de inicializacao: %s", SDL_GetError());

   /*
    * Loop principal
    

    if (window != NULL)
        while (!SDL_QuitRequested()) { /* ...  }
    else
        SDL_Log("Erro de inicializacao: %s", SDL_GetError());

    /*
     * Finalização
     

     SDL_DestroyWindow(window);
     SDL_Quit();
     return 0;
     
     
     */
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        SDL_Log("Can't init %s", SDL_GetError());
    SDL_CreateWindow("Hi mundo!", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Delay(10000000);
    return 0;
     





}