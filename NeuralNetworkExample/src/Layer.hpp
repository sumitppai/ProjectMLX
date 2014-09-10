/*
 * Layer.hpp
 *
 *  Created on: Sep 10, 2014
 *      Author: sumitppai
 */

#ifndef LAYER_HPP_
#define LAYER_HPP_
#include "OtherDefines.hpp"
#include "Neuron.hpp"
class Layer {
private:

public:
	Layer();
	virtual void connect(Layer* nextLayer) = 0;
	virtual void setWeightsForNextLayerNeurons(Layer* nextLayer) = 0;
	virtual ~Layer();

	Layer *previousLayer;
	Layer *nextLayer;
	vector<Neuron*> neurons;
};

#endif /* LAYER_HPP_ */
