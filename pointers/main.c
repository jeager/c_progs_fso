#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){

    double number1 = 7.3, number2;
    char s1[100], s2[100];

    /* Declare a variável dPtr como ponteiro para a variável do tipo double */
    double *dPtr;

    /* Carregue o endereço da variável number1 no ponteiro dPtr */
    dPtr = &number1;

    /* Imprima em tela o valor da variável apontada por dPtr partindo do ponteiro. */
    printf("Valor: %lf\n", *dPtr);

    /* Carregue o valor da variável apontada por dPrt na variável number2. */
    number2 = *dPtr;

    /* Imprima o valor armazenado em number2. */
    printf("Valor number2: %lf\n", number2);
    /* Imprima o endereço de number1 na tela. */
    printf("Endereco number1: %p\n", &number1);
    /* Imprima o endereço armazenado em dPtr na tela. */
    printf("Endereco dPtr: %p\n", dPtr);

    /* O valor impresso decorrente do enunciado que contempla 
    o item anterior é igual ao valor do endereço gravado em dPrt?

    Não, ja que o valor de dPtr é um ponteiro para o endereço de number1 */

    /* Leia uma string e a armazene no array s1 */
    printf("Inserir string: ");
    scanf("%s", s1);

    /*  Copie a string armazenada em s1 para s2 */
    strcpy(s2, s1);

    /* Compare a string armazenada em s1 com a string 
    armazenada em s2 imprima o resultado na tela. */
    printf("Comparacao entre s1 e s2: %d\n", strcmp(s1, s2));

    /* Apense a string s2 à string s1. */
    strcat(s1, s2);
    /* Imprima o resultado na tela */
    printf("s1 e s2 concatenados: %s\n", s1);

    /* A execução do item anterior pode provocar algum erro em tempo de execução?
    A execução pode ser afetada caso o tamanho de s1 seja insuficiente para alocar as 2 strings. */

    /* Determine o comprimento da string armazenada em s1 e imprima o resultado na tela.*/
    printf("Tamanho de s1 eh: |%d|\n", (int)strlen(s1));

    return 0;
}