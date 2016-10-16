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
#include "Teclado.h"
#include "Graficos.h"

SDL_Event event;
int keys[323] = { 0 };
float tam = 0.4;
int x_mouse, y_mouse, w, h, x, y, altura; 

int d_pad(int i, int j) {
	int v = (x + (w/3)*(i-1) < x_mouse && x + (w/3)*i > x_mouse) && (y + (w/3)*(j-1) < y_mouse);
	return v;
}

int joystick_pressed(int teclado) {
	altura = portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaGraficos_altura_janela();
	
	x_mouse = 0;
	y_mouse = 0;

	SDL_GetMouseState(&x_mouse, &y_mouse);

	w = (tam * altura);
    h = (tam * altura);

    x = 10;
    y = altura-10-(h);

	if(event.type == 1025) {
	    keys[1073741903] = d_pad(3, 2);
	    keys[1073741904] = d_pad(1, 2);
	    keys[1073741906] = d_pad(2, 1);
	}

	if(event.type == 1026) {
	    keys[1073741903] = 0;
	    keys[1073741904] = 0;
		keys[1073741906] = 0;
	}

/*
	if(event.type == 1025) {
		
	}
*/
	return 0;
}

int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaTeclado_tecla_pressionada(int teclado) {
    SDL_PollEvent(&event);

    SDL_GetKeyboardState(NULL);
    if(event.type == SDL_KEYDOWN)
    	keys[event.key.keysym.sym] = 1;
    if(event.type == SDL_KEYUP)
    	keys[event.key.keysym.sym] = 0;

    #if ANDROID
    	joystick_pressed(teclado);
    #endif

    return keys[teclado];
}