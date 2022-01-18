/**
 * @file analisador_lexico.cpp
 * @author Carlos Henrique Barreto Mareco
 * @date 11 Jan 2022
 * @link https://github.com/Carlos-Mareco/ @endlink
 */
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

typedef struct token {
    string palavra;
    int tipo = 0;
} toke;

void listarTokens(string ent);
string formataEntrada(string entrada);
vector<token> coletaTokens(vector<token> entToken, string entrada);
string classifToken(int tipo);
token automatoAnalisadorLexico(token entrada);

int main(){
    listarTokens("for(int i = 0; i < 10; i=i+1)");

    return 0;
}

void listarTokens(string entrada){
    entrada = formataEntrada(entrada);
    vector<token> tokens;
    
    tokens = coletaTokens(tokens, entrada);

    for(int i = 0; i < tokens.size(); i++){
        tokens[i] = automatoAnalisadorLexico(tokens[i]);
    }
    
    for(int i = 0; i < tokens.size(); i++){
        cout << tokens[i].palavra << "\t"<< classifToken(tokens[i].tipo) << endl;
    }
}

string classifToken(int tipo){
    string aux;
    switch (tipo){
        case 1:  aux = "ID";          break;
        case 2:  aux = "CONST_INT";   break;
        case 3:  aux = "CONST_FLOAT"; break;
        case 4:  aux = "OPER_ATRIB";  break;
        case 5:  aux = "OPER_RELAC";  break;
        case 6:  aux = "OPER_ARIT";   break;
        case 7:  aux = "DELIM";       break;
        case 8:  aux = "CARAC_ESPEC"; break;
        case 9:  aux = "IF";          break;
        case 10: aux = "FOR";         break;
        case 11: aux = "INT";         break;
        case 12: aux = "LITERAL";     break;
        case 13: aux = "OPER_BOOL";   break;

        default: aux = "ERRO";        break;
    }
    return aux;
}

