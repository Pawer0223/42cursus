#include "libft.h"
#include <stdio.h>
#include <string.h>

void	memccpy_test(char *argv[])
{
	int dstSize = atoi(argv[2]);
	char *src = argv[3];
	char  c = argv[4][0];
	size_t n = atoi(argv[5]);

	printf("### dstSize : [%d], src: [%s], c: [%c], size: [%zu] ### \n", dstSize,src,c,n);

	char *dest = (char *)malloc(sizeof(char) * dstSize);
	char *result = ft_memccpy(dest, src, c, n);

	if (!result)
		printf("[%c] is not found !!\n", c);
	else
	{
		printf("dest : [%s], result : [%s] \n", dest, result);
		printf("dest : [%p], result : [%p] \n", dest, result);
	}
	free(dest);
}

void	strlcat_test(char *argv[])
{
	size_t r1;
	size_t r2;
	printf("### [ Basic Return Value Test .. ] ###\n");


	printf("[1] ["", abc , 0] \n");
	
	r1 = ft_strlcat("", "abc", 0);
	r2 = strlcat("", "abc",0);
	printf(" my : [%zu], lib [%zu]\n", r1, r2);
	
	printf("[2] [abc, "", 0] \n");
	r1 = ft_strlcat("abc", "", 0);
	r2 = strlcat("abc", "",0);
	printf(" my : [%zu], lib [%zu]\n", r1, r2);

	char *d1 = (char *)malloc(sizeof(char) * 3);
	char *d2 = (char *)malloc(sizeof(char) * 3);
	printf("[3] [malloc size 3 dst, append , 7]\n");
	r1 = ft_strlcat(d1, "append", 7);
	r2 = strlcat(d2, "append",7);
	printf("my : [%s], result : [%s] /// return => my : [%zu], lib : [%zu] \n",d1, d2, r1, r2);
	free(d1);
	free(d2);

	printf("\ncheck please [ft_strlcat(NULL, def, 10)] .. is seqmentation fault !! \n");
	// printf("[3] [NULL, def, 10] \n");
	// r1 = ft_strlcat(NULL, "def", 10);
	// r2 = strlcat(NULL, "def",10);
	// printf(" my : [%zu], lib [%zu]\n", r1, r2);

	printf("check please [ft_strlcat(abc, NULL, 10)] .. is Exception ! \n");

	// printf("[4] [def, NULL, 10] \n");
	// r1 = ft_strlcat("def", NULL, 10);
	// r2 = strlcat("def", NULL, 10);
	// printf(" my : [%zu], lib [%zu]\n", r1, r2);
	
	printf("\n\n### [ user input Test .. ] ###\n");
	
	int size = atoi(argv[4]);
	printf("####### strlcat(%s, %s, %d) ##########\n", argv[2], argv[3], size);
	char *dst2 = (char *)malloc(sizeof(char) * 100);
	char *src2 = (char *)malloc(sizeof(char) * 100);

	strlcpy(dst2, argv[2], strlen(argv[2]) + 1);
	strlcpy(src2, argv[3], strlen(argv[3]) + 1);

	r1 = ft_strlcat(argv[2], argv[3],size);
	r2 = strlcat(dst2, src2,size);


	printf("my : [%s], result : [%s] /// return => my : [%zu], lib : [%zu] \n",argv[2], dst2, r1, r2);

	free(dst2);
	free(src2);

}

void	strnstr_test(char *argv[])
{
	char *src = argv[2];
	char *find = argv[3];
	int len = atoi(argv[4]);


	printf("########## basic test ############\n");
	printf("[1] ft_strnstr(%s,%s,%d) : ", "abc def", " ", 10);
    
	char *r1 = ft_strnstr("abc def", " ", 10);
	char *r1_l = strnstr("abc def", " ", 10);
	printf(" my: [%s] , lib: [%s]\n", r1, r1_l);
	
	printf("[2] ft_strnstr(%s,%s,%d) : ", "abc def", " d", 10);
	char *r2 = ft_strnstr("abc def", " d", 10);
	char *r2_l = strnstr("abc def", " d", 10);
	printf(" my: [%s] , lib: [%s]\n", r2, r2_l);


	printf("############### user input Test ###############\n");
	char *result = ft_strnstr(src, find, len);
	printf("ft_strnstr(%s,%s,%d) : %s\n", src, find, len, result);

	
	printf("test..\n");
	
	int i = 0;
	while(find[i]){
		printf("find[%d]:%c[%d]\n",i,find[i], find[i]);
		i++;
	}

}

void	strncmp_test(char *argv[])
{
	int r1, r2, r3, r4;
	int n = atoi(argv[4]);

	printf("############### Basic Test ###############\n");

	char str1[20] = "abc";
	str1[4] = '1';
	str1[5] = '2';
	str1[6] = '3';
	char str2[20] = "abc";
	str2[4] = '4';
	str2[5] = '6';
	str2[6] = '8';

	printf("str1 : [%s], str2 : [%s]\n", str1, str2);
	r1 = ft_strncmp(str1, str2, n);
	r2 = strncmp(str1,str2,n);
	r3 = ft_memcmp(str1, str2, n);
	r4 = memcmp(str1, str2, n);
	printf("# strncmp : my : [%d], lib : [%d]\n", r1, r2);
	printf("# memcmp : my : [%d], lib : [%d]\n", r3, r4);

	printf("############### user input Test ###############\n");
	char *s1 = argv[2];
	char *s2 = argv[3];
	printf("s1: [%s], s2: [%s], n : [%d]\n",s1, s2, n);

	r1 = ft_strncmp(s1, s2, n);
	r2 = strncmp(s1,s2,n);
	r3 = ft_memcmp(s1, s2, n);
	r4 = memcmp(s1, s2, n);

	printf("# strncmp : my : [%d], lib : [%d]\n", r1, r2);
	printf("# memcmp : my : [%d], lib : [%d]\n", r3, r4);
}

int		main(int argc, char *argv[])
{
	char *call = argv[1];

	if (argc < 2)
		printf("plaese Func name call !!\n");
	else {

		if (strcmp(call, "memccpy") == 0)
		{
			if (argc < 6)
				printf("memccpy [dstsize src c n]\n");
			else
				memccpy_test(argv);
		}
		else if (strcmp(call, "strlcat") == 0)
		{
			if (argc < 5)
				printf("strlcat [dest src dstsize]\n");
			else
				strlcat_test(argv);
		}
		else if (strcmp(call, "strnstr") == 0)
		{
			if (argc < 5)
				printf("strnstr [haystack needle len]\n");
			else
				strnstr_test(argv);
		}
		else if (strcmp(call, "strncmp") == 0)
		{
			if (argc < 5)
				printf("strnstr [s1 s2 n]\n");
			else
				strncmp_test(argv);
		} else {
			printf("### func name not found....\n");
		}
	}
	return (0);
}
