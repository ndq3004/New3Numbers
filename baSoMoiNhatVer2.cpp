//dua ra day so dai nhat chi xuat hien 3 gia tri so
#include<iostream>
#include<fstream>
using namespace std;
struct save{
	int key;
	int value;
}x, y, z;
	int n;
	int Arr[100];
void swap1(save &x, save &y){
	swap(x.key,y.key);
	swap(y.value,x.value);
}
void renew(save &x,int a, int i ) {
	x.key = i;
	x.value = a;
}
void daycon(int Arr[100], int n) {
	int max, imax, length, iCurrent, i,k;
	x.key=x.value=y.key=y.value=z.key=z.value=0;
	//update x
	k = 0;
	renew(x, Arr[0], k);
	//update x,y
	k++;
	while (k < n){
		if (Arr[k] == x.value) renew(x, Arr[k], k);
		else {
			renew(y, Arr[k], k);
			if (Arr[k + 1] != y.value) break;
			
		}
		k++;
	}
	//update x,y,z
	k++;
		while(k<n) {
			if (Arr[k] == x.value) renew(x, Arr[k], k);
			else if (Arr[k] == y.value) renew(y, Arr[k], k);
			else {
				renew(z, Arr[k], k);
				if (Arr[k + 1] != z.value) break;
				
			}
			k++;
	}
	k=z.key+1;cout<<k<<endl;
		// tempo x,y,z dau tien
	//vòng lap chinh
		length =k; ; imax = 0; max = length; iCurrent=0;
		for (i = k ; i < n; i++) {
			if (Arr[i] == x.value || Arr[i] == y.value || Arr[i] == z.value)
			{
				if (Arr[i] == x.value)
				{
					swap1(x, z);
					swap1(y, x);				
				}
				else if (Arr[i] == y.value)
				{
					swap1(y, z);	
				}
				 renew(z, Arr[i], i);
				length++;
				if (max < length)
				{
					max = length;
					imax = iCurrent;
				}
				cout<<"|"<<x.key<<"|"<<y.key<<"|	"<<z.key<<endl;
			}
			else
			{
				iCurrent = x.key + 1;
				if (Arr[iCurrent] == y.value)
				{
					swap1(y, z);
				}
				renew(z,Arr[i],i);
				renew(x, Arr[iCurrent], iCurrent);
				cout<<endl<<"|"<<x.key<<"|"<<y.key<<"|	"<<z.key<<endl;
				length = i - iCurrent + 1;
				if(max<length)
				{
					max = length;
					imax = iCurrent;
				}
			}
		}
		cout << "day dai nhat la" << endl;
		for (i = imax; i < imax + max; i++) {
			cout << Arr[i] << "  ";
	}
	cout<<endl;
		cout<<"day con co tat ca "<<max<<" phan tu "<<"bat dau tu vi tri so "<<imax;
}
int main()
{

	fstream f;
	f.open("k.txt", ios::in);
	f >> n;
	while (!f.eof()) {
		for (int i = 0; i < n; i++) f >> Arr[i];
	}
	f.close();
	daycon(Arr, n);
	return 0;
}
