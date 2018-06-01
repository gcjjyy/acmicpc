#include <stdio.h>

int unload[4];
int load[4];

int main() {
	int current = 0;
	int max = 0;
	for(int i = 0; i < 4; ++i) {
		scanf("%d%d", &unload[i], &load[i]);
		current += load[i] - unload[i];
		if(current > max) max = current;
	}

	printf("%d\n", max);
	return 0;
}