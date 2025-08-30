#include <stdio.h>


struct neuron_input {
	int value; 
	int weight; 
};

int fire_percpetron(struct neuron_input *inputs, int threshold, int input_length);
int sum_of_weights(struct neuron_input *inputs, int input_length); 

int main() {
	int ret; 

	struct neuron_input cheese_input = {
		.value = 1, 
		.weight = 3, 
	};

	struct neuron_input gluten_input = {
		.value = 0, 
		.weight = 5,
	};

	struct neuron_input inputs[] = {cheese_input, gluten_input};

	int fire  = fire_percpetron(inputs, 4, 2);

	if(fire < 1) {
		printf("There is no gluten we can go \n");
	} else  {
		printf("There is gluten we can't go \n");
	}

	ret = 0;
	return  ret;
}

int fire_percpetron(struct neuron_input *inputs, int threshold, int input_length){ 
	for(int i = 0; i < input_length; i++) {
		printf("input value: %d, weight: %d \n", inputs[i].value, inputs[i].weight);
	}

	int weight_sum = sum_of_weights(inputs, input_length); 

	printf("sum of weights is: %d \n", weight_sum);
	printf("Threshhold is: %d \n \n" , threshold);

	int ret; 

	if(weight_sum > threshold) {
		ret = 1; 
	} else {
		ret = 0; 
	}

	return ret;
}

int sum_of_weights(struct neuron_input *inputs, int input_length) {
	int sum = 0; 

	for(int i = 0; i < input_length; i++) {
		sum = sum + (inputs[i].value * inputs[i].weight);
	}
	return sum;
}


