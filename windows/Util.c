//Using SDL and standard IO
#include <stdio.h>
#include <SDL.h>
#include "Util.h"

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaUtil_aguarde(int intervalo) {
    #ifdef DEBUG
        printf("Aguardando o intervalo: %d", intervalo);
    #endif
    SDL_Delay(intervalo);
}