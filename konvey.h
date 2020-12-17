#include <windows.h>


/*
#define WORLD_H 10
#define WORLD_W 10
*/

class konvey {
    
private:
	int step;
	char ** wrd;
	char ** old_wrd;
	//friend std::ostream& operator<<(std::ostream& os, const konvey & game);
	
public:
	konvey();
    ~konvey();
    void clr_world();
    unsigned int get_live_count();
    void read_point_neighbors(unsigned int nb[][2], int x, int y);
    unsigned int count_live_neighbors(unsigned int x, unsigned int y);
    void swap_world();
    int cmp_world();
    char get_world(unsigned int x, unsigned int y);
    char get_old(unsigned int x, unsigned int y);
    void next_generation();
    void set_pos(unsigned int x, unsigned int y);
    void set_dot(unsigned int x, unsigned int y);
    char* get_world_str(unsigned int x);
    int get_step();
    void set_step(int x);
};





