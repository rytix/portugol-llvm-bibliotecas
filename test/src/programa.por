

/* CLIQUE NO SINAL DE "+", � ESQUERDA, PARA EXIBIR A DESCRI��O DO EXEMPLO
 *  
 * Copyright (C) 2014 - UNIVALI - Universidade do Vale do Itaja�
 * 
 * Este arquivo de c�digo fonte � livre para utiliza��o, c�pia e/ou modifica��o
 * desde que este cabe�alho, contendo os direitos autorais e a descri��o do programa, 
 * seja mantido.
 * 
 * Se tiver dificuldade em compreender este exemplo, acesse as v�deoaulas do Portugol 
 * Studio para auxili�-lo:
 * 
 * https://www.youtube.com/watch?v=K02TnB3IGnQ&list=PLb9yvNDCid3jQAEbNoPHtPR0SWwmRSM-t
 * 
 * Descri��o:
 * 
 * 	Este exemplo � um Jogo escrito em Portugol no qual o jogador controla uma nave que
 * 	deve pousar na lua o mais r�pido poss�vel. O exemplo demonstra como utilizar algumas 
 * 	das bibliotecas existentes no Portugol. Neste exemplo, tamb�m � poss�vel ver algumas
 * 	t�cnicas utilizadas na cria��o de jogos.
 *	
 *	As regras do jogo s�o as sguintes:
 *	
 *		a) O jogador perde se guiar a nave para fora da tela
 *		b) O jogador perde se pousar a nave fora da plataforma de pouso
 *		c) O jogador perde se pousar a nave muito r�pido
 * 	
 *   Jogo adaptado de http://www.gametutorial.net/article/Keyboard-input---Moon-lander
 * 	
 * Autores:
 * 
 * 	Fillipi Domingos Pelz
 *   Luiz Fernando Noschang (noschang@univali.br)
 *   
 * Data: 08/09/2013
 */
 
