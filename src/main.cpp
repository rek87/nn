#include <iostream>
using namespace std;
#include <vector>

#include <include/neuron.h>

int main(void) 
{
	std::vector<Neuron<2>> network(3);
	SendingPort input;
	OutputValue res;

	// Build the network
	inputs[0].link(&network[0].in[0]);
	inputs[0].link(&network[0].in[1]);
	inputs[1].link(&network[1].in[0]);
	inputs[1].link(&network[1].in[1]);

	network[0].out.link(&network[2].in[0]);
	network[1].out.link(&network[2].in[1]);

	network[2].out.link(&res);

	// Do a forward iteration
	std::vector<unsigned> in_v = {
	for (unsigned i = 0; i < inputs.size(); ++i) {

	}

  return 0;
}

