#include multicounter.h

//Resets the internal counter of counterIndex to zero

    static void FOS::resetCounter(int counterIndex){
        if(counterIndex-1 <sizeof([this->counters])/sizeof(this->counters[0]))
            this->counters[counterIndex-1] = 0;

    }

// Returns the current count for given counterIndex
// return the current count for given counterIndex
	 
	static int FOS::getCount(int counterIndex) {
		if (counterIndex-1 < sizeof([this->counters])/sizeof(this->counters[0]))
			return this->counters[counterIndex-1];
		return -1;
    }

    
//Increases the current count of counterIndex by 1. Returns always true so that it can be used
//in boolean statements
//return always true
	
	static boolean FOS::increaseCounter(int counterIndex) {
		if (counterIndex-1 < )
			this->counters[counterIndex-1]++;
		return true;
	}



//Increases the current count of counter given by counterIndex by step. Returns always true so that it can be
//used in boolean statements. Step could be negative. It is up to the specific
//usage scenario whether this is desirable or not.
//@param step The amount to increase the counter
//return always true
	static boolean increaseCounter(int counterIndex, int step) {
		if (counterIndex-1 < sizeof([this->counters])/sizeof(this->counters[0]))
			this->counters[counterIndex] = this->counters[counterIndex-1] + step;
		return true;
	}