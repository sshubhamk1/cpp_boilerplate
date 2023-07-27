#include <string>
class Shubham
{
    private:
        std::string m_name;
        int m_mob;
    public:
        std::string get_name();
        void set_name(std::string name);
        int get_mob();
        void set_mob(int mob);
        void display_info();
        Shubham();
        Shubham(std::string name, int mob);
};