#include<iostream>
#include<Windows.h>
#include<vector>
#include<chrono>
#include<random>
#include<thread>


void sum_vec(std::vector<int> v1, std::vector<int> v2, std::vector<int> v3, int firstNum, int lastNum)
{
	for (int i = firstNum; i < lastNum; ++i)
	{
		v3[i] = v1[i] + v2[i];
	}
}

void fill_vec(std::vector<int>& V)
{
	std::mt19937 gen;
	std::uniform_int_distribution<int> dis(0, 100000);
	auto rand_num([=]() mutable {return dis(gen); });
	std::generate(V.begin(), V.end(), rand_num);
}

int main()
{	

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "Количество аппаратных ядер: " << std::thread::hardware_concurrency() << std::endl;
	std::cout << "\t\t1000\t  10000 \t 100000 \t 1000000\n";

	for (int ThreadsNum = 1; ThreadsNum <= 16; ++ThreadsNum)
	{
		if (ThreadsNum == 1 || ThreadsNum == 2 || ThreadsNum == 4 || ThreadsNum == 8 || ThreadsNum == 16)
		{

			switch (ThreadsNum)
			{
			case 1:
				std::cout << ThreadsNum << "    поток: ";
				break;
			case 2:
				std::cout << ThreadsNum << "   потока: ";
				break;
			case 4:
				std::cout << ThreadsNum << "   потока: ";
				break;
			case 8:
				std::cout << ThreadsNum << "  потоков: ";
				break;
			default:
				std::cout << ThreadsNum << " потоков: ";
			}


			for (int elemNum = 1000; elemNum <= 1000000; elemNum *= 10)
			{
				std::vector<int> v1(elemNum);
				std::vector<int> v2(elemNum);
				std::vector<int> v3(elemNum);
				fill_vec(v1);
				fill_vec(v2);

				auto start = std::chrono::steady_clock::now();
				std::vector<std::thread> threads(ThreadsNum);
				for (int k = 0; k < ThreadsNum; ++k)
				{
					threads[k] = std::thread(sum_vec, v1, v2, v3, elemNum * k / ThreadsNum, elemNum * (k + 1) / ThreadsNum);
				}

				for (int k = 0; k < ThreadsNum; ++k)
				{
					threads[k].join();
				}
				auto end = std::chrono::steady_clock::now();
				std::chrono::duration<double> elapsed_seconds = end - start;

				std::cout << elapsed_seconds.count() << '\t';

			}
			std::cout << std::endl;

		}
		else { continue; }
	}


	return 0;
}