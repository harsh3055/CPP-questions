#include<iostream>
#include<memory>

namespace apple {
void print() {
	std::cout << "inside apple" << std::endl;
   };
}
namespace orange {
void print() {
	std::cout << "inside orange" << std::endl;
   }
};

class Entity {
public:
	Entity() {
		std::cout << "Entity created here" << std::endl;
	}
	~Entity() {
		std::cout << "Entity deleted here" << std::endl;
	}

};

int main() {
#ifndef ONLINE_JUDGE
	freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
	freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif
	enum season {
		summer = 2,
		winter = 5,
		rainy = 6
	} seasons;

	seasons = summer;
	std::cout << seasons;

	enum casess {
		Bold = 1,
		Italics = 2,
		Underline = 4
	} cases2;

	cases2 = Bold;
	std::cout << cases2;
	uint16_t l = 0x1234;
	uint8_t cases = Bold | Italics;
	//cout << cases << endl;
	printf("binary is %o\n", l);


// #if 0
	{

		{
			Entity* ent11 = new Entity;
			//shared_ptr<Entity>ent1 = make_shared<Entity>();
			std::cout << "hello" << std::endl;
			//shared_ptr<Entity>e = ent1;
			std::cout << "hello1" << std::endl;
			delete ent11;
		}
		std::cout << "hello3" << std::endl;
	}
// #endif
	apple::print();
	orange::print();

}
