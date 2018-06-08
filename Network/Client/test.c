
using namespace std;

void startupClient(int op, int echoServPort, char *servIP);

int main() {
	startupClient(2, 8080, "169.228.184.115");
	return 0;
}
