#include "pch.h"
#include <iostream>
#include <thread>
#include <mutex>

//std::mutex m;//global mutex


void threadFunction(int id, std::mutex &m)
{
	std::lock_guard<std::mutex> loc(m); //pri svoem unichtozhenii razblokiruet m, a unichtozhenie garda budet tolko pri vihode iz funkcii
	//printf("Hello from thread %d \n", id); // works correct without using mutexes
	m.lock();
	/*
	try {
		g();
	}

	catch (std::exception &e) {
		m.unlock(); // 
		throw e; //probrosim isklyucheniye dalshe
	}

	*/
	std::cout << "Hello from thread " << id << "!" << std::endl; // if we write this we need to use mutexes
	m.unlock();
}

int main()
{
	constexpr size_t N = 50;
	std::thread T[N];
	std::mutex m;
	for (int i = 0; i < N; i++)
	{
		T[i] = std::thread(threadFunction, i, std::ref(m));//address of function and args for it, without std::ref() it won't compile!!!!!! WHY????
	}
	
	for (int i = 0; i < N; i++)
	{
		T[i].join();
	}

	return EXIT_SUCCESS;
}
