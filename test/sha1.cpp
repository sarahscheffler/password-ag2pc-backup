#include <emp-tool/emp-tool.h>
#include "test/single_execution.h"
using namespace std;
using namespace emp;

int main(int argc, char** argv) {
	int party, port;
	parse_party_and_port(argv, &party, &port);
	NetIO* io = new NetIO(party==ALICE ? nullptr:IP, port);
	io->set_nodelay();
	//test(party, io, circuit_file_location+"sha-1.txt", string("92b404e556588ced6c1acd4ebf053f6809f73a93"));
	test(party, io, "test/sha-1_ALICE.txt", "92b404e556588ced6c1acd4ebf053f6809f73a93");
	delete io;
	return 0;
}
