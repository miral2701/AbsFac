#include <iostream>
using namespace std;

/*
Абстрактная фабрика - порождающий паттерн проектирования,
который предоставляет интерфейс для создания семейств взаимосвязанных или взаимозависимых объектов,
не специфицируя их конкретных классов.

Применимость
- система не должна зависеть от того, как создаются, компонуются и представляются входящие в нее объекты;
- входящие в семейство взаимосвязанные объекты должны использоваться вместе и необходимо обеспечить выполнение этого ограничения;
- система должна конфигурироваться одним из семейств составляющих ее объектов;
- необходимо предоставить библиотеку объектов, раскрывая только их интерфейсы, но не реализацию.

Паттерн абстрактная фабрика обладает следующими плюсами и минусами:
 * изолирует конкретные классы.
 * упрощает замену семейств продуктов.
 * гарантирует сочетаемость продуктов.
 * поддержать новый вид продуктов трудно.
*/

// AbstractProductA(Weapon) - объявляет интерфейс(абстрактный класс) для типа объекта-продукта
// абстрактный класс - оружие
class Weapon abstract
{
public:
	 virtual void Hit() abstract;
};

// ConcreteProductA1(Arbalet)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
// класс арбалет
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
// ConcreteProductA2(Sword)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
// класс меч
class Sword : public Weapon
{
public:
	void Hit() override
	{
		cout << "We are beating with the sword\n";
	}
};

// AbstractProductB(Movement) - объявляет интерфейс(абстрактный класс) для типа объекта-продукта
// абстрактный класс движение
class Movement abstract
{
public:
	virtual void Move() abstract;
};

// ConcreteProductB1(FlyMovement)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
// полет
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
// ConcreteProductB2(RunMovement)  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой, 
// а также реализует интерфейс Abstract Product
// бег
class RunMovement : public Movement
{
public:
	void Move()override
	{
		cout << "We are running\n";
	}
};

/* 
AbstractFactory(HeroFactory) - объявляет интерфейс для операций, создающих абстрактные объекты-продукты
*/

// класс абстрактной фабрики
class HeroFactory abstract
{
public:
	virtual Movement* CreateMovement() abstract;
	virtual  Weapon* CreateWeapon() abstract;
};

/* 
ConcreteFactory1(ElfFactory) - реализует операции, создающие конкретные объекты-продукты
 */
// Фабрика создания летящего героя с арбалетом
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

/* ConcreteFactory2(WarriorFactory) - реализует операции, создающие конкретные объекты-продукты
 */
// Фабрика создания бегущего героя с мечом
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

// Cистема не должна зависеть от того, как создаются, компонуются и представляются входящие в нее объекты
// клиент - сам супергерой
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
