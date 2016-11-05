#include "../libs/application.hpp"
#include <memory>

int main() {
  std::unique_ptr<Application> a(new Application());
  a->start();
  return 0;
}
