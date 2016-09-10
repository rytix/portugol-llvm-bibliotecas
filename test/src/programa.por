programa 
{
	inclua biblioteca Graficos --> graficos
	inclua biblioteca Util --> util
	
	funcao inicio () 
	{ 
		graficos.iniciar_modo_grafico(falso)
		inteiro cor = graficos.criar_cor(100, 0, 0)
		graficos.definir_cor(cor)
		graficos.limpar()
		graficos.renderizar()

		inteiro cor1 = graficos.criar_cor(255, 255, 255)
		graficos.definir_cor(cor1)
		para(inteiro i=0; i<200; i++) {
			para(inteiro j=0; j<100; j++){
				graficos.desenhar_ponto(50+i, 50+j)
			}
			//util.aguarde(10)
			graficos.renderizar()
		}
		graficos.renderizar()
		util.aguarde(10000)

		//inteiro foguete = graficos.carregar_imagem("foguete.png")
		//graficos.limpar()
		//graficos.desenhar_imagem(250, 400, foguete)
		

		//escreva("Preparando para lançar foguete...\n")
		//escreva("5...\n")
		//util.aguarde(1000)
		//escreva("4...\n")
		//util.aguarde(1000)
		//escreva("3...\n")
		//util.aguarde(1000)
		//escreva("2...\n")
		//util.aguarde(1000)
		//escreva("1...\n")
		//util.aguarde(10000)
		

		//para(inteiro i=0; i < 1000; i++){
			//graficos.limpar()
			//util.aguarde(10)
			//graficos.desenhar_imagem(250, 400-i, foguete)
			//graficos.renderizar()
		//}
		
		graficos.encerrar_modo_grafico()
	} 
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 354; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */