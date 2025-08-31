#include <math.h>
#include <stdio.h>
#include <stdbool.h>



struct perceptron_input {
	int value; 
	int weight; 
};

struct sigmoid_input {
	float value; 
	float weight; 
};

bool fire_percpetron(struct perceptron_input *inputs, int threshold, int input_length);
int sum_of_perceptron_weights(struct perceptron_input *inputs, int input_length);

bool fire_sigmoid(struct sigmoid_input *inputs, float threshold, int input_length);
float sum_of_sigmoid_weights(struct sigmoid_input *inputs, int input_length);

int main() {
	int ret; 

	struct perceptron_input cheese_input = {
		.value = 1, 
		.weight = 3, 
	};

	struct perceptron_input gluten_input = {
		.value = 0, 
		.weight = 5,
	};

	struct perceptron_input inputs[] = {cheese_input, gluten_input};

	bool fire  = fire_percpetron(inputs, 4, 2);

	if(fire) {
		printf("There is no gluten we can go \n \n");
	} else  {
		printf("There is gluten we can't go \n \n");
	}

	struct sigmoid_input sigmoid_cheese = {
		.value = 3.98, 
		.weight = 4.0, 
	};

	struct sigmoid_input sigmoid_gluten = {
		.value = 0.02, 
		.weight = 4.5,
	};

	struct sigmoid_input sinputs[] = {sigmoid_cheese, sigmoid_gluten}; 

	fire = fire_sigmoid(sinputs, 4.5, 2);

	if(fire) {
		printf("There is no gluten we can go \n");
	} else  {
		printf("There is gluten we can't go \n");
	}


	ret = 0;
	return  ret;
}

bool fire_sigmoid(struct sigmoid_input *inputs, float threshold, int input_length) {
	for(int i = 0; i < input_length; i++) {
		printf("input value: %.2f, weight: %.2f \n", inputs[i].value, inputs[i].weight);
	}

	float ret; 
	ret = sum_of_sigmoid_weights(inputs, input_length); 

	printf("sum of weights is: %.2f \n", ret);
	printf("Threshhold is: %.2f \n \n" , threshold);

	ret = 1 / (1 + exp(-(ret - threshold)));

	return ret <= 0.5;
}

float sum_of_sigmoid_weights(struct sigmoid_input *inputs, int input_length) {
	float sum = 0.0f; 

	for(int i = 0; i < input_length; i++) {
		sum = sum + (inputs[i].value * inputs[i].weight);
	}
	return sum;
}


bool fire_percpetron(struct perceptron_input *inputs, int threshold, int input_length){ 
	for(int i = 0; i < input_length; i++) {
		printf("input value: %d, weight: %d \n", inputs[i].value, inputs[i].weight);
	}

	int weight_sum = sum_of_perceptron_weights(inputs, input_length); 

	printf("sum of weights is: %d \n", weight_sum);
	printf("Threshhold is: %d \n \n" , threshold);


	return weight_sum - threshold <= 0;
}

int sum_of_perceptron_weights(struct perceptron_input *inputs, int input_length) {
	int sum = 0; 

	for(int i = 0; i < input_length; i++) {
		sum = sum + (inputs[i].value * inputs[i].weight);
	}
	return sum;
}


