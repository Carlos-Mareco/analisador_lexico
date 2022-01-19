# Analisador Léxico

A partir da string inserida como parâmetro na função `listarTokens()` em `main()`, o programa lista todos os tokens da
linguagem definida em [espeficacoes_linguagem.pdf](doc/especificacoes_linguagem.pdf) reconhecidos na string.<br>
Veja abaixo o autômato usado pelo analisador léxico:<br><br>
![automato_lexico](/doc/automato_lexico.png)<br>

## Compilação e execução

Use o compilador G++ integrante da [GCC](https://gcc.gnu.org/) (GNU Compiler Collection).
Certifique-se de estar no diretório do programa.

```bash
g++ analisador_lexico.cpp -o program
```
E para executar, ainda no mesmo diretório do programa, use :

```bash
./program
```

## Ambiente de criação e teste

**Informação do OS:** Linux Mint 20.2 Cinnamon.<br>
**Kernel do Linux:** 5.4.0-94-generic<br>
**Processador:** Intel© Core™ i7-7500U CPU @ 2.70GHz × 2.<br>
**Memória:** 7.7 GiB.<br>
**Editor/IDE:** [Visual Studio Code 1.63.2](https://code.visualstudio.com/).<br>
**Compilador:** G++ 9.3.0.<br>

## Licença

Licenciado sob a [GNU General Public License](./LICENSE).

## Condirações finais

Este programa faz parte de um dos componentes avaliativos da disciplina de Compiladores do Curso de Ciência da Computação da Universidade Federal do Amapá.