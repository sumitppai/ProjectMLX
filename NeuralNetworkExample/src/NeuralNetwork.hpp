/*
 * NeuralNetwork.hpp
 *
 *  Created on: Sep 11, 2014
 *      Author: sumitppai
 */

#ifndef NEURALNETWORK_HPP_
#define NEURALNETWORK_HPP_
#include "OtherDefines.hpp"
#include "InputLayer.hpp"
#include "HiddenLayer.hpp"
#include "OutputLayer.hpp"

class NeuralNetwork {
private:
	InputLayer* ip;
	vector<HiddenLayer*> hd;
	OutputLayer* op;
public:
	NeuralNetwork(int inputDimensions,
					int numberOfHiddenLayers,
					vector<int>& numberOfNeuronsInHiddenLayers,
					double(*actvFn) (vector<double>) ,
					double(*actvFnDerv) (vector<double>));

	virtual ~NeuralNetwork();
	void train();
};

#endif /* NEURALNETWORK_HPP_ */
