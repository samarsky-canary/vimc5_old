#pragma once
#include <string>
#include <limits>
#include "doctest/doctest.h"
#include "Typos.h"

class Memory
{
public:
	Memory() {
		m_memory = new uint8_t[std::numeric_limits<uint16_t>::max() + 1];	/*	размер памяти 2^16 Кбайт (размер адреса 16 бит) */
	}
	~Memory() {
		delete[] m_memory;
	}
	/*		Команды занесения в память	*/	
	void put_byte	(const uint8_t		&byte,	  uint16_t& pos);	// байт в память
	void put_2bytes	(const uint16_t		&t_short, uint16_t& pos);	// 2 байта в память
	void put_4bytes	(const uint32_t		&t_long,  uint16_t& pos);	// 4 байта в память
	void put_short	(const std::string	&t_short, uint16_t& pos);	// короткое целое в память
	void put_int	(const std::string	&t_int,   uint16_t& pos);	// длинное целое в память
	void put_float	(const std::string	&t_float, uint16_t& pos);	// дробное в память


	//TODO: ВСЁ ВЫШЕ УДАЛИТЬ!!!

	// Занесение в память (куда, что, какого размера)
	void push_data	(uint16_t address, const datas argument, const size_t& lngth);

	/*	DEBUG	*/	
	void print_segment(const uint16_t &addr, const uint16_t& length) const;

private:
	unsigned char *m_memory;
} inline pc_memory;
