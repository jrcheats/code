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

// 从十六进制字符串解析为结构体
CPUINFO deserializeCPUINFO(const std::string& str) {
	CPUINFO cpuinfo;
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 4; ++j) {
			std::string hexValue = str.substr((i * 4 + j) * 8, 8);
			cpuinfo.Register[i][j] = static_cast<int>(std::stoul(hexValue, nullptr, 16));
		}
	}
	return cpuinfo;
}

void print_cpu_info(const CPUINFO& cpuInfo) {
	for (int i = 0; i < 7; ++i) {
		std::cout << "CPUID(" << i << "):" << std::endl;
		std::cout << "  EAX: " << std::hex << cpuInfo.Register[i][0] << std::endl;
		std::cout << "  EBX: " << std::hex << cpuInfo.Register[i][1] << std::endl;
		std::cout << "  ECX: " << std::hex << cpuInfo.Register[i][2] << std::endl;
		std::cout << "  EDX: " << std::hex << cpuInfo.Register[i][3] << std::endl;
	}
}

int main() {
	CPUINFO cpuInfo;
	for (size_t i = 0; i < 7; i++) {
		__cpuid(cpuInfo.Register[i], static_cast<int>(i));
	}
	
	//print_cpu_info(cpuInfo);

	std::string serialized = serializeCPUINFO(cpuInfo);
	std::cout <<  serialized << std::endl;

	system("pause");
	return 0;
}
