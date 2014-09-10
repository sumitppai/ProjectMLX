/*
 * OutputLayer.cpp
 *
 *  Created on: Sep 10, 2014
 *      Author: sumitppai
 */

#include "OutputLayer.hpp"

OutputLayer::OutputLayer(int numberOfNeurons,
							vector<double (*) (vector<double>)> actvFns,
							vector<double (*) (vector<double>)> actvFnDervs
							){

	if(actvFns.size()!=numberOfNeurons || actvFnDervs.size()!=numberOfNeurons){
		throw NeuralException("provide equal number of activation functions and their derivatives");
	}

	for(int i=0; i<numberOfNeurons; ++i){
		this->neurons.push_back(new Neuron(actvFns[i], actvFnDervs[i]));
	}

}

OutputLayer::OutputLayer(int numberOfNeurons,
				double(*actvFn) (vector<double>) ,
				double(*actvFnDerv) (vector<double>)){

	for(int i=0; i<numberOfNeurons; ++i){
			this->neurons.push_back(new Neuron(actvFn, actvFnDerv));
	}
}

OutputLayer::~OutputLayer() {
	// TODO Auto-generated destructor stub
}

void OutputLayer::connect(Layer* nextLayer){
	this->nextLayer = nextLayer;
	nextLayer->previousLayer = this;
	for(int i=0; i<nextLayer->neurons.size(); ++i){
		for(int j=0; j<this->neurons.size(); ++j){
			nextLayer->neurons[i]->addSynapticInput(this->neurons[j], (rand() % 100 + 1)/100.0);

		}
	}
}

void OutputLayer::setWeightsForNextLayerNeurons(Layer* nextLayer){

}
