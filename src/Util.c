//Using SDL and standard IO
#include <stdio.h>
#include <SDL.h>
#include "Util.h"

void portugol_core_llvm_bibliotecas_portugol_core_llvm_bibliotecas_BibliotecaUtil_aguarde(int intervalo) {
    #ifdef DEBUG
        printf("Aguardando o intervalo: %d", intervalo);
    #endif
    #ifdef ANDROID
        /**
         * TODO: Resolver problema ou aplicar valor delta para renderização
         *
         * Deve-se melhorar a implementação do delay, pois para o android devido ao clock de processamento o mesmo 
         * possui um atraso de processamento de 10 milisegundos
         */
        if(intervalo > 10)intervalo -= 10;
        else intervalo = 0;
        SDL_Delay(intervalo);
	#else 
        SDL_Delay(intervalo);
   	#endif
}