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
	double (*activationFunction) (vector<double>);
	double (*activationFunctionDerivative) (vector<double>);
	friend class InputLayer;
public:
	Neuron();

	Neuron(double (*actFn) (vector<double>),
			double (*actFnDerv) (vector<double>));

	Neuron(double (*actFn) (vector<double>),
			double (*actFnDerv) (vector<double>),
			vector<Neuron*> synapticInputs,
			vector<double> synapticWeights);

	void addSynapticInput(Neuron *inputNeuron, double weight);
	virtual ~Neuron();
};

#endif /* NEURON_HPP_ */
