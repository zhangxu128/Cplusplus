#include "Date.h"

void Test1() {
	Date d1;
	Date d2(2019,5,13);
	Date d3(d2);
	Date d4 = d3;
	Date d5(2020, 5, 5);
	d1.print();
	d2.print();
	d3.print();
	d4.print();
	d5.print();

	if (d1 != d2) {
		cout << "d1 != d2" << endl;
	}
	if (d1 < d2) {
		cout << "d1 < d2" << endl;
	}
	if (d3 <= d4) {
		cout << "d3 <= d4" << endl;
	}
	if (d5 > d3) {
		cout << "d5 > d3" << endl;
	}
	if (d5 >= d4) {
		cout << "d5 >= d4" << endl;
	}
	if (d1 != d4) {
		cout << "d1 != d4" << endl;
	}

	Date d = d1++;
	d.print();
	d = ++d2;
	d.print();
	d = --d3;
	d.print();
	d = d4--;
	d.print();

	d5 += 1000;
	d5.print();

	Date d6(2019, 1, 5);
	d6 -= 158;
	d6.print();
	Date d7(2030, 5, 13);
	d = d7 - 100;
	d.print();
	Date d8(2030, 5, 13);
	d = d8 + 100;
	d.print();
	Date d9(2030, 5, 13);
	Date d10(2010, 5, 9);
	int days = d9 - d10;
	cout << days << endl;
}



int main(void) {

	Test1();
	system("pause");
	return 0;
}