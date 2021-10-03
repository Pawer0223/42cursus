#include <stdio.h>

int	main(void) {

    char name[10];
    int age;
    int name_len = 0;

    printf("name:");
    scanf("%s", name);
    
    for (int i = 0; i < 4; i++) {
	if (!name[i]) {
	    break;
	}
	name_len++;
    }
    if (name_len < 2 || name_len > 4 || name[name_len]) {
	printf("이름은 2~4글자만 가능합니다.\n");
	return main();
    }

    printf("age:");
    scanf("%d", &age);

    if (age < 0) {
	printf("나이는 음수가 될 수 없습니다.\n");
	return main();
    }

    printf("name : %s, age : %d\n", name, age);
    return (1);
}
