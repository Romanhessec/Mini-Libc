#include <string.h>

char *strcpy(char *destination, const char *source)
{
    char *ptr = destination;
	for (; *source != '\0'; *destination++ = *source++); 
	*destination = '\0';
 	
	return ptr;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	size_t i = 0;
	for (; len; len--, *destination++ = *source++);
	return destination;
}

char *strcat(char *destination, const char *source)
{
	char* ptr = destination + strlen(destination);
	
	for (; *source != '\0'; *ptr++ = *source++);
    *ptr = '\0';
 
    return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char* ptr = destination + strlen(destination);
	
	for (; *source != '\0' && len--; *ptr++ = *source++);
    *ptr = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	for(; *str1 != '\0' && *str2 != '\0'; str1++, str2++){
		if (*str1 > *str2)
            return 1;
        else if (*str1 < *str2)
			return -1;
	}
	if (*str1 == '\0' && *str2 != '\0')
		return -1;
	else if (*str1 != '\0' && *str2 == '\0')
		return 1;
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	for (; len && *str1 && (*str1 == *str2); len--, str1++, str2++);
	return (len == 0) ? 0 : *str1 - *str2;
}

size_t strlen(const char *str)
{
	size_t i = 0;
	for (; *str != '\0'; str++, i++);

	return i;
}

char *strchr(const char *str, int c)
{
	for (; *str != c && *str; str++);
	return (*str) ? str : NULL; 
}

char *strrchr(const char *str, int c)
{
	char *lastOccurence = NULL;
	for(; *str; str++, lastOccurence = (*str == c) ? str : lastOccurence);
    return lastOccurence;
}

char *strstr(const char *haystack, const char *needle)
{
	const char *haystack2, *needle2;
	for (; *haystack; haystack++) {
		haystack2 = haystack;
		needle2 = needle;
		for(; *haystack2 && *needle2 && (*haystack2 == *needle2); haystack2++, needle2++);
		if (*needle2 == '\0')
			return haystack;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	const char *haystack2, *needle2, *lastOccurence = NULL;
    for (; *haystack; haystack++) {
        haystack2 = haystack;
        needle2 = needle;
        for(; *haystack2 && *needle2 && (*haystack2 == *needle2); haystack2++, needle2++);
		lastOccurence = (*needle2 == '\0') ? haystack : lastOccurence;
    }
    return lastOccurence;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *d = destination, *s = source;
	for (; num; num--, *d++ = *s++);
    return destination;
}

void *memmove(void *destination, const void *source, size_t num)	
{
	char *dst = destination, *src = source;

	//checking for the overlapping situations
    if (dst <= src || dst >= (src + num))
        for (; num; num--, *dst++ = *src++);
    else {
        dst += num - 1;
        src+= num - 1;
		for (; num; num--, *dst-- = *src--);
    }
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	char *p1 = ptr1, *p2 = ptr2;

	for (; num; num--, p1++, p2++){
		if (*p1 < *p2)
			return -1;
		else if (*p1 > *p2)
			return 1;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char *p = source;
	for (; num; num--, p++){
		*p = value;
	}
	return source;
}