#include "understand.h"

int		main(int argc, char *argv[]) {

	printf("./understand \"{usleep, pthread}\" \"[n]\" \n");
	int idx = 1;

	if (argc < 2) {
		printf("Error: param error\n");
		return (0);
	}

	char *inst = argv[idx++];

	if (strcmp(inst, "usleep") == 0)
		understand_usleep();
	else if (strcmp(inst, "pthread") == 0) {
		if (argc != 3) {
			printf("Error: pthread please call ./understand pthread n\n");
			return (0);
		}
		int n = atoi(argv[idx++]);
		understand_thread(n);
	}
	else {
		printf("Error: [%s] is not valid\n", inst);
		return (0);
	}
	return (1);
}