#include <fstream>
#include <string>

typedef enum 
{
    t_states,
    t_alphabet,
    t_startstate,
    t_finalstate,
    t_transition,
    t_id,
    t_eof
} token;

extern char token_image[100];
std::ifstream dmfFile;
extern token scan();
void openFile(std::string filename);
extern std::string getTokenImage();
