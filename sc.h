#ifndef _SC_H
#define _SC_H

#include <cstring>
#include <cstdlib>

const int RANDOM = 0;
const int SYMMETRY = 1;
const int NONSIGULAR = 2;

templete<class T>
class Matrix{
	T **data;
	int size,num;
	Matrix(int n){
	    size = 2 * n;
	    num = n;
	    data = new int*[size];
	    for (int i = 0; i < size; i++)
	        data[i] = new int[size];
	    for (int i = 0; i < size; i++)
	        for (int j = 0; j < size; j++)
	            data[i][j] = 0;
	}
	
	void random(){
	    for (int i = 0; i < num; ++i)
	        for (int j = 0; j < num; ++j)
	            data[i][j] = rand();
	}
	
	void random(){
	    for (int i = 0; i < num; ++i)
	        for (int j = 0; j < num; ++j)
	            data[i][j] = rand();
	            
	   for (int i = 0; i < num; ++i)
	        for (int j = 0; j < num; ++j)
	            data[i][j] = data[j][i] = data[i][j] / 2 + data[j][i] / 2;
	}
	
	bool singular(){
	
	}
	
	void generate(int method){
	    do{
	        if (method & SYMMETRY) symmetry();
	        else random();
	    while ((method & NONSIGULAR) && sigular());
	}
	
	~Matrix(){
	    for (int i = 0; i < size; ++i)
	        delete [] data[i];
	    delete [] data;
	}

};

#endif
