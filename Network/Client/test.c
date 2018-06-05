
using namespace std;

void startupClient(int op, int echoServPort, char *servIP);

int main() {
	startupClient(2, 8080, "127.0.0.1");
	return 0;
}
