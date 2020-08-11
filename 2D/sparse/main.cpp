#include "Sparse.h"

int main(){

	Sparse* s1 = new Sparse(3, 3, 3);
	Sparse* s2 = new Sparse(3, 3, 3);
	Sparse* s3;

	std::cin >> s1;
	std::cin >> s2;
	
	std::cout << s1;
	std::cout << s2;
	
	s3 = *s1 + s2;
	std::cout << s3;

	delete s1, s2, s3;
	return 0;
}
