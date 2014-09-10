/*
 * Neuron.cpp
 *
 *  Created on: Sep 10, 2014
 *      Author: sumitppai
 */

#include "Neuron.hpp"

Neuron::Neuron(double (*actFn) (vector<double>),
				double (*actFnDerv) (vector<double>)){
	//Initialize the neuron with the activation function and it's derivative
	this->activationFunction = actFn;
	this->activationFunctionDerivative = actFnDerv;

}

Neuron::Neuron(double (*actFn) (vector<double>),
				double (*actFnDerv) (vector<double>),
				vector<Neuron*> synInputs,
				vector<double> synWeights){

	this->activationFunction = actFn;
	this->activationFunctionDerivative = actFnDerv;

	if(synInputs.size() != synWeights.size()){
		throw NeuralException("Inputs and weights vector must have same size");
	}

	for(int i=0; i<synapticInputs.size(); ++i){
		this->synapticInputs.push_back(synInputs[i]);
		this->synapticWeights.push_back(synWeights[i]);
	}

}


Neuron::~Neuron() {
	// TODO Auto-generated destructor stub
}

Neuron::Neuron(){

}

void Neuron::addSynapticInput(Neuron *inputNeuron, double weight){
	this->synapticInputs.push_back(inputNeuron);
	this->synapticWeights.push_back(weight);
}
