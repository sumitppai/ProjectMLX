/*
 * HiddenLayer.hpp
 *
 *  Created on: Sep 10, 2014
 *      Author: sumitppai
 */

#ifndef HIDDENLAYER_HPP_
#define HIDDENLAYER_HPP_
#include "OtherDefines.hpp"
#include "Neuron.hpp"
#include "Layer.hpp"

class HiddenLayer:public Layer {
private:


public:

	HiddenLayer(int numberOfNeurons,
				vector<double (*) (vector<double>)> actvFns,
				vector<double (*) (vector<double>)> actvFnDervs
				);

	HiddenLayer(int numberOfNeurons,
				double(*actvFn) (vector<double>) ,
				double(*actvFnDerv) (vector<double>));

	void connect(Layer* nextLayer);

	void setWeightsForNextLayerNeurons(Layer* nextLayer);

	virtual ~HiddenLayer();
};

#endif /* HIDDENLAYER_HPP_ */
