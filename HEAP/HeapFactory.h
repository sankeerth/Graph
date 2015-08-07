#ifndef HEAPFACTORY_H
#define HEAPFACTORY_H

#include "heap.h"
#include "MinHeap.h"
#include "MaxHeap.h"

enum HeapType {
    Min,
    Max
};

class HeapFactory
{
public:
	HeapFactory() {}
	~HeapFactory() {}

    template <typename T>
	static Heap<T>* create(HeapType type);
};

template <typename T>
Heap<T>* HeapFactory::create(HeapType type)
{
	switch(type) {
		case Min:
			return new MinHeap<T>();
		case Max:
			return new MaxHeap<T>();
	}
	return 0;
}

#endif