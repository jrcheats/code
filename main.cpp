#include <iostream>
#include <intrin.h>
#include <iomanip>
#include <sstream>
#include <string>

struct CPUINFO {
	int Register[7][4];
};

// 将结构体转换为十六进制字符串
std::string serializeCPUINFO(const CPUINFO& cpuinfo) {
	std::ostringstream oss;
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 4; ++j) {
			oss << std::setw(8) << std::setfill('0') << std::hex << cpuinfo.Register[i][j];
		}
	}
	return oss.str();
}

int main() {
	CPUINFO cpuInfo;
	for (size_t i = 0; i < 7; i++) {
		__cpuid(cpuInfo.Register[i], static_cast<int>(i));
	}

	std::string serialized = serializeCPUINFO(cpuInfo);
	std::cout <<  serialized << std::endl;

	system("pause");
	return 0;
}
