#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main(void)
{
    
    char palavra[2];

    scanf("%s", palavra);

    printf("%s", (palavra == "á") ? "a" : palavra);

    
}