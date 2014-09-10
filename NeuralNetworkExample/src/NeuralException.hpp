/*
 * NeuralException.hpp
 *
 *  Created on: Sep 10, 2014
 *      Author: sumitppai
 */

#ifndef NEURALEXCEPTION_HPP_
#define NEURALEXCEPTION_HPP_

#include <exception>
#include <string>
using namespace std;


class NeuralException:public exception {
private:
	string message;
public:
	NeuralException(string errorString);

	virtual ~NeuralException() throw ();

	const char* what();

};

#endif /* NEURALEXCEPTION_HPP_ */
