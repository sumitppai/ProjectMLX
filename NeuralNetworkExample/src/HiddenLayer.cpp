/*
 * HiddenLayer.cpp
 *
 *  Created on: Sep 10, 2014
 *      Author: sumitppai
 */

#include "HiddenLayer.hpp"

HiddenLayer::HiddenLayer(int numberOfNeurons,
							vector<double (*) (double)> actvFns,
							vector<double (*) (double)> actvFnDervs
							){

	if(actvFns.size()!=numberOfNeurons || actvFnDervs.size()!=numberOfNeurons){
		throw NeuralException("provide equal number of activation functions and their derivatives");
	}

	for(int i=0; i<numberOfNeurons; ++i){
		this->neurons.push_back(new Neuron(actvFns[i], actvFnDervs[i]));
	}

}


HiddenLayer::HiddenLayer(int numberOfNeurons,
				double(*actvFn) (double) ,
				double(*actvFnDerv) (double)){

	for(int i=0; i<numberOfNeurons; ++i){
			this->neurons.push_back(new Neuron(actvFn, actvFnDerv));
	}
}

HiddenLayer::~HiddenLayer() {
	// TODO Auto-generated destructor stub
}

void HiddenLayer::connect(Layer* nextLayer){
	this->nextLayer = nextLayer;
	nextLayer->previousLayer = this;

	for(int i=0; i<nextLayer->neurons.size(); ++i){
		for(int j=0; j<this->neurons.size(); ++j){
			nextLayer->neurons[i]->addSynapticInput(this->neurons[j], (rand() % 100 + 1)/100.0);

		}
	}
}

void HiddenLayer::setWeightsForNextLayerNeurons(Layer* nextLayer){

}
