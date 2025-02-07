#include<iostream>
#include<Windows.h>
#include<vector>
#include<chrono>
#include<random>
#include<thread>



void sum_vec(std::vector<int>::iterator begin_1, std::vector<int>::iterator end_1, std::vector<int>::iterator begin_2, std::vector<int>::iterator end_2, int* sum)
{
	for (auto i = begin_1; i < end_1; ++i)
	{
		*sum += *i;
	}
	for (auto i = begin_2; i < end_2; ++i)
	{
		*sum += *i;
	}
}

void fill_vec(std::vector<int>& V)
{
	std::mt19937 gen;
	std::uniform_int_distribution<int> dis(0, 100000);
	auto rand_num([=]() mutable {return dis(gen); });
	std::generate(V.begin(), V.end(), rand_num);
}

double get_time_1(std::vector<int>& v1, std::vector<int>& v2)
{
	int sum = 0;

	std::thread t1(sum_vec, v1.begin(), v1.end(), v2.begin(), v2.end(), &sum);

	auto start = std::chrono::steady_clock::now();

	t1.join();

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	return elapsed_seconds.count();
}

double get_time_2(std::vector<int>& v1, std::vector<int>& v2)
{
	int sum = 0;

	std::thread t1(sum_vec, v1.begin(), v1.begin()+v1.size()/2, v1.begin() + v1.size() / 2 , v1.end(), &sum);
	std::thread t2(sum_vec, v2.begin(), v2.begin() + v2.size() / 2, v2.begin() + v2.size() / 2, v2.end(), &sum);

	auto start = std::chrono::steady_clock::now();
	t1.join();
	t2.join();
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	return elapsed_seconds.count();
}

double get_time_4(std::vector<int>& v1, std::vector<int>& v2)
{
	int sum = 0;

	auto v1_it1 = v1.begin();
	auto v1_it2 = v1.begin() + v1.size() / 4;
	auto v1_it3 = v1.begin() + v1.size() / 2;
	auto v1_it4 = v1.begin() + v1.size() * 3 / 4;
	auto v1_it5 = v1.end();

	auto v2_it1 = v2.begin();
	auto v2_it2 = v2.begin() + v2.size() / 4;
	auto v2_it3 = v2.begin() + v2.size() / 2;
	auto v2_it4 = v2.begin() + v2.size() * 3 / 4;
	auto v2_it5 = v2.end();


	std::thread t1(sum_vec, v1_it1, v1_it2, v1_it2, v1_it3, &sum);
	std::thread t2(sum_vec, v1_it3, v1_it4, v1_it4, v1_it5, &sum);
	std::thread t3(sum_vec, v2_it1, v2_it2, v2_it2, v2_it3, &sum);
	std::thread t4(sum_vec, v2_it3, v2_it4, v2_it4, v2_it5, &sum);
	auto start = std::chrono::steady_clock::now();
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	return elapsed_seconds.count();
}

double get_time_8(std::vector<int>& v1, std::vector<int>& v2)
{
	int sum = 0;

	auto v1_it1 = v1.begin();
	auto v1_it2 = v1.begin() + v1.size() / 8;
	auto v1_it3 = v1.begin() + v1.size() / 4;
	auto v1_it4 = v1.begin() + v1.size() * 3 / 8;
	auto v1_it5 = v1.begin() + v1.size() / 2;
	auto v1_it6 = v1.begin() + v1.size() * 5 / 8;
	auto v1_it7 = v1.begin() + v1.size() * 3 / 4;
	auto v1_it8 = v1.begin() + v1.size() * 7 / 8;
	auto v1_it9 = v1.end();

	auto v2_it1 = v2.begin();
	auto v2_it2 = v2.begin() + v2.size() / 8;
	auto v2_it3 = v2.begin() + v2.size() / 4;
	auto v2_it4 = v2.begin() + v2.size() * 3 / 8;
	auto v2_it5 = v2.begin() + v2.size() / 2;
	auto v2_it6 = v2.begin() + v2.size() * 5 / 8;
	auto v2_it7 = v2.begin() + v2.size() * 3 / 4;
	auto v2_it8 = v2.begin() + v2.size() * 7 / 8;
	auto v2_it9 = v2.end();

	std::thread t1(sum_vec, v1_it1, v1_it2, v1_it2, v1_it3, &sum);
	std::thread t2(sum_vec, v1_it3, v1_it4, v1_it4, v1_it5, &sum);
	std::thread t3(sum_vec, v1_it5, v1_it6, v1_it6, v1_it7, &sum);
	std::thread t4(sum_vec, v1_it7, v1_it8, v1_it8, v1_it9, &sum);


	std::thread t5(sum_vec, v2_it1, v2_it2, v2_it2, v2_it3, &sum);
	std::thread t6(sum_vec, v2_it3, v2_it4, v2_it4, v2_it5, &sum);
	std::thread t7(sum_vec, v2_it5, v2_it6, v2_it6, v2_it7, &sum);
	std::thread t8(sum_vec, v2_it7, v2_it8, v2_it8, v2_it9, &sum);


	auto start = std::chrono::steady_clock::now();
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	return elapsed_seconds.count();
}

