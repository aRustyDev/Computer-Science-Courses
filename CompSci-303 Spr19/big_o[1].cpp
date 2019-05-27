int function_1(int n){
	int count = 0;
	for (int i = n; i > 0; i /= 2)
		count++;
	return count;
}

int function_2(int n){
	int count = 0;
	for (int i = 1; i < n; i *= 2)
		count++;
	return count;
}

int function_3(int n){
	int count = 0;
	for (int j = 1; j < n; j *= 2) {  //1+2^1+2^2+..+2^(n/2 - 2) )
		for (int k = 0; k < j; k++) {
			count++;
		}
	}

	return count;
}

int function_a(int n){
	int count = 0;
	for (int k = 0; k < n; k += 2) {
		count++;
	}
	return count;

}


int main(){
	int count = function_a(8);

	count = function_1(8);
	count = function_1(4);
	count = function_1(2);

	count = function_2(8);

	count = function_3(10);
}
