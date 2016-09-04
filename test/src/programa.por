programa 
{
	inclua biblioteca Graficos --> graficos
	funcao inicio () 
	{ 
		graficos.iniciar_modo_grafico(falso)
		inteiro cor = graficos.criar_cor(255, 0, 0)
		graficos.definir_cor(cor)
		
		inteiro tamanho = 300

		para(inteiro i=0; i<tamanho; i++) {
			para(inteiro j=0; j<tamanho; j++) {
				graficos.desenhar_ponto(100+i, 100+j)
				graficos.renderizar()
			}
		}


		graficos.encerrar_modo_grafico()
	} 
}