#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <stdexcept>


// iterator
template<typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), 10);
	if(it == container.end()) {
		throw std::runtime_error("Can`t find in this container...!");
	}
	return it;
}

// typename T::irerator easyfind(T &container, int value) {
// 	T it = std::find(container.begin, container.end(), 10);
// }

int main() {
	std::vector<int> i;

	try {
		easyfind(i, 10);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
