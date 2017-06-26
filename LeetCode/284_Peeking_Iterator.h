//284_Peeking_Iterator.h
//3ms	100.00%

/*
Acceptance:35.35%
Instruction: LeetCode 284 - Peeking Iterator - [M]
Developer: lrushx
Process Time: June 26, 2017
*/

/*
Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() operation -- it essentially peek() at the element that will be returned by the next call to next().
Here is an example. Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].
Call next() gets you 1, the first element in the list.
Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.
You call next() the final time and it returns 3, the last element. Calling hasNext() after that should return false.
Follow up: How would you extend your design to be generic and work with all types, not just integer?
*/




// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    int tmp_next=INT_MIN;
    bool tmp_hasNext;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    tmp_hasNext = Iterator::hasNext();
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
	    if (tmp_next != INT_MIN)
	        return tmp_next;
        tmp_hasNext = Iterator::hasNext();
        if (tmp_hasNext) tmp_next = Iterator::next();
        return tmp_next;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (tmp_next == INT_MIN){
	        int nex = Iterator::next();
	        tmp_hasNext = Iterator::hasNext();
	        return nex;
	    }
        int nex = tmp_next;
        tmp_next = INT_MIN;
        tmp_hasNext = Iterator::hasNext();
        return nex;
	}

	bool hasNext() const {
	    return tmp_hasNext;
	}
};
