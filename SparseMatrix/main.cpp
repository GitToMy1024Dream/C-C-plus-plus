#include "SparseMatrix.h"
int main()
{
	 int array[6][5] = {
						{ 1, 0, 3, 0, 5 },
						{ 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0 },
						{ 1, 0, 3, 0, 5 },
						{ 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0 } };
	 int array2[6][5] = {
						{ 1, 0, 3, 0, 5 },
						{ 0, 3, 0, 0, 0 },
						{ 7, 0, 4, 0, 8 },
						{ 1, 0, 3, 6, 5 },
					    { 2, 1, 0, 0, 0 },
						{ 1, 0, 3, 0, 9 } };
	 SparseMatrix<int> _s((int*)array,
		 sizeof(array)/sizeof(array[0]),
		 sizeof(array[0])/sizeof(array[0][0]),0); 
	 SparseMatrix<int> _ss((int*)array2,
		 sizeof(array2) / sizeof(array2[0]),
		 sizeof(array2[0]) / sizeof(array2[0][0]), 0);
	 _s.Display();
	 cout << endl;
	 _ss.Display();
	 _ss = _ss + _s;
	 cout << endl;
	 _ss.Display();
	 /*cout << _s.Access(0, 0) << endl;
	 cout << _s.Access(0, 2) << endl;
	 cout << _s.Access(0, 4) << endl;
	 cout << _s.Access(3, 0) << endl;
	 cout << _s.Access(4, 0) << endl;*/
	/* SparseMatrix<int> _s1 = _s.Transprot();
	 cout << _s1.Access(2, 0) << endl;
	 _s.Display();
	 cout << endl;
	 _s1.Display();*/
	// SparseMatrix<int> _s2 = _s.FastTransprot();
	// SparseMatrix<int> _s3 = _s;
	// SparseMatrix<int> _s4 = _s3 + _s;
	/* _s.Display();
	 cout << endl;
	 _s4.Display();*/
	// _s.Display();
	// cout << endl;
	// _ss.Display();
	// cout << endl;
	// SparseMatrix<int> _s5 = _s + _ss;
	// _s5.Display();
 	 //_s.Display();
	 //_s2.Display();
	 system("pause");
	 return 0;
}
