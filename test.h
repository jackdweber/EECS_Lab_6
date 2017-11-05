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
			std::cout << "ERROR: list not empty after creation. \n";
		}
		list->addBack(1);
		if(list->isEmpty()){
			r = false;
			std::cout << "ERROR: list empty after addBack. \n";
		}
		delete list;
		list = new LinkedListOfInts();
		list->addFront(1);
		if(list->isEmpty()){
			r = false;
			std::cout << "ERROR: list empty after addFront. \n";
		}
		delete list;
		return r;
	}

	bool sizeTest(){
		bool r  = true;
		list = new LinkedListOfInts();
		//Add ten with add back
		for(int i = 0; i < 10; i++){
			list->addBack(i);
		}
		if(list->size() != 10){
			r = false;
			std::cout << "ERROR: list not ten after adding ten to back. \n";
		}
		delete list;
		list = new LinkedListOfInts();
		//Now for add front, more of a test for add front.
		for(int i = 0; i < 10; i++){
			list->addFront(i);
		}
		if(list->size() != 10){
			r = false;
			std::cout << "ERROR: list not ten after adding ten to back. \n";
		}
		delete list;
		return r;

	}

public:

	void runTest(){
		std::cout << "\n";
		if(createList()){
			std::cout << "Test Create List: PASSED \n";
		}
		else{
			std::cout << "Test Create List: FAILED \n";
		}

		std::cout << "\n";
		if(isEmptyTest()){
			std::cout << "Test Empty: PASSED \n";
		}
		else{
			std::cout << "Test Empty: FAILED \n";
		}

		std::cout << "\n";
		if(sizeTest()){
			std::cout << "Test Size: PASSED \n";
		}
		else{
			std::cout << "Test Size: FAILED \n";
		}
	}
};

#endif
