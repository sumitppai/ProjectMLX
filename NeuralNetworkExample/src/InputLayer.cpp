/*
 * InputLayer.cpp
 *
 *  Created on: Sep 10, 2014
 *      Author: sumitppai
 */

#include "InputLayer.hpp"

InputLayer::InputLayer(int dims) {
	this->inputDimensions = dims;
	for(int i=0; i<dims; ++i){
		this->neurons.push_back(new Neuron());
	}

}

InputLayer::InputLayer(int numberOfNeurons,
				double(*actvFn) (double) ,
				double(*actvFnDerv) (double)){

	for(int i=0; i<numberOfNeurons; ++i){
			this->neurons.push_back(new Neuron(actvFn, actvFnDerv));
	}
}

InputLayer::~InputLayer() {
	// TODO Auto-generated destructor stub
}

void InputLayer::feedInput(vector<double> input){
	if(input.size()!=this->inputDimensions){
		throw NeuralException("Invalid input size");
	}

	for(int i=0; i<this->inputDimensions; ++i){
		this->neurons[i]->axonalOutput = input[i];
	}
}

void InputLayer::connect(Layer* nextLayer){
	this->nextLayer = nextLayer;
	nextLayer->previousLayer = this;

	for(int i=0; i<nextLayer->neurons.size(); ++i){
		for(int j=0; j<this->neurons.size(); ++j){
			nextLayer->neurons[i]->addSynapticInput(this->neurons[j], (rand() % 100 + 1)/100.0);

		}
	}
}


void InputLayer::setWeightsForNextLayerNeurons(Layer* nextLayer){

}
