#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include  "Processor.h"

bool parse(const std::string& tmp, std::vector<std::string>& args, Processor& p, uint16_t& offset);
void Upload(std::ifstream& file, Processor& p);