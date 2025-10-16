#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

class Replace{
	private:
		std::string _filename; 	//対象ファイル名
		std::string _string1;	// 置換元文字列
		std::string _string2;	// 置換後文字列
		
	public:
		
		Replace(const std::string &filename,
				const std::string &string1,
				const std::string &string2);
		
		~Replace();
		
		void replace();
		
		void processLine(std::string &line);
};

#endif
