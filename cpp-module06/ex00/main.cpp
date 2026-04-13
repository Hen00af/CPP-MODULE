#include <iostream>
#include <sstream>

int is_num(std::string str)	{
	
	// string streamへ変換

	std::stringstream ss(str);

	// number かどうかのはんてい
	int num;
	if( !(ss >> num) || !ss.eof())	{
		return 0;
	}
	return 1;
}

int stoi(std::string str) {
	std::stringstream ss(str);
	int num;
	ss >> num;
	return (num);
}

int main(int ac, char **av)	{

	if( ac != 2 )	{
		std::cerr << "{Usage}: "<< av[0] << " <number>" << std::endl;
		 return -1;
	}

	if (!is_num(av[1])) {
		std::cerr << "{Usage}: "<< av[0] << " <number>" << std::endl;
		return -1;
	}

	int num = stoi(av[1]);

	std::cout << num << std::endl;

	return 0;
}