#include "ArrayTest.h"

void testUseArray() {
	int* mArray = new int[10];
	int* arr2 = new int[5] {1, 2, 3};
	delete[] mArray;   // 数组一定要加 []
	mArray = nullptr;
	int mArray1[56]{ 1,2,3 };
	//cout << mArray1[1] << endl;
}

