//Using SDL and standard IO
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#if ANDROID
#include <SDL_image.h>
#endif
#if WIN32
#include <SDL2/SDL_image.h>
#endif
#include "Graficos.h"

//Screen dimension constants
const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;

SDL_Window* window;
SDL_Renderer *renderer;

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_limpar() {
    #ifdef DEBUG
    printf("Limpando tela");
    #endif
    SDL_RenderClear(renderer);
}

int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_criar_cor(int r, int g, int b) {
	#ifdef DEBUG
        printf("Criando cor r:%d g:%d b:%d \n", r, g, b);
    #endif
    int rgb = r;
    rgb = (rgb << 8) + g;
    rgb = (rgb << 8) + b;
	return rgb;
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_definir_cor(int cor) {
    #ifdef DEBUG
        printf("Definindo cor \n", cor);
    #endif
    int red = (cor >> 16) & 0xFF;
    int green = (cor >> 8) & 0xFF;
    int blue = cor & 0xFF;

    
    SDL_SetRenderDrawColor(renderer, red, green, blue, 0);
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_desenhar_ponto(int x, int y) {
    #ifdef DEBUG
        printf("Desenhando ponto na posição x:%d y:%d \n", x, y);
    #endif
    SDL_RenderDrawPoint(renderer, x, y); //Renders on middle of screen.
    SDL_RenderPresent(renderer);
    SDL_PumpEvents();
}

int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_carregar_imagem(char* caminho) {
    #ifdef DEBUG
        printf("Carregando imagem \"%s\" \n", caminho);
    #endif
    SDL_Surface* image_endereco = IMG_Load(caminho);
    
    if(image_endereco == NULL){
        printf("Imagem não encontrada para o caminho %s\n", caminho);
        return 0;
    } 

    int endereco = (int) image_endereco;    
    return endereco;
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_iniciar_modo_grafico(int manter_visivel){
    #ifdef DEBUG
        printf("Iniciando modo grafico...\n");
    #endif

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Problemas ao inicializar o modo gráfico: %s\n", SDL_GetError() );
    }

     else
    {
        //Cria janela
        SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
        if( window == NULL )
        {
            printf( "Janela não foi criada: %s\n", SDL_GetError() );
        }
        else
        {
            //Atualiza tela
            SDL_UpdateWindowSurface(window);
        }
    }
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_encerrar_modo_grafico(){
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_liberar_imagem(int endereco){
    return 0;
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_renderizar(){
    SDL_RenderPresent(renderer);
    SDL_PumpEvents();
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_renderizar_imagem(int largura, int altura){

}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_desenhar_imagem(int x, int y, int endereco){
    #ifdef DEBUG
        printf("Desenhando imagem x:%d y:%d endereco:%d \n", x, y, endereco);
    #endif    
    SDL_Surface* screen = SDL_GetWindowSurface(window);
    SDL_Surface* image_endereco = (SDL_Surface*) endereco;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image_endereco);

    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = image_endereco->w;
    dest.h = image_endereco->h;

    SDL_RenderCopy(renderer, texture, NULL, &dest);
}
