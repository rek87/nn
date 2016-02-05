#ifndef NEURON_H
#define NEURON_H

#include <stdio.h>

#include <include/helper.h>


struct Neuron;

// It might be a CRTP if virtual function is too slow
struct ReceivingPort {
	virtual void notify_input(unsigned i) = 0;

	ReceivingPort *prev;
	ReceivingPort *next;
};

struct InputPort: public ReceivingPort {
	void notify_input(unsigned i);

	Neuron *n;
	unsigned index;
};

struct OutputValue: public ReceivingPort {
	void notify_input(unsigned i);

	bool ready;
	unsigned v;
};

struct SendingPort {
	void send(unsigned o);
	void link(ReceivingPort *p);

	LinkedItem<ReceivingPort, &ReceivingPort::prev, &ReceivingPort::next> links_;
};


struct Neuron {
  public:
  Neuron(unsigned n);

	InputPort *in;
	SendingPort out;
	unsigned *weights;

	unsigned partial_sum;
	unsigned missing; // Missing inputs to calculate output

	void read_input(unsigned index, unsigned in);
};

#endif
