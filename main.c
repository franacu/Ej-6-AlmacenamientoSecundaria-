//Escribir un programa que cuente la cantidad de palabras en un archivo.
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main()
{
    char *archivo="ejercicio6.txt";
    FILE *fp;
    fp= fopen(archivo,"a");
    if(fp==NULL)
    {
        printf("No se abrio con exito\n");
        return -1;
    }else
        {
            printf("Se abrio con exito\n");

            fprintf(fp,"Palabra1 palabra2 palabra3\n");
            fclose(fp);
        }
    fopen(archivo,"r");
    int cont=0;
    char palabra[256];
    while (fgets(palabra, sizeof(palabra), fp) != NULL) {
        char *token = strtok(palabra, " \t\n");  // Divide la línea en palabras
        while (token != NULL) {
            cont++;
            token = strtok(NULL, " \t\n");  // Obtener la siguiente palabra
        }
    }
    printf("Contador de palabras: %d",cont);
    return 0;
}
