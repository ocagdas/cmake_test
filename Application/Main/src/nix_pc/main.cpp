#include "common/CommonStartup.h"

int main() {
   std::string startupMsg("starting from: ");
   startupMsg.append(__FUNCTION__);
   startupMsg.append("@");
   startupMsg.append(__FILE__);

   toyproj::CommonStartup(startupMsg);
 
   return 0; 
}