programa
{
	inclua biblioteca Graficos --> g
	inclua biblioteca Teclado --> t
	inclua biblioteca Util --> u
	inclua biblioteca Tipos --> tp
	inclua biblioteca Matematica --> m

	/* Dimens�es da tela do jogo */ 
	inteiro LARGURA_TELA = 640, ALTURA_TELA = 480

	/* Constantes para controle da f�sica do jogo */
	const real ACELERACAO_GRAVIDADE = 0.18, VELOCIDADE_MAXIMA_GRAVIDADE = 4.5
	
	const real ACELERACAO_FOGUETE = 0.20, VELOCIDADE_MAXIMA_FOGUETE = 20.0
	
	const real PERCENTUAL_VELOCIDADE_HORIZONTAL = 1.0, VELOCIDADE_MAXIMA_POUSO = 2.50

	/* Constantes que armazenam as dimens�es das imagens utilizadas no jogo */
	const inteiro ALTURA_FOGUETE = 76, LARGURA_FOGUETE = 59, LARGURA_PLATAFORMA = 135

	/* Define quantos quadros ser�o desenhados por segundo (FPS) */
	const inteiro TAXA_ATUALIZACAO = 85

	

	/* Vari�veis que armazenam a posi��o dos objetos no jogo */
	inteiro x_foguete = 0, y_foguete = 0, x_plataforma = 250, y_plataforma = 420

	/* Vari�veis utilizadas para controlar a velocidade de foguete */
	real velocidade_vertical = 0.0, velocidade_horizontal = 0.0
	
	/* Vari�veis utilizadas para controlar o estado do foguete */
	logico acelerando = falso, quebrou = falso, pousou = falso, foi_para_o_espaco = falso


	/* Vari�veis utilizadas para controlar o FPS e o tempo de jogo */
	inteiro tempo_inicio_jogo = 0, tempo_total_jogo = 0

	inteiro tempo_inicio = 0, tempo_decorrido = 0, tempo_restante = 0, tempo_quadro = 1, tempo_atualizacao=0, tempo=0, quadros=0
	
	
	/* Vari�veis que armazenam o endere�o de mem�ria das imagens utilizadas no jogo */
	inteiro imagem_fundo = 0, imagem_menu = 0, imagem_foguete = 0, imagem_lua=0, imagem_planetas=0
	
	inteiro imagem_jato2 = 0, imagem_foguete_quebrado = 0, imagem_jato = 0, imagem_plataforma = 0, imagem_fogo = 0
	inteiro indice_fogo = 0
	logico atualizou = falso

	inteiro indice_fundo=0, ultimo_giro_fundo=0
	inteiro indice_planetas=0, ultimo_giro_planetas=0

	funcao jogo()
	{
		reiniciar()

		enquanto (nao t.tecla_pressionada(t.TECLA_ESC))
		{
			tempo_inicio = u.tempo_decorrido()
			desenhar()

			tempo_decorrido = u.tempo_decorrido() - tempo_inicio
			tempo_atualizacao += tempo_decorrido
			se(tempo_atualizacao > 20)
			{
				atualizar()
				tempo_atualizacao = 0
			}
			
			
			tempo += tempo_decorrido
			quadros++
			se (TAXA_ATUALIZACAO > 0  e tempo_restante > 0)
			{
				u.aguarde(tempo_restante)
				//escreva("FPS:", quadros, "\n")
				quadros=0
			}
		}
	}

	funcao atualizar()
	{
	 	//g.renderizar()
		se (nao pousou e nao quebrou e nao foi_para_o_espaco)
		{
			atualizar_velocidade_vertical()
			atualizar_velocidade_horizontal()
			atualizar_posicao_foguete()
			atualizar_estado_foguete()
		}
		senao
		{
			se (t.tecla_pressionada(t.TECLA_SETA_ACIMA))
			{
				reiniciar()
			}
		}
	}

	funcao atualizar_velocidade_vertical()
	{
            se (t.tecla_pressionada(t.TECLA_W) ou t.tecla_pressionada(t.TECLA_SETA_ACIMA))
            {
	     	velocidade_vertical -= ACELERACAO_FOGUETE

	     	se (velocidade_vertical < -VELOCIDADE_MAXIMA_FOGUETE)
	     	{
                    velocidade_vertical = -VELOCIDADE_MAXIMA_FOGUETE
	     	}
	     	
	          acelerando = verdadeiro
	     }
	     senao
	     {
			velocidade_vertical += ACELERACAO_GRAVIDADE

			se (velocidade_vertical > VELOCIDADE_MAXIMA_GRAVIDADE)
			{
				velocidade_vertical = VELOCIDADE_MAXIMA_GRAVIDADE
			}
			
			acelerando = falso
		}
	}

	funcao atualizar_velocidade_horizontal()
	{
		se (t.tecla_pressionada(t.TECLA_A) ou t.tecla_pressionada(t.TECLA_SETA_ESQUERDA))
		{
			velocidade_horizontal -= (ACELERACAO_FOGUETE * PERCENTUAL_VELOCIDADE_HORIZONTAL)
		}
		senao se(velocidade_horizontal < 0.0)
		{
			velocidade_horizontal += (ACELERACAO_GRAVIDADE * PERCENTUAL_VELOCIDADE_HORIZONTAL)
		}
	
		se (t.tecla_pressionada(t.TECLA_D) ou t.tecla_pressionada(t.TECLA_SETA_DIREITA))
		{
			velocidade_horizontal += (ACELERACAO_FOGUETE * PERCENTUAL_VELOCIDADE_HORIZONTAL)
		}
		senao se(velocidade_horizontal > 0.0)
		{
			velocidade_horizontal -= (ACELERACAO_GRAVIDADE * PERCENTUAL_VELOCIDADE_HORIZONTAL)
		}
	}

	funcao atualizar_posicao_foguete()
	{
		x_foguete += m.arredondar(velocidade_horizontal, 1)
		y_foguete += m.arredondar(velocidade_vertical, 1)
	}

	funcao atualizar_estado_foguete()
	{
		se (x_foguete + LARGURA_FOGUETE < 0 ou x_foguete > LARGURA_TELA ou y_foguete + ALTURA_FOGUETE < 0)
		{
			foi_para_o_espaco = verdadeiro
		}
		senao se (y_foguete + ALTURA_FOGUETE - 10 > y_plataforma)
		{
			se ((x_foguete > x_plataforma) e (x_foguete < x_plataforma + LARGURA_PLATAFORMA - LARGURA_FOGUETE))
            	{
				se (velocidade_vertical <= VELOCIDADE_MAXIMA_POUSO)
				{
					pousou = verdadeiro
					tempo_total_jogo = u.tempo_decorrido() - tempo_inicio_jogo
				}
                	senao
                	{
                    	quebrou = verdadeiro
            		}
            	}
            	senao
            	{
                	se(y_foguete + ALTURA_FOGUETE > tp.real_para_inteiro(ALTURA_TELA - 57 + m.valor_absoluto(400.0-x_foguete+ (LARGURA_FOGUETE / 2))/7))
                	{
                    	quebrou = verdadeiro
            		}
            	}
		}
	}

	funcao desenhar_fundo(){
				
		se(indice_fundo>LARGURA_TELA)
		{
			g.desenhar_porcao_imagem(0, 0, indice_fundo, 0, LARGURA_TELA-(indice_fundo-LARGURA_TELA), ALTURA_TELA, imagem_fundo)
			g.desenhar_porcao_imagem(LARGURA_TELA-(indice_fundo-LARGURA_TELA), 0, 0, 0, LARGURA_TELA, ALTURA_TELA, imagem_fundo)
		}
		senao{
			g.desenhar_porcao_imagem(0, 0, indice_fundo, 0, LARGURA_TELA, ALTURA_TELA, imagem_fundo)
		}
		se(tempo_inicio -ultimo_giro_fundo>35){
			indice_fundo= (indice_fundo+1)%(LARGURA_TELA*2)
			ultimo_giro_fundo = tempo_inicio
		}
	}
	funcao desenhar_planetas(){
		

		se(indice_planetas>LARGURA_TELA)
		{
			g.desenhar_porcao_imagem(0, 0, indice_planetas, 0, LARGURA_TELA-(indice_planetas-LARGURA_TELA), ALTURA_TELA, imagem_planetas)
			g.desenhar_porcao_imagem(LARGURA_TELA-(indice_planetas-LARGURA_TELA), 0, 0, 0, LARGURA_TELA, ALTURA_TELA, imagem_planetas)
		}
		senao
		{
			g.desenhar_porcao_imagem(0, 0, indice_planetas, 0, LARGURA_TELA, ALTURA_TELA, imagem_planetas)
		}
		se(tempo_inicio -ultimo_giro_planetas>100){
			indice_planetas= (indice_planetas+1)%(LARGURA_TELA*2)
			ultimo_giro_planetas = tempo_inicio
			//escreva("Imagem: %d", indice_planetas)
		}
	}
	funcao desenhar()
	{
		desenhar_fundo()
		desenhar_planetas()
		
		g.desenhar_imagem(LARGURA_TELA/2 - 400, ALTURA_TELA-70, imagem_lua)
		g.desenhar_imagem(x_plataforma, y_plataforma, imagem_plataforma)
		
		se (pousou)
    		{
        		desenhar_sombra_foguete()	
			g.desenhar_imagem(x_foguete, y_foguete, imagem_foguete)
		}
		senao se (quebrou)
		{
			se(tempo_inicio%150 < 75){
				se(nao atualizou){
					indice_fogo = (indice_fogo+1)%6
					atualizou = verdadeiro
				}
			}senao{
				atualizou = falso
			}
	        	g.desenhar_imagem(x_foguete, y_foguete + ALTURA_FOGUETE - 43, imagem_foguete_quebrado)
	        	g.desenhar_porcao_imagem(x_foguete+20, y_foguete + ALTURA_FOGUETE - 30, indice_fogo*30, 0, 30, 45, imagem_fogo)
			g.definir_cor(0xFFFFFF)
		}
		senao
    		{
    			desenhar_sombra_foguete()
			se (acelerando)
			{
				se(tempo_inicio%100 <50){
					g.desenhar_imagem(x_foguete + 10, y_foguete + 66, imagem_jato)
				}senao{
					g.desenhar_imagem(x_foguete + 10, y_foguete + 66, imagem_jato2)
				}
			}

			g.desenhar_imagem(x_foguete, y_foguete, imagem_foguete)
    		}

		//g.desenhar_imagem(x_foguete, y_foguete, imagem_foguete)
		g.renderizar()
	}


	funcao desenhar_sombra_foguete()
	{
		inteiro x_centro_foguete = x_foguete + (LARGURA_FOGUETE / 2)
		inteiro distancia_plataforma = (y_foguete + ALTURA_FOGUETE) - y_plataforma - 11
		
		inteiro largura_sombra = LARGURA_FOGUETE + (distancia_plataforma / 10)
		inteiro altura_sombra = largura_sombra / 10

		inteiro x_sombra = x_centro_foguete - (largura_sombra / 2)
		inteiro y_sombra = tp.real_para_inteiro(ALTURA_TELA - 57 + m.valor_absoluto(400.0-x_centro_foguete)/7)
		
		g.definir_cor(g.COR_PRETO)
		g.desenhar_elipse(x_sombra, y_sombra, largura_sombra, altura_sombra, verdadeiro)
	}

	funcao reiniciar()
	{
		x_foguete = u.sorteia(10, LARGURA_TELA-10)
		y_foguete = 0
		acelerando = falso
		pousou = falso
		quebrou = falso
		foi_para_o_espaco = falso
		velocidade_vertical = 0.0
		velocidade_horizontal = 0.0
		tempo_inicio_jogo = u.tempo_decorrido()
		tempo_total_jogo = 0
	}

	funcao carregar_imagens()
	{
            imagem_lua = g.carregar_imagem("moon.png")
            imagem_fundo = g.carregar_imagem("fundo.jpg")
            imagem_planetas = g.carregar_imagem("planetas.png")
            imagem_menu = g.carregar_imagem("menu.jpg")
            imagem_foguete = g.carregar_imagem("foguete.png")
            imagem_jato = g.carregar_imagem("jato_foguete1.png")
            imagem_plataforma = g.carregar_imagem("plataforma_pouso.png")
            imagem_jato2 = g.carregar_imagem("jato_foguete2.png")
            imagem_foguete_quebrado = g.carregar_imagem("foguete_quebrado.png")
            imagem_fogo = g.carregar_imagem("fogo.png")
	}

	funcao liberar_imagens()
	{
		g.liberar_imagem(imagem_planetas)
		g.liberar_imagem(imagem_lua)
		g.liberar_imagem(imagem_fundo)
		g.liberar_imagem(imagem_menu)
		g.liberar_imagem(imagem_foguete)
		g.liberar_imagem(imagem_jato)
		g.liberar_imagem(imagem_plataforma)
		g.liberar_imagem(imagem_jato2)
		g.liberar_imagem(imagem_foguete_quebrado)
		g.liberar_imagem(imagem_fogo)
	}

	funcao inicializar()
	{
		g.iniciar_modo_grafico(verdadeiro)
		LARGURA_TELA = g.largura_janela()
		ALTURA_TELA = g.altura_janela()
		x_plataforma = LARGURA_TELA/2-60
		y_plataforma = ALTURA_TELA-50
	}

	funcao finalizar()
	{
		liberar_imagens()
		g.encerrar_modo_grafico()
	}
	
	funcao inicio()
	{
		inicializar()
		carregar_imagens()
		jogo()
		finalizar()
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta se��o do arquivo guarda informa��es do Portugol Studio.
 * Voc� pode apag�-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 4089; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */