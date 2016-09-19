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
#include "Mouse.h"

int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaMouse_posicao_x() {
	int x = 0;
	int y = 0;

	SDL_GetMouseState(&x, &y);

    return x;
}

int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaMouse_posicao_y() {
	int x = 0;
	int y = 0;

	SDL_GetMouseState(&x, &y);

    return y;
}

int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaMouse_ler_botao() {
	SDL_Event event;
	SDL_PollEvent(&event);

	/* If a button on the mouse is pressed. */
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        return event.button.button;
    }
    return -1;
}

int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaMouse_botao_pressionado(int botao) {
    SDL_Event event;
	SDL_PollEvent(&event);

	/* If a button on the mouse is pressed. */
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        return event.button.button == botao;
    }

    return 0;
}

int portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaMouse_algum_botao_pressionado() {
    SDL_Event event;
	SDL_PollEvent(&event);

	/* If a button on the mouse is pressed. */
    return event.type == SDL_MOUSEBUTTONDOWN;
}

