#include <iostream>
#include <stdlib.h>
#include <vector>


using namespace std;

int length;

// The following function used to swap two char or numbers
void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y =  temp;
}

// The following functions create all the permuations by swapping each numbers or char
void permute(vector<int> &vec, int l, int r){
	if (l == r){
		for(int z = 0; z < vec.size(); z++){
			cout << vec[z] << " ";
		}
		cout << endl;
	}
	else{
		for(int i = l; i <= r; i++){
			swap(vec[l], vec[i]);
			permute(vec, l+1, r);
			//back tracking 
			swap(vec[l], vec[i]);
		}
	}
}


int main(){
	cout << "How many numberes you want to shuffle: ";
	cin >> length;

	vector<int> n(length);
	
	cout << "give " << length << " numbers: " << endl;


	// insert all the numbers in a vector
	for(int i = 0; i < length; i++){
		cin >> n[i];
	}

	//calculate all the permutation the inserted numbers can generate
	// if there are four numbers then the number of permutaion will be 
	// 4! = 4 * 3 * 2 * 1 = 24
	long perm = 1;
	int index = length;
	do{
		perm = perm * index;
		index = index - 1;
	}while(index > 1);

	cout << "The given number will generate total " << perm << " numbers of permutation" << endl;
	cout << "and they are: " << endl;

	//create and print all the permutaions
	permute(n, 0, length -1);

	
	return 0;
}
