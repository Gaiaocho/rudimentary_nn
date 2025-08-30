#include <stdio.h>


struct neuron_input {
	int value; 
	int weight; 
};


int main() {
	int ret; 

	struct neuron_input input = {
		.value = 1, 
		.weight = 15, 
	};

	printf("This is our input value: %d, weight: %d\n",input.value, input.weight); 

	ret = 0;
	return  ret;
}
