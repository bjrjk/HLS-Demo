#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "plus.h"

int main(){
	for(int i=0;i<10;i++){
		if(plus_test(i)==i+1)continue;
		return 1;

	}
	return 0;
}
