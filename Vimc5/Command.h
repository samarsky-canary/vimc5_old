#pragma once
#include <cstdint>

enum command_size
{
	two = 2,
	four = 4,
};
class Command
{
public:
	Command(const uint8_t &size_com) : _size_command(size_com) {}

	virtual void operator() ();
private:
	uint8_t _size_command;
};

class Command_2Byte : public Command
{
	using Command::Command;

};

class Command_4Byte : public Command
{
	Command_4Byte() : Command(command_size::four) {}
};

//-------------------------------------------------------------------------------------------------------
/*                                  ÷≈ÀŒ◊»—À≈ÕÕ¿ﬂ ¿–»‘Ã≈“» ¿                                           */
//-------------------------------------------------------------------------------------------------------


class Int_math : Command_4Byte
{
	virtual uint16_t accamulate_u16b(uint16_t left, uint16_t right) const noexcept;
	virtual uint32_t accamulate_u32b(uint32_t left, uint32_t right) const noexcept;
	virtual int16_t  accamulate_16b (int16_t left,  int16_t right) const noexcept;
	virtual int32_t  accamulate_32b (int32_t left,  int32_t right) const noexcept;
};

class Int_add final : Int_math
{
	uint16_t accamulate_u16b(uint16_t left, uint16_t right) const noexcept override { return left + right; }
	uint32_t accamulate_u32b(uint32_t left, uint32_t right) const noexcept override { return left + right; }
	int16_t accamulate_16b (int16_t left, int16_t right) const noexcept override { return left + right; }
	int32_t accamulate_32b (int32_t left, int32_t right) const noexcept override { return left + right; }
};

class Int_sub final : Int_math 
{
	uint16_t accamulate_u16b(uint16_t left, uint16_t right) const noexcept override { return left - right; };
	uint32_t accamulate_u32b(uint32_t left, uint32_t right) const noexcept override { return left - right; }

};

class Int_mul final : Int_math
{
	uint16_t accamulate_u16b(uint16_t left, uint16_t right) const noexcept override { return left * right; };
	uint32_t accamulate_u32b(uint32_t left, uint32_t right) const noexcept override { return left * right; }

};

class Int_div final :  Int_math
{
	uint16_t accamulate_u16b(uint16_t left, uint16_t right) const noexcept override { return left / right; };
	uint32_t accamulate_u32b(uint32_t left, uint32_t right) const noexcept override { return left / right; }

};
//-------------------------------------------------------------------------------------------------------
/*                                      Œœ≈–¿÷»» —–¿¬Õ≈Õ»ﬂ                                             */
//-------------------------------------------------------------------------------------------------------


class Int_comp : Command_4Byte
{
	virtual bool compare_32b();

};

//-------------------------------------------------------------------------------------------------------
/*                                      ƒ–Œ¡Õ¿ﬂ ¿–»‘Ã≈“» ¿                                             */
//-------------------------------------------------------------------------------------------------------

class Float_math : Command_4Byte
{
	virtual float accamulate_f(float left, float right) const noexcept;
};


class Float_add final : Float_math
{
	float accamulate_f(float left, float right) const noexcept override { return left + right; }
};

class Float_sub final : Float_math
{
	float accamulate_f(float left, float right) const noexcept override { return left - right; }
};

class Float_mul final : Float_math
{
	float accamulate_f(float left, float right) const noexcept override { return left * right; }
};

class Float_div final : Float_math
{
	float accamulate_f(float left, float right) const noexcept override { return left / right; }
};