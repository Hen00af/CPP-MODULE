#include "replace.hpp"

Replace::Replace(const std::string &pfilename,
				 const std::string &string1, 
				 const std::string &string2):
    _filename(pfilename), _string1(string1), _string2(string2) {
		std::cout << "Replace has been called" << std::endl;
}

Replace::~Replace()
{
	std::cout << "Replace destructor has been called" << std::endl;
}

void Replace::replace()
{
    std::ifstream ifs(_filename.c_str());
    if (!ifs.is_open()) {
        std::cerr << "Error: cannot open input file: " << _filename << std::endl;
        return;
    }

    std::string line;
    std::string stream;
    while (std::getline(ifs, line)) {
        processLine(line);
        stream.append(line);
		if(!ifs.eof())
			stream.push_back('\n'); 
    }
    ifs.close();

    std::string out_filename = _filename + ".replace";
    std::ofstream ofs(out_filename.c_str(), std::ios::out);
    if (!ofs.is_open()) {
        std::cerr << "Error: cannot open output file: " << out_filename << std::endl;
        return;
    }

    ofs << stream;
    ofs.close();

    std::cout << "Created: " << out_filename << std::endl;
}

void Replace::processLine(std::string &line)
{
	size_t pos = 0;
	while ((pos = line.find(_string1, pos)) != std::string::npos)
	{
		line.erase(pos, _string1.length());
		line.insert(pos, _string2);
		pos += _string2.length();
	}
}
