#include <signal.h>
#include <string>
#include <sys/types.h>

auto main(int argc, char *argv[]) -> int {
  auto to_pid = std::stoi(argv[1]);
  auto use_signal = std::stoi(argv[2]);

  kill(to_pid, use_signal);

  return 0;
}
