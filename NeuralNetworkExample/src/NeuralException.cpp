/*
 * NeuralException.cpp
 *
 *  Created on: Sep 10, 2014
 *      Author: sumitppai
 */

#include "NeuralException.hpp"

NeuralException::NeuralException(string errorSrting) {
	this->message = errorSrting;

}

NeuralException::~NeuralException() throw () {

}

const char* NeuralException::what(){
	return this->message.c_str();
}
