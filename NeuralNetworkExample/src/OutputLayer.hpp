/*
 * OutputLayer.hpp
 *
 *  Created on: Sep 10, 2014
 *      Author: sumitppai
 */

#ifndef OUTPUTLAYER_HPP_
#define OUTPUTLAYER_HPP_
#include "OtherDefines.hpp"
#include "Layer.hpp"

class OutputLayer:public Layer {
public:
	OutputLayer(int numberOfNeurons,
				vector<double (*) (vector<double>)> actvFns,
				vector<double (*) (vector<double>)> actvFnDervs
				);

	OutputLayer(int numberOfNeurons,
					double(*actvFn) (vector<double>) ,
					double(*actvFnDerv) (vector<double>));

	void setWeightsForNextLayerNeurons(Layer* nextLayer);

	void connect(Layer* nextLayer);
	virtual ~OutputLayer();
};

#endif /* OUTPUTLAYER_HPP_ */
