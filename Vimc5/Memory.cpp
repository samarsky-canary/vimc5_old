#include <iostream>
#include <exception>
#include "Memory.h"


void Memory::put_byte(const uint8_t &byte, uint16_t& pos)
{
	*(m_memory + pos) = byte;
	pos++;
}

void Memory::put_2bytes(const uint16_t &t_short, uint16_t& pos)
{
	*((uint16_t*)(m_memory + pos)) = t_short;
	pos += 2;
}

void Memory::put_4bytes(const uint32_t &t_long, uint16_t& pos)
{
	*((uint32_t*)(m_memory + pos)) = t_long;
	pos += 4;
}

void Memory::put_short(const std::string & t_short, uint16_t& pos)
{
	const short number = stoi(t_short);
	*((short*)(m_memory + pos)) = number;
	pos += 2;
}


void Memory::put_int(const std::string & t_int, uint16_t& pos)
{
	const int number = stoi(t_int);
	*((short*)(m_memory + pos)) = number;
	pos += 2;
}

void Memory::put_float(const std::string & t_float, uint16_t& pos)
{
	/* Функция преобразования из строки в float и положить*/
}


void Memory::print_segment(const uint16_t &addr, const uint16_t &length) const
{
	const auto end = addr + length;
	for (auto i = addr; i < end; i++)
	{
		printf("%X ", *(m_memory + i));	// в 16-ом виде
		std::cout << std::endl;

		for (int k = sizeof(uint8_t) * 8 - 1; k >= 0; --k)	// в 2ичном
			printf("%d", *(m_memory + i) & (1 << k) ? 1 : 0);
		std::cout << " || ";
	}
	std::cout << std::endl;
}


void Memory::push_data(uint16_t address, const datas argument, const size_t& lngth)
{
	for (auto i = 0; i < lngth; i++)
		* (m_memory + address + i) = argument.ByteMem[i];				// просто кладём 1/2/4 байта в память
}