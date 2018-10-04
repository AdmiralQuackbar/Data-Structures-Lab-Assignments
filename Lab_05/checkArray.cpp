int checkArray(string *A, int array_size);

//checks if array is ascending or descending or neither
int checkArray(string *A, int array_size)
{
    bool ascend = false;
    bool descend = false;
    //checks each adjacent element if they are descending or ascending
    for(int counter = 1; counter < array_size; counter++) 
    {
	if(A[counter] > A[counter - 1]) {
	    ascend = true;
	}	
	else if(A[counter] < A[counter - 1]) {
	    descend = true;
	}
    }
    //returns ascending only if the ascend bool is true
    if(ascend && !descend) {
	return 1;
    }
    //returns descending only if descend bool is true
    else if(!ascend && descend) {
	return -1;
    }
    //returns unsorted only if both descend and ascend bool are both true or both false
    else {
	return 0;
    }
}
