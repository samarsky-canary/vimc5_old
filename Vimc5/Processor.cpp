#include "Processor.h"
#include <iostream> // удалить потом

template<typename  T>
void cicle_chow(const size_t &_end, T *ptr)
{
	for (auto i = 0; i < _end; i++)
		std::cout << *(ptr + i) << std::endl;
}

void Processor::debug()
{
	std::cout << "PSW\n"
		<< _psw.ip << " - IP" << std::endl
		<< _psw.nf << " - neg flag" << std::endl
		<< _psw.of << " - overflow flag" << std::endl
		<< _psw.zf << " - zero flag" << std::endl;

	std::cout << "REGS\n"
		<< "us\n";
	cicle_chow(8, &_poh.su[0]);
	std::cout << "ss\n";
	cicle_chow(8, &_poh.ss[0]);
	std::cout << "iu\n";
	cicle_chow(4, &_poh.iu[0]);
	std::cout << "is\n";
	cicle_chow(4, &_poh.is[0]);
	std::cout << "f\n";
	cicle_chow(4, &_poh.f[0]);
}


void Processor::push_data(uint16_t address, const datas argument, const size_t& lngth)
{
	_mem.push_data(address, argument, lngth);
}