double get_time_16(std::vector<int>& v1, std::vector<int>& v2)
{
	int sum = 0;

	auto v1_it1 = v1.begin();
	auto v1_it2 = v1.begin() + v1.size() / 16;
	auto v1_it3 = v1.begin() + v1.size() * 2 / 16;
	auto v1_it4 = v1.begin() + v1.size() * 3 / 16;
	auto v1_it5 = v1.begin() + v1.size() * 4 / 16;
	auto v1_it6 = v1.begin() + v1.size() * 5 / 16;
	auto v1_it7 = v1.begin() + v1.size() * 6 / 16;
	auto v1_it8 = v1.begin() + v1.size() * 7 / 16;
	auto v1_it9 = v1.begin() + v1.size() * 8 / 16;
	auto v1_it10 = v1.begin() + v1.size() * 9 / 16;
	auto v1_it11 = v1.begin() + v1.size() * 10 / 16;
	auto v1_it12 = v1.begin() + v1.size() * 11 / 16;
	auto v1_it13 = v1.begin() + v1.size() * 12 / 16;
	auto v1_it14 = v1.begin() + v1.size() * 13 / 16;
	auto v1_it15 = v1.begin() + v1.size() * 14 / 16;
	auto v1_it16 = v1.begin() + v1.size() * 15 / 16;
	auto v1_it17 = v1.end();

	auto v2_it1 = v2.begin();
	auto v2_it2 = v2.begin() + v2.size() / 16;
	auto v2_it3 = v2.begin() + v2.size() * 2 / 16;
	auto v2_it4 = v2.begin() + v2.size() * 3 / 16;
	auto v2_it5 = v2.begin() + v2.size() * 4 / 16;
	auto v2_it6 = v2.begin() + v2.size() * 5 / 16;
	auto v2_it7 = v2.begin() + v2.size() * 6 / 16;
	auto v2_it8 = v2.begin() + v2.size() * 7 / 16;
	auto v2_it9 = v2.begin() + v2.size() * 8 / 16;
	auto v2_it10 = v2.begin() + v2.size() * 9 / 16;
	auto v2_it11 = v2.begin() + v2.size() * 10 / 16;
	auto v2_it12 = v2.begin() + v2.size() * 11 / 16;
	auto v2_it13 = v2.begin() + v2.size() * 12 / 16;
	auto v2_it14 = v2.begin() + v2.size() * 13 / 16;
	auto v2_it15 = v2.begin() + v2.size() * 14 / 16;
	auto v2_it16 = v2.begin() + v2.size() * 15 / 16;
	auto v2_it17 = v2.end();

	std::thread t1(sum_vec, v1_it1, v1_it2, v1_it2, v1_it3, &sum);
	std::thread t2(sum_vec, v1_it3, v1_it4, v1_it4, v1_it5, &sum);
	std::thread t3(sum_vec, v1_it5, v1_it6, v1_it6, v1_it7, &sum);
	std::thread t4(sum_vec, v1_it7, v1_it8, v1_it8, v1_it9, &sum);
	std::thread t5(sum_vec, v1_it9, v1_it10, v1_it10, v1_it11, &sum);
	std::thread t6(sum_vec, v1_it11, v1_it12, v1_it12, v1_it13, &sum);
	std::thread t7(sum_vec, v1_it13, v1_it14, v1_it14, v1_it15, &sum);
	std::thread t8(sum_vec, v1_it15, v1_it16, v1_it16, v1_it17, &sum);

	std::thread t9(sum_vec, v2_it1, v2_it2, v2_it2, v2_it3, &sum);
	std::thread t10(sum_vec, v2_it3, v2_it4, v2_it4, v2_it5, &sum);
	std::thread t11(sum_vec, v2_it5, v2_it6, v2_it6, v2_it7, &sum);
	std::thread t12(sum_vec, v2_it7, v2_it8, v2_it8, v2_it9, &sum);
	std::thread t13(sum_vec, v2_it9, v2_it10, v2_it10, v2_it11, &sum);
	std::thread t14(sum_vec, v2_it11, v2_it12, v2_it12, v2_it13, &sum);
	std::thread t15(sum_vec, v2_it13, v2_it14, v2_it14, v2_it15, &sum);
	std::thread t16(sum_vec, v2_it15, v2_it16, v2_it16, v2_it17, &sum);


	auto start = std::chrono::steady_clock::now();
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
	t11.join();
	t12.join();
	t13.join();
	t14.join();
	t15.join();
	t16.join();
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	return elapsed_seconds.count();
}



