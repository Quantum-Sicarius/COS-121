/**
* @Author: Thomas Scholtz <thomas>
* @Date:   2016-11-05T10:58:08+02:00
* @Email:  thomas@quantum-sicarius.za.net
* @Last modified by:   thomas
* @Last modified time: 2016-12-07T19:16:42+02:00
* @License: Attribution-NonCommercial-ShareAlike 4.0 International
*/

#include "../libs/application.hpp"
#include <memory>

int main() {
  std::unique_ptr<Application> a(new Application());
  a->start();
  return 0;
}
