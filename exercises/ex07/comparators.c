#include <stdio.h>
#include <strings.h>

int compare_scores_desc(const void* score_a, const void* score_b) {
	int *a_pointer = (int*) score_a;
	int *b_pointer = (int*) score_b;
	return *a_pointer - *b_pointer;
}

int compare_names(const void* a, const void* b) {
	char **a_pointer = (char**) a;
	char **b_pointer = (char**) b;
	int len_a = strlen(*a_pointer);
	int len_b = strlen(*b_pointer);
	int comp = len_a - len_b;
	if(comp == 0) {
		for(int i = 0; i < len_a; i++) {
			comp = *a_pointer[i] - *b_pointer[i];
			if(comp != 0) {
				break;
			}
		}
	}
	return comp;
}

void print_int_list(int *arr) {
	printf("[ ");
	for(int i = 0; i < 7; i++) {
		printf("%d ", arr[i]);
	}
	printf("]\n");
}

void print_str_list(char **arr) {
	printf("[ ");
	for(int i = 0; i < 3; i++) {
		printf("%s ", arr[i]);
	}
	printf("]\n");
}
int main() {
	int scores[] = {543,323,32,554,11,3,112};
	char* names[] = {"kai", "andrew", "patrick"};
	qsort(scores, 7, sizeof(int), compare_scores_desc);
	print_int_list(scores);
	print_str_list(names);
	qsort(scores, 3, sizeof(char), compare_names);
	return 0;
}
