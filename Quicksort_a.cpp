#include <fstream>
#include<iostream>
using namespace std;

void exchange(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

void quicksort(int (&data)[100000],int start, int end)
{
	if (start<end){
		int i = start;
		int j = start + 1;
		while (1){
			if (data[j] >= data[start]){
				j++;
			}
			else{
				i++;
				exchange(data[i], data[j]);
				j++;
			}
			if (j > end)
				break;
		}
		exchange(data[start], data[i]);
		quicksort(data, start, i - 1);
		quicksort(data, i + 1, end);
	}
}

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	if (!fin)
	{
		cout << "ÀÉ®×Åª¨ú¥¢±Ñ" << endl;
		system("pause");
		return 0;
	}
	int num;
	fin >> num;
	int data[100000];
	for (int j = 0; j < num; j++)
	{
		fin >> data[j];
	}
	quicksort(data, 0, num-1);
	for (int j = 0; j < num; j++)
	{	
		if (j==0)
		fout<< data[j];
		else
		fout<<' '<<data[j];
	}
	fin.close();
	fout.close();
}