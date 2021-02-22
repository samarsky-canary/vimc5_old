#pragma once
#include <cstdint>
#include "Typos.h"
#include "Memory.h"

class Processor
{
	POH _poh;
	PSW _psw;
	address PC;		// счётчик адреса команды
	address RI;		// регистр адреса таблицы прерываний
	Memory _mem;	// RAM память
};