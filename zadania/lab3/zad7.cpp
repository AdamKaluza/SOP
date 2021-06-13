#include <iostream>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

auto handler_sigusr1(int signum) -> void {
  char msg[] = "Signal ?? SIGUSR1\n";
  msg[7] = (signum / 10) + '0';
  msg[8] = (signum % 10) + '0';
  auto ret = write(2, msg, sizeof(msg) - 1);
  std::cout << ret;
}
auto main() -> int {
  struct sigaction action;

  action.sa_flags = 0;
  action.sa_handler = handler_sigusr1;
  sigemptyset(&action.sa_mask);

  sigaction(SIGUSR1, &action, NULL);

  return 0;
}
