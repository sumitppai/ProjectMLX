/*
 * InputLayer.hpp
 *
 *  Created on: Sep 10, 2014
 *      Author: sumitppai
 */

#ifndef INPUTLAYER_HPP_
#define INPUTLAYER_HPP_
#include "OtherDefines.hpp"
#include "Neuron.hpp"
#include "Layer.hpp"

class InputLayer:public Layer {
private:
	int inputDimensions;


public:
	InputLayer(int dim);

	InputLayer(int numberOfNeurons,
					double(*actvFn) (vector<double>) ,
					double(*actvFnDerv) (vector<double>));

	void feedInput(vector<double> input);

	void setWeightsForNextLayerNeurons(Layer* nextLayer);

	void connect(Layer* nextLayer);

	virtual ~InputLayer();


};

#endif /* INPUTLAYER_HPP_ */
