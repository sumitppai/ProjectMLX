/*
 * NeuralNetwork.cpp
 *
 *  Created on: Sep 11, 2014
 *      Author: sumitppai
 */

#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(int inputDimensions,
		int numberOfHiddenLayers,
		vector<int>& numberOfNeuronsInHiddenLayers,
		double(*actvFn) (double) ,
		double(*actvFnDerv) (double)) {

	ip = new InputLayer(inputDimensions);

	if(numberOfHiddenLayers<1){
		throw new NeuralException("must have atleast 1 hidden layer");
	}

	if(numberOfHiddenLayers != numberOfNeuronsInHiddenLayers.size()){
		throw new NeuralException("please correct the vector indicating the count of neurons in each hidden layer");
	}

	hd.push_back(new HiddenLayer(numberOfNeuronsInHiddenLayers[0], actvFn, actvFnDerv));
	ip->connect(hd[0]);

	for(int i=1; i<numberOfHiddenLayers; ++i){
		hd.push_back(new HiddenLayer(numberOfNeuronsInHiddenLayers[i], actvFn, actvFnDerv));
		hd[i-1]->connect(hd[i]);
	}

	op = new OutputLayer(1, actvFn, actvFnDerv);

	hd[numberOfHiddenLayers-1]->connect(op);

}

NeuralNetwork::~NeuralNetwork() {
	// TODO Auto-generated destructor stub
}

void NeuralNetwork::train(string directoryPath){

	ifstream inFile;
	size_t size = 0;

	inFile.open(directoryPath.c_str(), ios::in);
	unsigned char ch;
	int i=0;
	if(inFile.is_open()) {
		while(!inFile.eof()){
			inFile>>ch;
			cout<<ch<<" ";
			if(i%28==0) cout<<endl;
			if(i==28*28*50) break;
			i++;
		}
	}

	inFile.close();

}

