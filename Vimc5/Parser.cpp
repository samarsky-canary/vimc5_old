
#include "Parser.h"
#include "Typos.h"
#include "switch_string.h"
#include <map>


using namespace std;

namespace syntax
{
	std::map<std::string, unsigned>_registers;
	inline void init_regs_short()
	{
		_registers["s1"] = 0;
		_registers["s2"] = 1;
		_registers["s3"] = 2;
		_registers["s4"] = 3;
		_registers["s5"] = 4;
		_registers["s6"] = 5;
		_registers["s7"] = 6;
		_registers["s8"] = 7;
	}

	inline void init_regs_long()
	{
		_registers["l1"] = 0;
		_registers["l2"] = 2;
		_registers["l3"] = 4;
		_registers["l4"] = 6;
	}

	inline void init_regs_float()
	{
		_registers["f1"] = 0;
		_registers["f2"] = 2;
		_registers["f3"] = 4;
		_registers["f4"] = 6;
	}
	/* Сопоставление текста регистра и его номера*/

	void init_registers()
	{
		/* short regs*/
		init_regs_short();

		/* long regs*/
		init_regs_long();

		/* float regs*/
		init_regs_float();

	}
}

void inline substr_minus_from_number(string& number)
{
	if (number[0] == '-')
		number = number.substr(1, number.size() - 1);
}

bool is_number(const string& number)
{
	string temp = number;

	substr_minus_from_number(temp);
	return temp.find_first_not_of("0123456789") == string::npos;
}

bool is_float_number(const string& number)
{
	string temp = number;
	substr_minus_from_number(temp);
	auto pos = temp.find_first_not_of("0123456789");

	if (pos == string::npos)
		return true;

	return (temp[pos] == '.') ?
		temp.find_first_not_of("0123456789", pos + 1, temp.size()) == string::npos :
		false;
}

bool parse(const string& tmp, vector<string>& args, Processor& p, uint16_t& offset)
{
	stringstream str(tmp);
	string word;
	datas _datas;
	while (str >> word)
		args.push_back(word);
	SWITCH(args[0])
	{
		CASE("s") :
		{
			if (args.size() < 2 || !is_number(args[1]))			// 1 argument uint16_t address
				return false;

			auto ip = static_cast<uint16_t>(stoi(args[1]));
			p.setIP(ip);
			//p.debug();
		}
		break;


		CASE("ss") :												// load short signed 16bit num
		{
			if (args.size() < 2 || !is_number(args[1]))
				return false;
			_datas.WordMem[0] = static_cast<int16_t>(stoi(args[1]));

			cout << "num is " << stoi(args[1]) << " to int_16t " << static_cast<int16_t>(stoi(args[1])) << endl;

			p.push_data(p.getIP() + offset, _datas, sizeof(_datas.WordMem[0]));
			offset += sizeof(_datas.WordMem[0]);
			//p.print_segment(p.getIP(),  offset);
		}
		break;


		CASE("su") :											// load short unsigned 16bit num
		{
			if (args.size() < 2 || !is_number(args[1]))
				return false;
			_datas.WordMem[0] = static_cast<int16_t>(stoi(args[1]));

			cout << "num is " << stoi(args[1]) << " to uint_16t" << static_cast<uint16_t>(stoi(args[1])) << endl;

			p.push_data(p.getIP() + offset, _datas, sizeof(_datas.WordMem[0]));
			offset += sizeof(_datas.WordMem[0]);
			//p.print_segment(p.getIP(), offset);
		}
		break;


		CASE("ls") :											// load long signed 32bit num
		{
			if (args.size() < 2 || !is_number(args[1]))
				return false;
			_datas.DwordMem = stoi(args[1]);

			cout << "num is " << stoi(args[1]) << " to int_32t" << stoi(args[1]) << endl;

			p.push_data(p.getIP() + offset, _datas, sizeof(_datas.DwordMem));
			offset += sizeof(_datas.DwordMem);
			//p.print_segment(p.getIP(), offset);
		}
		break;


		CASE("lu") :											// load long unsigned 32bit num
		{
			if (args.size() < 2 || !is_number(args[1]))
				return false;
			_datas.DwordMem = stoi(args[1]);

			cout << "num is " << stoi(args[1]) << " to int_32t" << static_cast<uint32_t>(stoi(args[1])) << endl;

			p.push_data(p.getIP() + offset, _datas, sizeof(_datas.DwordMem));
			offset += sizeof(_datas.DwordMem);
			p.print_segment(p.getIP(), offset);
		}
		break;


		CASE("f") :											// load long unsigned 32bit num
		{
			if (args.size() < 2 || !is_number(args[1]))
				return false;
			_datas.DwordMem = stoi(args[1]);


			p.push_data(p.getIP() + offset, _datas, sizeof(_datas.DwordMem));
			offset += sizeof(_datas.DwordMem);
		}
		break;
	default:
		cout << "default";
		break;
	}
}
/* Чтение файла*/
void Upload(ifstream& file, Processor& p)
{
	//
	//
	int curline = 0;
	uint16_t offset = 0;
	while (!file.eof())
	{
		string tmp;
		vector<string> arguments;
		getline(file, tmp);
		parse(tmp, arguments, p, offset);
		curline++;




	}
}
