class Officer {
private:
    static Officer* officer;

    int damage;
    int health;
    int armor;



    Officer(): damage(40), health(200), armor(80) {}
    virtual ~Officer() {}



public:
    static Officer* create_officer(){
        if(!officer){
            officer = new Officer();
        }
        return officer;
    }

    static bool kill_officer(){
        if(officer){
            delete officer;
            officer = 0;
            return true;
        }
        return false;
    }

    void show_stats(){
        std::cout << "Officer's stats!" << std::endl;
        std::cout << "Damage " << damage << std::endl;
        std::cout << "Health " << health << std::endl;
        std::cout << "Armor " << armor << std::endl;
    }
};
