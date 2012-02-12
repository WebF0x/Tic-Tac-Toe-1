/*
 * Best.cpp
 *
 *  Created on: May 22, 2011
 *      Author: Jurre
 */

#include "Best.h"


Best::Best(int value) {
	this->value = value;
}

Best::Best(int value, int row, int column) {
	this->value = value;
	this->row = row;
	this->column = column;
}
