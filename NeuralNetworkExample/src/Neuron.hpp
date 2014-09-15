/*
 * Neuron.hpp
 *
 *  Created on: Sep 10, 2014
 *      Author: sumitppai
 */

#ifndef NEURON_HPP_
#define NEURON_HPP_

#include "OtherDefines.hpp"

class Neuron {
private:
	double delta;	//Error
	vector<Neuron*> synapticInputs;
	vector<double> synapticWeights;
	double axonalOutput;
	double (*activationFunction) (double);
	double (*activationFunctionDerivative) (double);
	friend class InputLayer;
public:
	Neuron();

	Neuron(double (*actFn) (double),
			double (*actFnDerv) (double));

	Neuron(double (*actFn) (double),
			double (*actFnDerv) (double),
			vector<Neuron*> synapticInputs,
			vector<double> synapticWeights);

	void addSynapticInput(Neuron *inputNeuron, double weight);
	virtual ~Neuron();
};

#endif /* NEURON_HPP_ */
