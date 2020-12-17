#include <string>
#include "CScreen.h"
#include "konvey.h"


class Command
{
    private:
      //enum eCommand { CMD_NOCOMMAND = 0, CMD_RESET, CMD_SET, CMD_CLEAR, CMD_STEP, CMD_BACK, CMD_SAVE, CML_LOAD, CVD_EXIT };

    public:
    //	Command();
    //   ~Command();
       void playGame(CScreen screen);
       void print_world(CScreen screen, konvey &wrd);
       void set_comm(CScreen screen);
       int sTOi(std::string str);
       void saveF(const std::string fileName, konvey &wrd) const;
       int loadF(const std::string fileName, konvey &wrd);
       friend std::ostream& operator<<(std::ostream& os, konvey& wrd);
       
};
  
