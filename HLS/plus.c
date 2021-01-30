#include "plus.h"

int plus_test(int x){
#pragma HLS INTERFACE s_axilite port=x
#pragma HLS INTERFACE s_axilite port=return
	return x+1;
}
