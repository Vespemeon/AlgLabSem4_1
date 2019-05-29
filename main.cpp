#include "linkedList.h"

int main() {

	List<int> *list = new List<int>({ 13, 19, 16, 8 });

	list->insert(15, 3);

	std::cout << *list << std::endl;

	system("PAUSE");

	return 0;
}
