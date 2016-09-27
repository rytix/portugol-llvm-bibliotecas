#Requisitos

- llvm 3.1
- MinGW
- SDL
- NDK


#Instalação

Copiar os arquivos do llvm para a pasta do MinGW, assim como as do SDL.

#Execução 

Inicialmente deve-se acessar a pasta Windows e executar build.bat para efetuar a compilação. Após executado basta acessar a pasta test e rodar o arquivo run.bat.

O sistema irá compilar tudo para você... Não precisa se preocupar :bowtie:.

Em caso de problemas, crie uma issues neste repositório. Ficarei bastante feliz :wink:.

#Compilação para android
Deve-se efetuar a alteração do local de instalção do NDK nos arquivos /test/Makefile e /src/Makefile
```
NDK_PATH = Colocar path do arquivo
```
