//Using SDL and standard IO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

float escalaLargura;
float escalaAltura;

SDL_Window* window;
SDL_Surface* surface;
SDL_Renderer *renderer;
SDL_Rect src;
SDL_Rect dest;
int w;
int h;

int s_height = 0;
int s_width = 0;

SDL_Texture* texture_joystick;

void init_joystick() {
    char* caminho = "dpad.png";
    #ifdef ANDROID
        SDL_RWops *file = SDL_RWFromFile(caminho, "rb");
        SDL_Surface* image_endereco  = IMG_Load_RW(file, 1);
    #else
        SDL_Surface* image_endereco = IMG_Load(caminho);
    #endif

    texture_joystick = SDL_CreateTextureFromSurface(renderer, image_endereco);
}

void render_joystick() {
    SDL_QueryTexture(texture_joystick, NULL, NULL, &w, &h);
    float tam = 0.4;

    //SDL_Log("tamanho: %d", s_height);
    w = (tam * s_height);
    h = (tam * s_height);

    int x = 10;
    int y = s_height-10-(h);


    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;

    SDL_RenderCopy(renderer, texture_joystick, NULL, &dest);
}

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
    SDL_PumpEvents();
}

int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_carregar_imagem(char* caminho) {
    #ifdef DEBUG
        printf("Carregando imagem \"%s\" \n", caminho);
    #endif

    #ifdef ANDROID
        SDL_RWops *file = SDL_RWFromFile(caminho, "rb");
        SDL_Surface* image_endereco  = IMG_Load_RW(file, 1);
    #else
        SDL_Surface* image_endereco = IMG_Load(caminho);
    #endif
    
    if(image_endereco == NULL){
        printf("Imagem não encontrada para o caminho %s\n", caminho);
        return 0;
    } 

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image_endereco);
    int endereco = (int) texture;
    SDL_Log("endereço %d", endereco);
    return endereco;
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_iniciar_modo_grafico(int manter_visivel){
    #ifdef DEBUG
        SDL_Log("Iniciando modo grafico...\n");
    #endif

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        SDL_Log( "Problemas ao inicializar o modo gráfico: %s\n", SDL_GetError() );
    }

     else
    {

        //Cria janela
        #ifdef ANDROID
        window = SDL_CreateWindow("Programa", 50, 50, NULL, NULL, 0);
        //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
        #else
        window = SDL_CreateWindow("Programa", 50, 50, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        #endif
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_TARGETTEXTURE);
        //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
        //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);
        //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

        
        SDL_GetWindowSize(window, &s_width, &s_height);
        
        escalaAltura = 1;
        escalaLargura = 1;

        if( window == NULL )
        {
            SDL_Log( "Janela não foi criada: %s\n", SDL_GetError() );
        }
        else
        {
            //Atualiza tela
            SDL_UpdateWindowSurface(window);
            SDL_RenderClear(renderer);
        }


        init_joystick();
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
    #if ANDROID
        render_joystick();
    #endif
    
    SDL_RenderPresent(renderer);
    SDL_Delay(1);
    //SDL_UpdateWindowSurface(window);
    SDL_RenderClear(renderer);
    SDL_PumpEvents();
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_renderizar_imagem(int largura, int altura){

}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_desenhar_imagem(int x, int y, int endereco){
    #ifdef DEBUG
        SDL_Log("Desenhando image x:%d y:%d", x, y);
    #endif
    //SDL_Surface* image_endereco = (SDL_Surface*) endereco;
    //SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image_endereco);
    SDL_Texture* texture = (SDL_Texture*) endereco;

    SDL_QueryTexture(texture, NULL, NULL, &w, &h);

    dest.x = x*escalaLargura;
    dest.y = y*escalaAltura;
    dest.w = w * escalaLargura;
    dest.h = h * escalaAltura;

    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_desenhar_porcao_imagem(int x, int y, int  xi, int yi, int largura, int altura, int endereco) {
    #ifdef DEBUG
        SDL_Log("Desenhando image x:%d y:%d xi:%d yi:%d largura:%d altura:%d", x, y);
    #endif

    //SDL_Surface* image_endereco = (SDL_Surface*) endereco;
    SDL_Texture* texture =(SDL_Texture*) endereco;

    
    src.x = xi*escalaLargura;
    src.y = yi*escalaAltura;
    src.w = largura * escalaLargura;
    src.h = altura * escalaAltura;

    
    dest.x = x*escalaLargura;
    dest.y = y*escalaAltura;
    dest.w = largura * escalaLargura;
    dest.h = altura * escalaAltura;

    SDL_RenderCopy(renderer, texture, &src, &dest);
}

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_desenhar_elipse(int x, int y, int largura, int altura, int preencher) {
    
}


int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_largura_janela(){
    return s_width;
}

int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_altura_janela(){
    return s_height;
}