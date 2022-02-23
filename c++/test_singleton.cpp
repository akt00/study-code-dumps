#ifndef TEST_SINGLETON
#defin TEST_SINGLETON

class Singleton {
private:
	static Singleton* instance;
	int data;
  // private constructor. prohibits instanciation
	Singleton() {
		data = 0;
	}
public:
	static Singleton* getInstance() {
		if (instance == nullptr) {
			instance = new Singleton();
			std::cout << "initialized at " << instance << std::endl;
		}
		return instance;
	}

	~Singleton() {
		std::cout << "destructor called\n";
	}

	int getData() {
		return data;
	}

	void setData(int val) {
		data = val;
	}

	void deleteInstance() {
		std::cout << "instance deleted\n";
		delete instance;
		instance = nullptr;
	}
};

Singleton* Singleton::instance = nullptr; // should be initialized in a tranlation unit

void test_singleton() {
	auto instance = Singleton::getInstance();
	std::cout << instance << std::endl;
	std::cout << typeid(instance).name() << std::endl;
  // deletes the instance, however not initialized with nullptr
	delete instance;
	// instance->deleteInstance();
	auto i2 = Singleton::getInstance();
	std::cout << &instance << std::endl;
}

#endif
