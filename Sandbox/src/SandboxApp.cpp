#include <Magnets.h>

class Sandbox : public Magnets::Application{
public:
	Sandbox() {
	
	}
	~Sandbox() {

	}
};

Magnets::Application* Magnets::CreateApplication() {
	return new Sandbox;
}
