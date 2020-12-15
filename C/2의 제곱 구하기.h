#include <iostream>
using namespace std;

int main(){
	int num;
	cin >> num;
	
	for(;;){
		if(num == 1){
			cout << 1;
			break;
		}
		if(num % 2 == 0){
			num = num / 2;
		}
		else{
			cout << 0;
			break;
		}
	}
}