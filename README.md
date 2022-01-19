# Analisador Léxico (nível básico)

A partir da string inserida como parâmetro na função `listarTokens()` em `main()`, o programa lista todos os tokens da
linguagem definida em [espeficacoes_linguagem.pdf](doc/especificacoes_linguagem.pdf) reconhecidos na string.<br>
Veja abaixo o autômato usado pelo analisador léxico:<br><br>
![automato_lexico](/doc/automato_lexico.png)<br>

## Tabela de leximas reconhecidos

Na tabela abaixo, está especificado quais as classes de tokens que o analisador reconhece, pois, embora
seja baseado em C, não reconhece todas as palavras reservadas e algumasexpressões da linguagem, visto 
que resultaria em um programa bastante complexo.

Classe do token | Descrição da classe | Expressão reconhecida
:-------------- | :------------------ | :--------------------
ID | Identificador | “a”, “ab0”, “Abc”, “abC123”
CONST_INT | Um número inteiro não<br> negativo | “12”, “15”, “27”, “19”, “01”
CONST_FLOAT | Um número real não<br> negativo | “10.2”, “0.5”, “00.1”, “.001”
LITERAL | Qualquer caractere<br> alfanumérico entre aspas| “\” caractere 39\””
OPER_ATRIB | Operação de atribuição| “=”
OPER_RELAC | Operadores relacionais | “==”, “<=”, “>=”, “!=”
OPER_ARIT | Operadores aritméticos | “+”, “-”, “*”, “/”
OPER_BOOL | Operador booleano | “!”
DELIM | Delimitadores | “,”, “;”
CARAC_ESPEC | Caracteres especiais | “(”, “)”, “[“, “]”, “{“, “}”
IF | Palavra reservada: if | “if”
FOR | Palavra reservada: for | “for”
INT | Palavra reservada: int | “int”

## Compilação e execução

Através do terminal, escolha um local onde será salvo os arquivos e use:<br>
```bash
git clone https://github.com/Carlos-Mareco/analisador_lexico.git
```

Use o compilador G++ integrante da [GCC](https://gcc.gnu.org/) (GNU Compiler Collection).
Certifique-se de estar no diretório do programa.

```bash
g++ analisador_lexico.cpp -o program
```
E para executar, ainda no mesmo diretório do programa, use :

```bash
./program
```

## Uso do programa

Para usar o analisador léxico é necessário, antes de cada compilação e execução, modificar o parâmetro da 
função `listarTokens()` em `main()` de [analisador_lexico.cpp](analisador_lexico.cpp), veja abaixo um exemplo
pré-definido:<br>
```cpp
int main(){
    listarTokens("for(int i = 0; i < 10; i=i+1)");

    return 0;
}
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

## Considerações finais

Este programa faz parte de um dos componentes avaliativos da disciplina de Compiladores do Curso de Ciência da Computação da Universidade Federal do Amapá.
