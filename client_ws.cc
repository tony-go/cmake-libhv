#include "hv/WebSocketClient.h"
using namespace hv;

int main(int argc, char **argv) {
  WebSocketClient ws;
  ws.onopen = []() {
    printf("onopen\n");
    printf("Type your message:\n");
  };
  ws.onmessage = [](const std::string &msg) {
    printf("onmessage: %.*s\n", (int)msg.size(), msg.data());
  };
  ws.onclose = []() { printf("onclose\n"); };

  ws.open("ws://127.0.0.1:9999/ws");

  std::string str;
  while (std::getline(std::cin, str)) {
    if (!ws.isConnected())
      break;
    if (str == "quit") {
      ws.close();
      break;
    }
    ws.send(str);
  }

  return 0;
}
