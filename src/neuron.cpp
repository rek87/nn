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

void SendingPort::link(ReceivingPort *p)
{
	links_.append(p);
}

void SendingPort::send(unsigned o)
{
  ReceivingPort *p = links_.head();
	while (p != NULL) {
		p->notify_input(o);
		p = links_.next(p);
	}
}

Neuron::Neuron(unsigned n): in(new InputPort[n]), weights(new unsigned [n]),
    missing(n)
{
  FILE *f = fopen("/dev/urandom", "rb");
  for (unsigned i = 0; i < n; ++i) {
    fread(&weights[i], sizeof(unsigned), 1, f);
    in[i].n = this;
    in[i].index = i;
  }
  fclose(f);
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

