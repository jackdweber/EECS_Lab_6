#ifndef TEST_H
#define TEST_H

#include "LinkedListOfInts.h"

class Tester {

private:
	LinkedListOfInts* list;
	

	bool createList(){
		list = new LinkedListOfInts();
		if(list != nullptr){
			return true;
		}
		delete list;
		return false;
	}

	bool isEmptyTest(){
		bool r = true;
		list = new LinkedListOfInts();
		if(!list->isEmpty()){
			r = false;
			std::cout << "ERROR: list not empty after creation.";
		}
		list->addBack(1);
		if(list->isEmpty()){
			r = false;
			std::cout << "ERROR: list empty after addBack.";
		}
		delete list;
		list = new LinkedListOfInts();
		list->addFront(1);
		if(list->isEmpty()){
			r = false;
			std::cout << "ERROR: list empty after addFront.";
		}
		return r;
	}

public:

	void runTest(){
		std::cout << "\n";
		if(createList()){
			std::cout << "Test Create List: PASSED \n";
		}
		else{
			std::cout << "Test Create List: FAILED \n";s
		}

		if(isEmptyTest()){
			std::cout << "Test Create List: PASSED \n";
		}
		else{
			std::cout << "Test Create List: FAILED \n";s
		}

	}
};

#endif
