#include <iostream>
using namespace std;

/*
����������� ������� - ����������� ������� ��������������,
������� ������������� ��������� ��� �������� �������� ��������������� ��� ��������������� ��������,
�� ������������ �� ���������� �������.

������������
- ������� �� ������ �������� �� ����, ��� ���������, ����������� � �������������� �������� � ��� �������;
- �������� � ��������� ��������������� ������� ������ �������������� ������ � ���������� ���������� ���������� ����� �����������;
- ������� ������ ����������������� ����� �� �������� ������������ �� ��������;
- ���������� ������������ ���������� ��������, ��������� ������ �� ����������, �� �� ����������.

������� ����������� ������� �������� ���������� ������� � ��������:
 * ��������� ���������� ������.
 * �������� ������ �������� ���������.
 * ����������� ������������ ���������.
 * ���������� ����� ��� ��������� ������.
*/

// AbstractProductA(Weapon) - ��������� ���������(����������� �����) ��� ���� �������-��������
// ����������� ����� - ������
class Weapon abstract
{
public:
	 virtual void Hit() abstract;
};

// ConcreteProductA1(Arbalet)  - ���������� ������-�������, ����������� ��������������� ���������� ��������, 
// � ����� ��������� ��������� Abstract Product
// ����� �������
class Arbalet : public Weapon
{
public:
	void Hit() override
	{
		cout << "We are shooting from a crossbow\n";
	}
};


class Stick : public Weapon
{
public:
	void Hit() override
	{
		cout << "We are killing from a stick\n";
	}
};
// ConcreteProductA2(Sword)  - ���������� ������-�������, ����������� ��������������� ���������� ��������, 
// � ����� ��������� ��������� Abstract Product
// ����� ���
class Sword : public Weapon
{
public:
	void Hit() override
	{
		cout << "We are beating with the sword\n";
	}
};

// AbstractProductB(Movement) - ��������� ���������(����������� �����) ��� ���� �������-��������
// ����������� ����� ��������
class Movement abstract
{
public:
	virtual void Move() abstract;
};

// ConcreteProductB1(FlyMovement)  - ���������� ������-�������, ����������� ��������������� ���������� ��������, 
// � ����� ��������� ��������� Abstract Product
// �����
class FlyMovement : public Movement
{
public:
	void Move() override
	{
		cout << "We are flying\n";
	}
};

class MagicMovement : public Movement
{
public:
	void Move() override
	{
		cout << "We are doing magic\n";
	}
};
// ConcreteProductB2(RunMovement)  - ���������� ������-�������, ����������� ��������������� ���������� ��������, 
// � ����� ��������� ��������� Abstract Product
// ���
class RunMovement : public Movement
{
public:
	void Move()override
	{
		cout << "We are running\n";
	}
};

/* 
AbstractFactory(HeroFactory) - ��������� ��������� ��� ��������, ��������� ����������� �������-��������
*/

// ����� ����������� �������
class HeroFactory abstract
{
public:
	virtual Movement* CreateMovement() abstract;
	virtual  Weapon* CreateWeapon() abstract;
};

/* 
ConcreteFactory1(ElfFactory) - ��������� ��������, ��������� ���������� �������-��������
 */
// ������� �������� �������� ����� � ���������
class ElfFactory : public HeroFactory
{
public:
	Movement* CreateMovement() override
	{
		return new FlyMovement();
	}
	Weapon* CreateWeapon() override
	{
		return new Arbalet();
	}
};

class WizardFactory : public HeroFactory
{
public:
	Movement* CreateMovement() override
	{
		return new MagicMovement();
	}
	Weapon* CreateWeapon() override
	{
		return new Stick();
	}
};

/* ConcreteFactory2(WarriorFactory) - ��������� ��������, ��������� ���������� �������-��������
 */
// ������� �������� �������� ����� � �����
class WarriorFactory : public HeroFactory
{
public:
	Movement* CreateMovement() override
	{
		return new RunMovement();
	}
	Weapon* CreateWeapon() override
	{
		return new Sword();
	}
};

// C������ �� ������ �������� �� ����, ��� ���������, ����������� � �������������� �������� � ��� �������
// ������ - ��� ����������
class Hero
{
	Weapon* weapon;
	Movement* movement;
public:
	Hero(HeroFactory* factory)
	{
		weapon = factory->CreateWeapon();
		movement = factory->CreateMovement();
	}
	void Run()
	{
		movement->Move();
	}
	void Hit()
	{
		weapon->Hit();
	}
};

void main()
{
	HeroFactory* factory = new ElfFactory();
	Hero *hero = new Hero(factory);
	hero->Hit();
	hero->Run();
	delete factory;
	delete hero;

	factory = new WarriorFactory();
	hero = new Hero(factory);
	hero->Hit();
	hero->Run();
	delete factory;
	delete hero;

	factory = new WizardFactory(); 
	hero = new Hero(factory);
	hero->Hit();
	hero->Run();
	delete factory;
	delete hero;

	system("pause");
}
