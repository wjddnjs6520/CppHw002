#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 기본 클래스: Animal
class Animal {
public:
    //순수 가상함수는 대입 0으로 생성
    virtual void makeSound() = 0;
    //소멸자 가상함수 선언
    virtual ~Animal() {}

};

// 파생 클래스: Dog
class Dog : public Animal {
    void makeSound() {
        cout << "Dog make Sound: Wolf! Wolf!" << endl;
    }
};

// 파생 클래스: Cat
class Cat : public Animal {
    void makeSound() {
        cout << "Cat make Sound: Mew~! Mew~!" << endl;
    }
};
// 파생 클래스: Cow
class Cow : public Animal {
    void makeSound() {
        cout << "Dog make Sound: Om~~~~mo! Om~~~~mo!" << endl;
    }
};

class Zoo {
private:
    Animal* animals[10] = {nullptr}; // 동물 객체를 저장하는 포인터 배열
public:
    // 동물을 동물원에 추가하는 함수
    // - Animal 객체의 포인터를 받아 포인터 배열에 저장합니다.
    // - 같은 동물이라도 여러 번 추가될 수 있습니다.
    // - 입력 매개변수: Animal* (추가할 동물 객체)
    // - 반환값: 없음
    void addAnimal(Animal* animal) {
        if (animals[9] != nullptr) {
            cout << "Zoo is already full!" << endl;
        }
        else {
            for (int i = 0; i < 10; i++) {
                if (animals[i] == nullptr) {
                    animals[i] = animal;
                    break;
                }
            }
        }
    }

    // 동물원에 있는 모든 동물의 행동을 수행하는 함수
    // - 모든 동물 객체에 대해 순차적으로 소리를 내고 움직이는 동작을 실행합니다.
    // - 입력 매개변수: 없음
    // - 반환값: 없음
    void performActions() {
        for (int i = 0; i < 10; i++) {
            if (animals[i] == nullptr) {
                break;
            }
            animals[i]->makeSound();
        }
    }

    // Zoo 소멸자
    // - Zoo 객체가 소멸될 때, 동물 벡터에 저장된 모든 동물 객체의 메모리를 해제합니다.
    // - 메모리 누수를 방지하기 위해 동적 할당된 Animal 객체를 `delete` 합니다.
    // - 입력 매개변수: 없음
    // - 반환값: 없음
    ~Zoo() {
        //메모리 해제
        for (int i = 0; i < 10 ; i++) {
            if (animals[i] == nullptr) {
                break;
            }
            delete animals[i];
        }
    }
};



// 랜덤 동물을 생성하는 함수
// - 0, 1, 2 중 하나의 난수를 생성하여 각각 Dog, Cat, Cow 객체 중 하나를 동적으로 생성합니다.
// - 생성된 객체는 Animal 타입의 포인터로 반환됩니다.
// - 입력 매개변수: 없음
// - 반환값: Animal* (생성된 동물 객체의 포인터)
Animal* createRandomAnimal() {
    int randomNumber = rand() % 3;  // 0 ~ 2 사이 난수

    switch (randomNumber)
    {
    case 0:
        return new Dog();
        break;
    case 1:
        return new Cat();
        break;
    case 2:
        return new Cow();
        break;
    default:
        break;
    }
}


int main() {
    //Zoo
    Zoo* myZoo = new Zoo();


    for (int i = 0; i < 10; i++) {
        myZoo->addAnimal(createRandomAnimal());
    }

    myZoo->performActions();

    myZoo->addAnimal(new Dog());
    delete myZoo;

    return 0;
}