int main()
{	

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double time1[4];
	double time2[4];
	double time4[4];
	double time8[4];
	double time16[4];

	std::vector<int> v1 (1000);
	std::vector<int> v2 (1000);
	fill_vec(v1);
	fill_vec(v2);

	time1[0] = get_time_1(v1, v2);
	time2[0] = get_time_2(v1, v2);
	time4[0] = get_time_4(v1, v2);
	time8[0] = get_time_8(v1, v2);
	time16[0] = get_time_16(v1, v2);

	std::vector<int> v3(10000);
	std::vector<int> v4(10000);
	fill_vec(v3);
	fill_vec(v4);

	time1[1] = get_time_1(v3, v4);
	time2[1] = get_time_2(v3, v4);
	time4[1] = get_time_4(v3, v4);
	time8[1] = get_time_8(v3, v4);
	time16[1] = get_time_16(v3, v4);

	std::vector<int> v5(100000);
	std::vector<int> v6(100000);
	fill_vec(v5);
	fill_vec(v6);

	time1[2] = get_time_1(v5, v6);
	time2[2] = get_time_2(v5, v6);
	time4[2] = get_time_4(v5, v6);
	time8[2] = get_time_8(v5, v6);
	time16[2] = get_time_16(v5, v6);

	std::vector<int> v7(1000000);
	std::vector<int> v8(1000000);
	fill_vec(v7);
	fill_vec(v8);

	time1[3] = get_time_1(v7, v8);
	time2[3] = get_time_2(v7, v8);
	time4[3] = get_time_4(v7, v8);
	time8[3] = get_time_8(v7, v8);
	time16[3] = get_time_16(v7, v8);




	std::cout << "Количество аппаратных ядер: " << std::thread::hardware_concurrency()<<std::endl;
	std::cout << "\t\t1000\t  10000 \t 100000 \t 1000000\n";
	std::cout << " 1   поток: " << time1[0]<<'\t'<<time1[1]<<'\t'<<time1[2]<<'\t'<<time1[3] << std::endl;
	std::cout << " 2  потока: " << time2[0] << '\t' << time2[1] << '\t' << time2[2] << '\t' << time2[3] << std::endl;
	std::cout << " 4  потока: " << time4[0] << '\t' << time4[1] << '\t' << time4[2] << '\t' << time4[3] << std::endl;
	std::cout << " 8 потоков: " << time8[0] << '\t' << time8[1] << '\t' << time8[2] << '\t' << time8[3] << std::endl;
	std::cout << "16 потоков: " << time16[0] << '\t' << time16[1] << '\t' << time16[2] << '\t' << time16[3] << std::endl;

	return 0;
}