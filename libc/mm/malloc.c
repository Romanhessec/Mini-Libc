// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    mem_list_add(ptr, size);
    return ptr; 
}

void *calloc(size_t nmemb, size_t size)
{
	void* ptr = malloc(nmemb * size);
	memset(ptr, 0, nmemb * size);
	return ptr;
}

void free(void *ptr)
{
    struct mem_list *item = mem_list_extract(ptr);
    munmap(item->start, item->len);
    mem_list_free(item);
}

void *realloc(void *ptr, size_t size)
{
    void* buffer = mremap(ptr, sizeof(size_t), size, MREMAP_MAYMOVE);
    return buffer;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	return realloc(ptr, nmemb*size);
}
