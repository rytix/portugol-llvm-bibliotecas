//Using SDL and standard IO
#include <stdio.h>
#include <SDL.h>
#include "Graficos.h"

const int DEBUG = 0;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window;
SDL_Renderer *renderer;

int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_criar_cor(int r, int g, int b) {
	if(DEBUG) printf("Criando cor r:%d g:%d b:%d \n", r, g, b);
    int rgb = r;
    rgb = (rgb << 8) + g;
    rgb = (rgb << 8) + b;
	return rgb;
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_definir_cor(int cor) {
	if(DEBUG) printf("Definindo cor \n", cor);
    int red = (cor >> 16) & 0xFF;
    int green = (cor >> 8) & 0xFF;
    int blue = cor & 0xFF;

    
    SDL_SetRenderDrawColor(renderer, red, green, blue, 0);
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_desenhar_ponto(int x, int y) {
	if(DEBUG) printf("Desenhando ponto na posição x:%d y:%d \n", x, y);
    SDL_RenderDrawPoint(renderer, x, y); //Renders on middle of screen.
    SDL_RenderPresent(renderer);
    SDL_PumpEvents();
}

int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_carregar_imagem(char* endereco) {
    return 0;
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_iniciar_modo_grafico(int manter_visivel){
    if(DEBUG) printf("Iniciando modo grafico...\n");

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Problemas ao inicializar o modo gráfico: %s\n", SDL_GetError() );
    }

     else
    {
        //Cria janela
        SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);
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

}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_renderizar_imagem(int largura, int altura){

}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_desenhar_imagem(int x, int y, int endereco){

}
