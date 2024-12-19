#include <stdio.h>
#include <string.h>

extern void *memmem(const void *haystack, size_t haystacklen, const void *needle, size_t needlelen);

int main(void)
{
	const char * a = "abc123467def";
	const char * b = "467";
	const char * c = "ghi";
	const char * d = "def";

	printf("memmem(NULL, 0, b, sizeof b): %s\n", (const char *)memmem(NULL, 0, b, strlen(b)));
	printf("memmem(%s, 0, b, sizeof b): %s\n", a, (const char *)memmem(a, 0, b, strlen(b)));
	printf("memmem(%s, %lu, NULL, 0): %s\n", a, (unsigned long)strlen(a), (const char *)memmem(a, strlen(a), NULL, 0));
	//printf("memmem(%s, %lu, NULL, %s): %lu\n", a, (unsigned long)strlen(a), (unsigned long)strlen(b), (const char *)memmem(a, strlen(a), NULL, strlen(b)));
	printf("memmem(%s, %lu, %s, %lu): %s\n", a, (unsigned long)strlen(a), b, (unsigned long)strlen(b), (const char *)memmem(a, strlen(a), b, strlen(b)));
	printf("memmem(%s, %lu, %s, %lu): %s\n", a, (unsigned long)strlen(a), c, (unsigned long)strlen(c), (const char *)memmem(a, strlen(a), c, strlen(c)));
	printf("memmem(%s, %lu, %s, %lu): %s\n", a, (unsigned long)strlen(a), d, (unsigned long)strlen(d), (const char *)memmem(a, strlen(a), d, strlen(d)));
	printf("memmem(%s, %lu, %s, %lu): %s\n", a, (unsigned long)(strlen(a)+1), d, (unsigned long)(strlen(d)+1), (const char *)memmem(a, (strlen(a)+1), d, strlen(d)+1));
	return 0;
}

