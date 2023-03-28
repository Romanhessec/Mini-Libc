#include <stdio.h>
#include <stdlib.h>

char *strcpy2(char *destination, const char *source)
{
	if (destination == NULL) 
	{
        return NULL;
    }

    char *ptr = destination;
 
    while (*source != '\0')
    {
        *destination++ = *source++;
        //destination++;
        //source++;
    }
 
    *destination = '\0';
 
    return ptr;
}

char *strncpy2(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */

	int i;
    for (i = 0; i < len && source[i] != '\0'; i++) 
	{
        destination[i] = source[i];
    }

    destination[i] = '\0';

    // for (; i < len; i++) 
	// {
    //     destination[i] = '\0';
    // }

    return destination;
}

int main()
{
    char *dest = malloc(20 * sizeof(char));
    char *source = "Salut";

    strncpy2(dest, source, 3);
    printf("%s\n", dest);
    

    return 0;
}