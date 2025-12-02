#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>

int main(void)
{
    setlocale(LC_ALL, "");
    wchar_t frase[510];

    while (fgetws(frase, sizeof(frase), stdin) != NULL)
    {
        int j = 0;
        int k;
        char semespaco[510];
        char inverte[510];

        for (int i = 0; frase[i] != L'\0'; i++)
        {
            if (frase[i] >= L'a' && frase[i] <= L'z')
            {
                semespaco[j] = (char)frase[i];
                j++;

            } else if (frase[i] >= L'A' && frase[i] <= L'Z')
            {
                semespaco[j] = (char)(frase[i] + 32);
                j++;
            } else if (frase[i] == L'í' || frase[i] == L'Í')
            {
                semespaco[j] = 'i';
                j++;
            } else if (frase[i] == L'é' || frase[i] == L'ê' || frase[i] == L'É' || frase[i] == L'Ê')
            {
                semespaco[j] = 'e';
                j++;
            } else if (frase[i] == L'ó' || frase[i] == L'õ' || frase[i] == L'ô'|| frase[i] == L'Ó'|| frase[i] == L'Õ'||frase[i] == L'Ô')
            {
                semespaco[j] = 'o';
                j++;
            } else if (frase[i] == L'ú'||frase[i] == L'Ú')
            {
                semespaco[j] = 'u';
                j++;
            } else if (frase[i] == L'á' || frase[i] == L'à' || frase[i] == L'ã'|| frase[i] == L'â'|| frase[i] == L'Á'||frase[i] == L'À'||frase[i] == L'Ã'||frase[i] == L'Â')
            {
                semespaco[j] = 'a';
                j++;
            } else if (frase[i] == L'Ç' || frase[i] == L'ç')
            {
                semespaco[j] = 'c';
                j++;
            }
        }

        semespaco[j] = '\0';

        for(k = 0; semespaco[k] != '\0'; k++)
        {   
            j--;
            inverte[k] = semespaco[j];
            
        }

        inverte[k] = '\0';



        if (!strcmp(inverte, semespaco))
        {
            printf("sim\n");
        } else
        {
            printf("nao\n");
        }
        

    }
}



