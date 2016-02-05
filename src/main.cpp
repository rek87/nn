#include <iostream>
using namespace std;
#include <vector>

#include <include/neuron.h>

int main(void) 
{
  std::vector<Neuron> in_stage(4, Neuron(1)); //Input stage
	std::vector<Neuron> network(4, Neuron(4)); // Hidden stage
	Neuron out_stage(4);

	SendingPort input;
	OutputValue res;

	// Build the network
	// Link input stage
	for (unsigned i = 0; i < in_stage.size(); ++i)
	  input.link(&in_stage[i].in[0]);

	// Fully link hidden stage
	for (unsigned i = 0; i < in_stage.size(); ++i)
	  for (unsigned j = 0; j < network.size(); ++j)
	    in_stage[i].out.link(&network[j].in[i]);

	// Link output stage
	for (unsigned i = 0; i < network.size(); ++i)
	  network[i].out.link(&out_stage.in[i]);
	out_stage.out.link(&res);

	// Do a forward iteration
	input.send(3);
	if (res.ready)
	  cout << "Value: " << res.v << endl;

  return 0;
}