token automatoAnalisadorLexico(token entrada){
    int estado = 0;
    string aux = entrada.palavra;
    
    for(int pos = 0; pos <= aux.size(); pos++){
        switch (estado){
            case 0: // estado q0
                if(isalpha(aux[pos])){
                    if(aux[pos] == 'i')
                        estado = 1;
                    else if(aux[pos] == 'f')
                        estado = 5;
                    else
                        estado = 8;
                } else if(isdigit(aux[pos])){
                    estado = 10;
                } else if(aux[pos] == '='){
                    estado = 15;
                } else if(aux[pos] == '<' || aux[pos] == '>'){
                    estado = 19;
                } else if(aux[pos] == ',' || aux[pos] == ';'){
                    estado = 17;
                } else if(aux[pos] == '('  || aux[pos] == ')' || aux[pos] == '[' || aux[pos] == ']' ||
                          aux[pos] == '{' || aux[pos] == '}'){
                    estado = 18;
                } else if(aux[pos] == '+' || aux[pos] == '-' || aux[pos] == '*' || aux[pos] == '/'){
                    estado = 14;
                } else if(aux[pos] == '!'){
                    estado = 22;
                } else if(aux[pos] == '\"'){
                    estado = 20;
                } else {
                    pos = aux.size() + 1;
                }
            break;

            case 1: // estado q1
                if(aux[pos] == 'f')
                    estado = 2;
                else if(aux[pos] == 'n')
                    estado = 3;
                else if(isalnum(aux[pos]))
                    estado = 8;
                else if(aux[pos] == '\0')
                    entrada.tipo = 1;
                else
                    pos = aux.size() + 1;
            break;
            case 2: // estado q2
                if(aux[pos] == '\0')
                    entrada.tipo = 9;
                else if(isalnum(aux[pos]))
                    estado = 8;
                else
                    pos = aux.size() + 1;
            break;

            case 3: // estado q3
                if(aux[pos] == 't')
                    estado = 4;
                else if(isalnum(aux[pos]))
                    estado = 8;
                else
                    pos = aux.size() + 1;
            break;
            case 4: // estado q4
                if(aux[pos] == '\0')
                    entrada.tipo = 11;
                else if(isalnum(aux[pos]))
                    estado = 8;
                else
                    pos = aux.size() + 1;
            break;

            case 5: // estado q5
                if(aux[pos] == 'o')
                    estado = 6;
                else if(isalnum(aux[pos]))
                    estado = 8;
                else if(aux[pos] == '\0')
                    entrada.tipo = 1;
                else
                    pos = aux.size() + 1;
            break;
            case 6: // estado q6
                if(aux[pos] == 'r')
                    estado = 7;
                else if(isalnum(aux[pos]))
                    estado = 8;
                else
                    pos = aux.size() + 1;
            break;
            case 7: // estado q7
                if(aux[pos] == '\0')
                    entrada.tipo = 10;
                else if(isalnum(aux[pos]))
                    estado = 8;
                else
                    pos = aux.size() + 1;
            break;

            case 8: // estado q8
                if(aux[pos] == '\0')
                    entrada.tipo = 1;
                else if(isalnum(aux[pos]))
                    estado = 9;
                else
                    pos = aux.size() + 1;
            break;
            case 9: // estado q9
                if(aux[pos] == '\0')
                    entrada.tipo = 1;
                else if(isalnum(aux[pos]))
                    estado = 9;
                else
                    pos = aux.size() + 1;
            break;

            case 10: // estado q10
                if(aux[pos] == '\0')
                    entrada.tipo = 2;
                else if(isdigit(aux[pos]))
                    estado = 10;
                else if(aux[pos] == '.')
                    estado = 11;
                else
                    pos = aux.size() + 1;
            break;
            case 11: // estado q11
                if(isdigit(aux[pos]))
                    estado = 12;
                else
                    pos = aux.size() + 1;
            break;
            case 12: // estado q12
                if(aux[pos] == '\0')
                    entrada.tipo = 3;
                else if(isdigit(aux[pos]))
                    estado = 12;
                else
                    pos = aux.size() + 1;
            break;

            case 13: // estado q13
                if(isdigit(aux[pos]))
                    estado = 12;
                else
                    pos = aux.size() + 1;
            break;

            case 14: // estado q14
                if(aux[pos] == '\0')
                    entrada.tipo = 6;
                else
                    pos = aux.size() + 1;
            break;
            
            case 15: // estado q15
                if(aux[pos] == '\0')
                    entrada.tipo = 4;
                else if(aux[pos] == '=')
                    estado = 16;
                else
                    pos = aux.size() + 1;
            break;
            case 16: // estado q16
                if(aux[pos] == '\0')
                    entrada.tipo = 5;
                else
                    pos = aux.size() + 1;
            break;

            case 17: // estado q17
                if(aux[pos] == '\0')
                    entrada.tipo = 7;
                else
                    pos = aux.size() + 1;
            break;

            case 18: // estado q18
                if(aux[pos] == '\0')
                    entrada.tipo = 8;
                else
                    pos = aux.size() + 1;
            break;

            case 19: // estado q19
                if(aux[pos] == '\0')
                    entrada.tipo = 5;
                else if(aux[pos] == '=')
                    estado = 16;
                else
                    pos = aux.size() + 1;
            break;

            case 20: // estado q20
                if(isalnum(aux[pos]) || isblank(aux[pos])){
                    estado = 20;
                }
                else if(aux[pos] == '\"')
                    estado = 21;
                else
                    pos = aux.size() + 1;
            break;

            case 21: // estado q21
                if(aux[pos] == '\0')
                    entrada.tipo = 12;
                else
                    pos = aux.size() + 1;
            break;

            case 22: // estado q22
                if(aux[pos] == '\0')
                    entrada.tipo = 13;
                else if(aux[pos] == '=')
                    estado = 16;
                else
                    pos = aux.size() + 1;
            break;

            default:
                break;
        }
    }
    return entrada;
}

vector<token> coletaTokens(vector<token> entToken, string entrada){
    token aux;
    aux.palavra = "";
    for(int i = 0; i < entrada.length(); i++){
        if(!isspace(entrada[i]) && entrada[i] != '\"'){
            aux.palavra += entrada[i];
        } else if(entrada[i] == '\"'){
            do{
                aux.palavra += entrada[i];
                i++;
            } while(entrada[i] != '\"' && i < entrada.length());
            aux.palavra += entrada[i];
            entToken.push_back(aux);
            aux.palavra = "";
        } else {
            if(aux.palavra != " " && aux.palavra.size() > 0){
                entToken.push_back(aux);
            }
            aux.palavra = "";
        }
    }
    return entToken;
}

string formataEntrada(string ent){
    string temp = "";

    for(int i = 0; i < ent.length(); i++){
        if(ent[i] == '(' || ent[i] == ')' || ent[i] == '[' || ent[i] == ']' || ent[i] == '{' || ent[i] == '}' ||
           ent[i] == ',' || ent[i] == ';' || ent[i] == '=' || ent[i] == '<' || ent[i] == '>' || ent[i] == '\"' || 
           ent[i] == '!' || ent[i] == '+' || ent[i] == '-' || ent[i] == '*' || ent[i] == '/'){
            if(ent[i+1] != '=') {
                temp += " ";
                temp += ent[i];
                temp += " ";
            } else {
                temp += " ";
                temp += ent[i];
                temp += ent[i+1];
                temp += " ";
                i++;
            }
        } else {
            temp += ent[i];
        }
    }
    return temp;
}