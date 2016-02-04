#include <include/neuron.h>

void InputPort::notify_input(unsigned i)
{
	n->read_input(index, i);
}

void OutputValue::notify_input(unsigned i)
{
	ready = true;
	v = i;
}

void SendingPort::link(Port *p)
{
	links_.append(p);
}

void SendingPort::send(unsigned o)
{
	Port *p = links_.head();
	while (p != NULL) {
		p->notify_input(o);
		p = links_.next(p);
	}
}

void Neuron::read_input(unsigned index, unsigned in)
{
	// Calculate weighted sum
	partial_sum += in * weights[index];
	--missing;

	if (missing == 0) {
		unsigned o = partial_sum;
		out.send(o);
	}
}
