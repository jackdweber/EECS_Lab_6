#ifndef TEST_H
#define TEST_H

#include "LinkedListOfInts.h"
#include <iostream>
#include <vector>

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

	bool searchTest(){
		bool r = true;
		list = new LinkedListOfInts();
		for(int i = 0; i < 10; i++){
			list->addBack(i);
		}
		if(!list->search(0)){
			r = false;
			std::cout << "ERROR: failed to find node at front. \n";
		}
		if(!list->search(9)){
			r = false;
			std::cout << "ERROR: failed to find node at back. \n";
		}
		if(!list->search(5)){
			r = false;
			std::cout << "ERROR: failed to find node in middle. \n";
		}
		delete list;
		return r;
	}

	bool addBackTest(){
		bool r = true;
		list = new LinkedListOfInts();
		for(int i = 0; i < 10; i++){
			list->addBack(i);
		}

		std::vector<int> vect = list->toVector();

		for(int i = 0; i < 10; i++){
			if(vect[i] != i){
				std::cout << "ERROR: Addback failed at index: ";
				std::cout << i;
				std::cout << "\n";
				r = false;
			}
		}

		delete list;
		return r;
	}

	bool addFrontTest(){
		bool r = true;
		list = new LinkedListOfInts();
		for(int i = 0; i < 10; i++){
			list->addFront(i);
		}

		std::vector<int> vect = list->toVector();

		for(int i = 0; i < 10; i++){
			if(vect[i] != 9 - i){
				std::cout << "ERROR: Addback failed at index: ";
				std::cout << i;
				std::cout << "\n";
				r = false;
			}
		}

		delete list;
		return r;
	}

	bool removeBackTest(){
		bool r = true;
		list = new LinkedListOfInts();
		for(int i = 0; i < 10; i++){
			list->addBack(i);
		}
		std::vector<int> vect1 = list->toVector();
		for(int i = 0; i < 3; i++){
			list->removeBack();
		}
		std::vector<int> vect2 = list->toVector();
		
		if(vect2.size() != 6){
			std::cout << "ERROR: Incorrect size after removing.\n";
			r = false;
		}

		for(int i = 0; i < (int) vect2.size(); i++){
			if(vect1[i] != vect2[i]){
				std::cout << "ERROR: items are not the same at at index: ";
				std::cout << i;
				std::cout << "\n";
				r = false;
			}
		}

		delete list;
		return r;
	}

	bool removeFrontTest(){
		bool r = true;
		list = new LinkedListOfInts();
		for(int i = 0; i < 10; i++){
			list->addFront(i);
		}
		std::vector<int> vect1 = list->toVector();
		for(int i = 0; i < 3; i++){
			list->removeFront();
		}
		std::vector<int> vect2 = list->toVector();
		
		if(vect2.size() != 6){
			std::cout << "ERROR: Incorrect size after removing.\n";
			r = false;
		}

		for(int i = 0; i < (int) vect2.size(); i++){
			if(vect1[i+3] != vect2[i]){
				std::cout << "ERROR: items are not the same at at index: ";
				std::cout << i;
				std::cout << "\n";
				r = false;
			}
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

		std::cout << "\n";
		if(searchTest()){
			std::cout << "Test Search: PASSED \n";
		}
		else{
			std::cout << "Test Search: FAILED \n";
		}

		std::cout << "\n";
		if(addBackTest()){
			std::cout << "Test addBack: PASSED \n";
		}
		else{
			std::cout << "Test addBack: FAILED \n";
		}

		std::cout << "\n";
		if(addFrontTest()){
			std::cout << "Test addFront: PASSED \n";
		}
		else{
			std::cout << "Test addFront: FAILED \n";
		}

		std::cout << "\n";
		if(removeBackTest()){
			std::cout << "Test removeBack: PASSED \n";
		}
		else{
			std::cout << "Test removeBack: FAILED \n";
		}

		std::cout << "\n";
		if(removeFrontTest()){
			std::cout << "Test removeFront: PASSED \n";
		}
		else{
			std::cout << "Test removeFront: FAILED \n";
		}

		std::cout << "\n";
	}
};

#endif
