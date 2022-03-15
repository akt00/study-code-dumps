#ifndef TEST_LOCALTIME
#define TEST_LOCALTIME
#include<ctime>
#include<iostream>

void test_localtime() {
  
	auto epoch_t = std::time(nullptr);
	tm timeinfo;
	auto ret = localtime_s(&timeinfo, &epoch_t);
	if(ret == 0) std::cout << timeinfo.tm_year + 1900 << " " << timeinfo.tm_mon + 1 << " " << timeinfo.tm_mday;
}

#endif
