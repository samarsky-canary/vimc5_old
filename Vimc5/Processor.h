#pragma once
#include <cstdint>
#include "Typos.h"
#include "Memory.h"
#include "Registers.h"

class Processor
{
public:
	void push_data( uint16_t address, const datas argument, const size_t &lngth);
	void setIP(uint16_t& address) {_psw.ip = address; }
	uint16_t getIP() { return _psw.ip; }
	void debug();

	void print_segment(const size_t& addr, const size_t& length) const
	{
		_mem.print_segment(addr, length);
	}
private:
	POH _poh;
	PSW _psw;
	Memory _mem;	// RAM пам€ть
	//TODO: ƒобавить указатель на структуру команд Command *CommandList
};

