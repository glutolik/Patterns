#include <iostream>
#include <memory>

class Infantry{
private:
    int damage;
    int health;
    int armor;
public:
    Infantry() {}
    ~Infantry() {}

    void SetDamage(const int& d){
        damage = d;
    }
    void SetHealth(const int& h){
        health = h;
    }
    void SetArmor(const int& a){
        armor = a;
    }

    void show_stats(){
        std::cout << "Unit's stats!" << std::endl;
        std::cout << "Damage " << damage << std::endl;
        std::cout << "Health " << health << std::endl;
        std::cout << "Armor " << armor << std::endl;
    }
};

class InfantryUnitBuilder{
protected:
    std::shared_ptr<Infantry> unit;
public:
    InfantryUnitBuilder() {}
    virtual ~InfantryUnitBuilder() {}

    std::shared_ptr<Infantry> create_unit(){
        return unit;
    }

    void create_infantry_unit() {
        unit.reset (new Infantry);
    }
    virtual void set_damage()=0;
    virtual void set_health()=0;
    virtual void set_armor()=0;
};

class SwordsmanBuilder : public InfantryUnitBuilder{
public:
    SwordsmanBuilder() : InfantryUnitBuilder() {}
    ~SwordsmanBuilder() {}

    void set_damage(){
        unit->SetDamage(10);
    }
    void set_health(){
        unit->SetHealth(100);
    }
    void set_armor(){
        unit->SetArmor(50);
    }
};

class ArcherBuilder : public InfantryUnitBuilder{
public:
    ArcherBuilder() : InfantryUnitBuilder() {}
    ~ArcherBuilder() {}

    void set_damage(){
        unit->SetDamage(15);
    }
    void set_health(){
        unit->SetHealth(80);
    }
    void set_armor(){
        unit->SetArmor(20);
    }
};

class KnightBuilder : public InfantryUnitBuilder{
public:
    KnightBuilder() : InfantryUnitBuilder() {}
    ~KnightBuilder() {}

    void set_damage(){
        unit->SetDamage(20);
    }
    void set_health(){
        unit->SetHealth(120);
    }
    void set_armor(){
        unit->SetArmor(100);
    }
};

class Barrack{
private:
    InfantryUnitBuilder* unit_builder;
public:
    Barrack() : unit_builder(NULL) {}
    ~Barrack() {}

    void set_unit_builder(InfantryUnitBuilder* b){
        unit_builder = b;
    }

    std::shared_ptr<Infantry> create_unit(){
        return unit_builder->create_unit();
    }

    void train_unit(){
        unit_builder->create_infantry_unit();
        unit_builder->set_damage();
        unit_builder->set_health();
        unit_builder->set_armor();
    }
};


