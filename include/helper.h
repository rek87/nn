#ifndef HELPER_H
#define HELPER_H

template<class I, I* I::*P, I* I::*N>
class LinkedItem {
	typedef I Item;
public:
	void append(Item *i) {
		//TODO
	}

	void remove(Item *i) {
		//TODO
	}

	Intem *next(Item *i) {
		//TODO
	}

	Item *head(void) { return h_; }
	Item *tail(void) { return t_; }

private:
	Item h_;
	Item t_;

	unsigned size_;
};

#endif
