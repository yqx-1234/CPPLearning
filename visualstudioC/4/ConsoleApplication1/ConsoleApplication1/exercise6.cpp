//Ã¶¾Ù¾ÙÀı
#include "iostream"

int main() {
	enum weekdays{Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday};
	weekdays today;
	today = Monday;
std::cout << today << "\n";
	today = Thursday;
	std::cout << today << "\n";
	switch (today) {
	case Monday:
		break;
	}
	return 0;
}